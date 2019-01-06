# Puppies Tower

A play tower suitable for 15 cm plush puppies.

This repository contains a rough documentation of a fun project. It consists of:

* a tower with a look-out
  * simple elevator
  * electronics with [source code](esp8622/tower.ino)

## Context

We already owned almost every plush puppy from a TV series, but the available play tower only fits with smaller figures. Therefore, I built a bigger version of it.

## Build Steps

:warning: This is no step by step guide and in the end, it was quite hard to build.

### Floor and Roof of the Look-Out
![a chipboard with drawn circles on it][chrono1]

### Miscellaneous Elements
![a chipboard with every other needed element drawn on it][chrono2]

### Cut-Out Elements

The paint on the 90° tube did not hold and it will be replaced by a yellow cup later (see [Lessons Learned](#lessons-learned)).

![cut-out elements from the chipboard][chrono3]

### Roughened Surface with Sandpaper
![cut-out elements roughened with sandpaper][chrono4]

### Applied Primer

The chipboard's surface curls (maybe too much primer) were cut and glued again later.

![elements that are painted with primer][chrono5]

### Colored Elements
![primed elements are now colored][chrono6]

### Electronic Part

Almost every powerbank seems to not switch on again after sleep mode. The reboot also leads to a short but annoying flashing of the internal LED. Therefore, the powerbank is left outside the box on the roof, so it can be easily plugged out. It has also been replaced by a device that has a power switch.

![electronical part in the head of the look-out][chrono7]

### Finished Tower
![finished tower][chrono8]

## Lessons Learned

- The painting of PVC parts became an issue when using lacquers/acrylic paint suitable for children
  - Make some tests first
  - Check the instructions of the paint cans for their minimal processing temperature
- Glue did not help. In the end, many parts have been bolted together
- I only had white wire at hand, which got complicated
  - Use multiple colors
  - Mark the wires
- Get a long USB cable to upload code to the already installed [NodeMCU](http://www.nodemcu.com)


[chrono1]: assets/01-chipboard-look-out.jpg "The floor and roof of the look-out."
[chrono2]: assets/02-chipboard-misc.jpg "Every other needed element of the tower."
[chrono3]: assets/03-chipboard-cut.jpg "Elements were cut-out."
[chrono4]: assets/04-sandpaper.jpg "Elements were roughened with sandpaper."
[chrono5]: assets/05-primer.jpg "Primed elements."
[chrono6]: assets/06-color.jpg "Colored elements."
[chrono7]: assets/07-electronics.jpg "The electronical part of the tower."
[chrono8]: assets/08-finished.jpg "The finished tower."
