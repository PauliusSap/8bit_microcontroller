### Some learning stuff. C programming AVR-8 bit microcontroller @2017

### Compile and upload to EEPROM
```bash
#!/bin/bash
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c -o $1.o $1.c
avr-gcc -mmcu=atmega2560 $1.o -o $1
avr-objcopy -O ihex -R .eeprom $1 $1.hex
avrdude -D -p m2560 -c stk600 -P /dev/$2 -U flash:w:$1.hex:i

#/sbin/getty 57600 ttyACM0

#sleep
rm $1.hex
rm $1.o
rm $1
```

### avr-gcc parameters:
```-c``` - compile and assemble, but do not link

### avrdude parameters:
```-U``` memtype:op:filename[:format]
```memtype(flash, fuse, hfuse, lfuse, lock)```

```:op```
(r-read device memory and write to specific file)
(w-read data from specific the file and write to the device memory)

```:format```
(i-Intel hex, e-ELF, a-Auto detect, b-binary each value prepended 0b, h-hexadecimal eac value prepended 0x)