[hexgen2014 world generator](http://www.heroextant.net/hexgen2014/)
============================

**THIS IS NEARLY FINISHED; EXPECT A RELEASE ~~BEFORE JULY 2014~~ SOON**

This is a program for creating nice looking images of a world map and simulating weather. Maps are randomly generated using entirely procedural methods.

**TODO SCREENSHOT**

In 2010, the [Hero Extant World Generator prototype](http://www.tophatstuff.co.uk/archive.php?p=99) was released with a GUI for Windows. The world-generator backend has now been updated and converted into a command-line tool, *hexgen2014*, by the original author. Several improvements have been made. The tool is written in C and available as free & open source software for Windows and Linux.

It is hoped that you will find this program useful as a standalone tool for your own projects. Alternatively you may like to use the world generator source code in your own programs.

Updated versions of this software can always be found at the [website](http://www.heroextant.net/hexgen2014/) or on [GitHub](https://github.com/golightlyb/hexgen2014). Bug reports and feedback can be sent to hexgen2014@heroextant.net. Thanks!


Contents
--------
[New Features](#new-features)  
[Screenshots](#screenshots)  
[Download a Binary Package](#download)  
[Compile from Source](#compile)  
[Additional Ports](#ports)  
[Free Software License](#copying)  

<a name="new-features" />
New Features
------------

Improving over all previous releases:

**Advanced weather simulation!** Atmosphere, wind and weather are simulated in incredible detail. Weather changes over time.

**Seasons!** Seasonal variation over the same map is now supported by varying axial tilt. This is then automatically factored into the new weather simulation.

**Improved terrain generation:** Terrain is generated using a new simplex noise method, replacing the old midpoint displacement algorithm. This gives greater flexibility in the shape of map and generates higher quality terrains, avoiding artifacts such as diamond shaped mountains or square shaped peninsulas.

**Custom terrain shape masks:** Generating maps in specific shapes is now possible using preset shapes or by loading a custom image as a mask.

**More customisable than ever before:** Do you want to simulate 12 months of sunlight patterns over a small island in the North? Or would you rather simulate a pattern of dry and monsoon seasons over a world-spanning continent baked in the glow of a giant sun? What about a garden world where a low axial tilt means mild seasons? Your imagination can go wild.

**LaTeX/PDF output:** Automatically generate a fancy PDF document of your world and its features using `pdflatex`. Alternatively use the generated LaTeX files as the basis for your own worldbuilding document.


<a name="screenshots" />
Screenshots
------------

| Screenshot    | Description   |
|---------------|---------------|
| [![Heightmap generation](http://www.heroextant.net/hexgen2014/screenshots/2014/april/elevation-quick-320.png)](http://www.heroextant.net/hexgen2014/screenshots/2014/april/elevation-quick.png) | This is a colourised version of a raw heightmap generated by the program. |
| [![Atmosphere](http://www.heroextant.net/hexgen2014/screenshots/2014/april/22-atmosphere1Dgraph-320x213.png)](http://www.heroextant.net/hexgen2014/screenshots/2014/april/22-atmosphere1Dgraph-1200x800.png) | Graph generated by the program showing air pressure and density by altitude. |
| [![Sunlight model](http://www.heroextant.net/hexgen2014/screenshots/2014/april/sunlight-animation.gif)](http://www.heroextant.net/hexgen2014/screenshots/2014/april/sunlight-animation-thumb.gif) | (Animated GIF) Seasonal model of direct sunlight based on latitude, axial tilt and completion of orbit. This image shows a large area over the equator. Sticking to only one hemisphere is fun too. You can control the planet's axial tilt for milder (or harsher!) seasons. |



<a name="download" />
Download a Binary Package
-------------------------

The following compiled versions of hexgen2014 are available:

* hexgen2014-linux32 (for 32-bit Linux)
* hexgen2014-linux64 (for 64-bit Linux)
* hexgen2014-win32 (for 32-bit Windows)
* hexgen2014-win64 (for 64-bit Windows)

For convenience, all versions are made available in one package containing
source code and documentation.

Packages are available to download from the following locations:

* http://www.heroextant.net/hexgen2014/pub/



<a name="compile" />
Compile from Source
-------------------

Consult the documentation for more detailed information.

The given build process was designed for 64-bit Debian (stable); users of other systems
may want to follow the instructions in the documentation instead.

Requires:
[tup](http://gittup.org/tup/),
gcc,
clang

Optional:
[debian Multiarch](https://wiki.debian.org/Multiarch/HOWTO),
[gcc-mingw-w64](https://packages.debian.org/wheezy/gcc-mingw-w64),
[wine64](http://wiki.winehq.org/Wine64),
[fabric](http://www.fabfile.org/)


    git clone https://github.com/golightlyb/hexgen2014
    cd hexgen2014
    nano tup.config # turn target platforms on/off
    tup init
    tup upd

If you make changes after this point, simply run `tup upd` to update the build.


<a name="ports" />
Additional Ports
----------------

* [Original Cobra version of the Hero Extant 2010 World Generator Prototype](http://www.tophatstuff.co.uk/archive.php?p=99)  
Comes with a graphical user interface. The compiler for this version is no longer published, so you cannot modify the software unfortunately.

* [Java port of the Hero Extant 2010 World Generator](https://github.com/avh4/hero-extant)  
This is a Java version of the world generator backend suitable for including in Java projects.

* [TT Tile Tools](http://www.deamonsouls.de/TT/)  
This program uses the Java port of Hero Extant 2010 World Generator as one of the ways to generate map images.


<a name="copying" />
Free Software License
---------------------

 This is Free and Open Source Software. This means that you are allowed to
 share and modify the software at no cost, subject to the below agreement.

    hexgen2014 world generator
    
    Copyright (c) 2010, 2014 Ben Golightly <golightly.ben@googlemail.com>
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

Simply, you can use this software however you like. However, you must include
a copy of the license and copyright notice if you share it with other people.

If you have questions about what this license means, [this is my interpretation](http://www.tophatstuff.co.uk/archive.php?p=40). Alternatively please e-mail me at the given address.

You can use any images/data that you generate with this program without restriction ([for this reason](http://www.gnu.org/licenses/gpl-faq.html#WhatCaseIsOutputGPL)).

