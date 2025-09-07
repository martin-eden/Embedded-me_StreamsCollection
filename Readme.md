## What

(2025-08)

Stream adapters for base modules.

First I wrote (and writing) base modules. Currently it's UART,
RAM, Flash and EEPROM. Then I've added stream interface to
write common functions. And now I do not want to modify each
base module to support streams.

So I'm wrapping them as streams here.

This module will require all base modules. This module will grow.
This module will change. That's bad but it's isolated here.


## Code

* [Interface][Interface]
* [Example][Example]
* [Implementation][Implementation]


## Install/remove

Easy way is to clone [GetLibs][GetLibs] repo and run it's code.


## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]


[Interface]: src/me_StreamsCollection.h
[Example]: examples/me_StreamsCollection/me_StreamsCollection.ino
[Implementation]: src/Interfaces/

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
