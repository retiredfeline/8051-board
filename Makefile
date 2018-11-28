#
# By default SDCC generates for the small model which is what we want
# RAM is internal, ROM is from 0 to 2kB
#

CC=sdcc
CFLAGS=-mmcs51

default:	blink.ibn

%.asm:		%.c
		$(CC) $(CFLAGS) -S $<

%.ihx:		%.c
		$(CC) $(CFLAGS) $<

%.ibn:		%.ihx
		hex2bin -e ibn $<

clean:
		rm -f blink.{asm,sym,lst,rel,rst,sym,lk,map,mem,ihx,ibn}
