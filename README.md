# 8051 MCU board

These are the Kicad design files for the 8051 controller board used in my [8051 tuner](https://hackaday.io/project/162267-8051-tuner) project published at Hackaday.

## Don't build this board

What? Did I just read that?

Yes. This board is obsolete. If you want to experiment with the MCS-51 family you can get the same functionality with the Atmel 89C2051, avoiding an (E)EPROM, and the 74LS373. The 89C2051 has EEPROM, can clock twice as fast, 24 MHz, and will draw less current. Since you get the same port pins (a quibble, you lose one pin, P3.6) as this design, what's not to like about that? What's more the 89C2051 is only a dollar or so whereas the original 40-pin 8051/8031 is out of production and any chips you see advertised are for exact replacements and priced accordingly.

If you need more program memory or ports, there are the Atmel 89S51 and 89S52 with 4 or 8 kB EEPROM, 32 port pins and even higher clock. As the program memory is internal again you don't need the (E)EPROM and latch. Another possibility is the STC89C52 which is a bit cheaper and has serial bootloading. These appear to be pin compatible with the original 8051 but with more internal resources.

The only reasons I designed this board were to make use of the 8051/8031 chips that I already have, and to practice Kicad/eeschema. Since I'd already drawn the circuit I thought I might as well publish it, as a reference design.

Also included is a sample blink program written for compilation with SDCC.

## Versioning

First release November 2018

## Authors

* **Ken Yap**

## License

See the [LICENSE](LICENSE.md) file for license rights and limitations (MIT).
