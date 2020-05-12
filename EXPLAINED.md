```
0 - input
1 - output
```
## Examples
### Declare ports INPUT/OUTPUT
```C
DDRB = 0b10000000   #DECIMAL: 128, HEX: 0x80
DDRB = 0x80         #DECIMAL: 128, BINARY: 0b10000000
 ```

### Make high/low
```C
PORTB |= (1 << 7)  #MAKE HIGH
PORTB = 0b10000000 #MAKE HIGH

PORTB &= ~(1 << 6) #MAKE LOW
PORTB = 0b01000000 #MAKE LOW
```

### Read digital is high or low
```C
PINB & (1 << 7)    #IS HIGH
!(PINB & (1 << 7)) #IS LOW
```

### ATmega2560 board PIN mapping
```
PIN |PORT|NO|BITS
  2 | E  | 4|  16
  3 | E  | 5|  32
  4 | G  | 5|  32
  5 | E  | 3|   8

  6 | H  | 3|   8
  7 | H  | 4|  16
  8 | H  | 5|  32
  9 | H  | 6|  64

 10 | B  | 4|  16
 11 | B  | 5|  32
 12 | B  | 6|  64
 13 | B  | 7| 128
 ```

### Arithmetic examples
```C
# make high 11 and 12 PIN
PORTB |= (1 << 4) //32 bit
PORTB |= (1 << 5) //64 bit
# 32 bit + 64 bit = 96 bit //PORTB = 96
```

### Bitwise
```C
int num1 = 8;  			//00001000
int num2 = 24; 			//00011000
int num3 = num1 & num2; //00001000
int num4 = num1 | num2; //00011000
int num5 = ~ num1;      //11110111 (BITWISE NOT)
int num6 = num4 << 2    //11000000 (BITWISE LEFT SHIFT)
```

### Avr lib defines
```C
#define _SFR_IO8(io_addr) ((io_addr) + __SFR_OFFSET)
#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)
#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))

#define PORTA   _SFR_IO8(0X02)
#define PORTB   _SFR_IO8(0x05)
#define PORTC   _SFR_IO8(0x08)
#define PORTD   _SFR_IO8(0x0B)
#define PORTE   _SFR_IO8(0x0E)
#define PORTF   _SFR_IO8(0x11)
#define PORTG   _SFR_IO8(0x14)
#define PORTH   _SFR_IO8(0x17)

#define DDRA    _SFR_IO8(0X01)
#define DDRB    _SFR_IO8(0x04)
#define DDRC    _SFR_IO8(0x07)
#define DDRD    _SFR_IO8(0x0A)
#define DDRE    _SFR_IO8(0x0D)
#define DDRF    _SFR_IO8(0x10)
#define DDRG    _SFR_IO8(0x13)

#When touch show other value
#define PINA    _SFR_IO8(0X00)
#define PINB    _SFR_IO8(0X03)
#define PINC    _SFR_IO8(0x06)
#define PIND    _SFR_IO8(0x09)
#define PINE    _SFR_IO8(0x0C)
#define PINF    _SFR_IO8(0x0F)
#define PING    _SFR_IO8(0x12)

#PINA > DDRA > PORTA
#PINB > DDRB > PORTB

#define PB7 7 //from PA0 TO PG7 defines
```