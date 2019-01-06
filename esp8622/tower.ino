#define SWITCH_COUNTER_MAX 10
#define ACTION_MILLIS 600
#define SLEEP_MICROSECONDS 3000000
#define LOGGING_LIMIT 1000

#if defined(LOGGING_LIMIT)
  int loopCount = 0;
#endif

const int INTERNAL_LED = D4;
const int LED_RED_A = D8;
const int LED_RED_B = D7;
const int LED_RED_C = D6;
const int LED_RED_D = D5;
const int LED_FLOOR = D3;
const int BUTTON_RED = D1;
const int SWITCH_KEY = D2;

int switchCount = 0;
int sequenceRed = 0;

void setup() {
  #if defined(LOGGING_LIMIT)
    Serial.begin(115200);
    Serial.println("setup");
  #endif
  
  pinMode(INTERNAL_LED, OUTPUT);
  
  pinMode(LED_RED_A, OUTPUT);
  pinMode(LED_RED_B, OUTPUT);
  pinMode(LED_RED_C, OUTPUT);
  pinMode(LED_RED_D, OUTPUT);
  pinMode(LED_FLOOR, OUTPUT);
  pinMode(BUTTON_RED, INPUT);
  pinMode(SWITCH_KEY, INPUT);

  allLights(LOW);
}

void loop() {
  if (startSleep()) {
    return;
  }
  if (checkCancelSequenceRed()) {
    return;
  }
  if (startSequenceRed()) {
    digitalWrite(LED_FLOOR, LOW);
  } else {
    digitalWrite(LED_FLOOR, HIGH);
  }
  delay(10);
  #if defined(LOGGING_LIMIT)
    loopCount++;
  #endif
}

boolean startSleep() {
  int switchState = digitalRead(SWITCH_KEY);
  #if defined(LOGGING_LIMIT)
    if (loopCount % LOGGING_LIMIT == 0) {
      Serial.print("SWITCH_KEY: ");
      Serial.println(switchState);
    }
  #endif
  if (switchState == HIGH) {
    switchCount = SWITCH_COUNTER_MAX;
    digitalWrite(INTERNAL_LED, HIGH);
    return false;
  } else {
    switchCount -= 1;
    if (switchCount <= 0) {
      #if defined(LOGGING_LIMIT)
        Serial.println("sleep");
      #endif
      sequenceRed = 0;
      switchCount = 0;
      allLights(LOW);
      //delay(SLEEP_MICROSECONDS/1000);
      ESP.deepSleep(SLEEP_MICROSECONDS);
    }
  }
  return true;
}

boolean startSequenceRed() {
  if (sequenceRed <= 0) {
    int buttonRedState = digitalRead(BUTTON_RED);
    #if defined(LOGGING_LIMIT)
      if (loopCount % LOGGING_LIMIT == 0) {
        Serial.print("buttonRedState: ");
        Serial.println(buttonRedState);
      }
    #endif
    if (buttonRedState == HIGH) {
      sequenceRed = 1;
    } else {
      return false;
    }
  }
  #if defined(LOGGING_LIMIT)
    Serial.print("sequenceRed: ");
    Serial.println(sequenceRed);
  #endif
  switch(sequenceRed) {
    case 1:
      redBlink();
    break;
    case 2:
      redBlink();
    break;
    case 3:
      redBlink();
    break;
    case 4:
      redBlink();
    break;
    case 5:
      redBlink();
    break;
    case 6:
      redBlink();
    break;
    case 7:
      redBlink();
    break;
    case 8:
      redBlink();
    break;
    case 9:
      redBlink();
    break;
    case 10:
      redBlink();
    break;
    case 11:
      redBlink();
    break;
    case 12:
      redBlink();
    break;
    case 13:
      redBlink();
    break;
    default:
      #if defined(LOGGING_LIMIT)
        Serial.println("unexpected sequenceRed default state");
      #endif
      redLights(LOW);
    break;
  }
  if (sequenceRed < 13) {
    sequenceRed += 1;
    return true;
  } else {
    sequenceRed = 1;
  }
}

boolean checkCancelSequenceRed() {
  if (sequenceRed > 0) {
    int buttonRedState = digitalRead(BUTTON_RED);
    if (buttonRedState == HIGH) {
      delay(10);
      buttonRedState = digitalRead(BUTTON_RED);
      if (buttonRedState == HIGH) {
        stopSequenceRed();
        #if defined(LOGGING_LIMIT)
          Serial.println("sequence canceled");
        #endif
        delay(2000);
        return true;
      }
    }
  }
  return false;
}

void stopSequenceRed() {
  sequenceRed = 0;
  redLights(LOW);
}

void redBlink() {
  redLights(HIGH);
  digitalWrite(LED_FLOOR, LOW);
  delay(ACTION_MILLIS / 2);
  redLights(LOW);
  digitalWrite(LED_FLOOR, HIGH);
  delay(ACTION_MILLIS / 2);
}

void redAlternate() {
  digitalWrite(LED_RED_A, HIGH);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, HIGH);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 2);
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, HIGH);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, HIGH);
  delay(ACTION_MILLIS / 2);
}

void redRound() {
  digitalWrite(LED_RED_A, HIGH);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 4);
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, HIGH);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 4);
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, HIGH);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 4);
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, HIGH);
  delay(ACTION_MILLIS / 4);
}

void redRoundReverse() {
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, HIGH);
  delay(ACTION_MILLIS / 4);
  digitalWrite(LED_RED_A, HIGH);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 4);
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, HIGH);
  digitalWrite(LED_RED_C, LOW);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 4);
  digitalWrite(LED_RED_A, LOW);
  digitalWrite(LED_RED_B, LOW);
  digitalWrite(LED_RED_C, HIGH);
  digitalWrite(LED_RED_D, LOW);
  delay(ACTION_MILLIS / 4);
}

void redLights(uint8_t state) {
  digitalWrite(LED_RED_A, state);
  digitalWrite(LED_RED_B, state);
  digitalWrite(LED_RED_C, state);
  digitalWrite(LED_RED_D, state);
}

void allLights(uint8_t state) {
  redLights(state);
  digitalWrite(LED_FLOOR, state);
}
