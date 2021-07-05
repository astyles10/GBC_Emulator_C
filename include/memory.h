/*
    Memory Map
*/
#define ROM_BANK_ZERO           0x0000 
#define ROM_BANK_SWITCHABLE     0x4000
#define RAM_VIDEO               0x8000
#define RAM_SWITCHABLE          0xA000
#define RAM_INTERNAL_8KB        0xC000
#define RAM_INTERNAL_8KB_ECHO   0xE000
#define SPRITE_ATTR_MEM         0xFE00
#define EMPTY_REGION_1          0xFEA0
#define IO_PORTS                0xFF00
#define EMPTY_REGION_2          0xFF4C
#define RAM_INTERNAL            0xFF80
#define INTERRUPT_ENR           0xFFFF

struct MemoryMap {
    unsigned char ROMBankZero[ROM_BANK_SWITCHABLE - ROM_BANK_ZERO];
    unsigned char ROMBankSwitchable[RAM_VIDEO - ROM_BANK_SWITCHABLE];
    unsigned char RAMVideo[RAM_SWITCHABLE - RAM_VIDEO];
    unsigned char RAMSwitchable[RAM_INTERNAL_8KB - RAM_SWITCHABLE];
    unsigned char RAMInternal8KB[RAM_INTERNAL_8KB_ECHO - RAM_INTERNAL_8KB];
    unsigned char RAMInternal8KBEcho[SPRITE_ATTR_MEM - RAM_INTERNAL_8KB_ECHO];
    unsigned char spriteAttributeMemory[EMPTY_REGION_1 - SPRITE_ATTR_MEM];
    unsigned char emptyRegion1[IO_PORTS - EMPTY_REGION_1];
    unsigned char ioPorts[EMPTY_REGION_2 - IO_PORTS];
    unsigned char emptyRegion2[IO_PORTS - EMPTY_REGION_1];
    unsigned char RAMInternal[INTERRUPT_ENR - RAM_INTERNAL];
    unsigned char interruptEnable;
} extern memoryMap;

// Begin Reserved Memory Locations

/* 
    Restart Addresses
 */

#define RST_0x00 0x00
#define RST_0x08 0x08
#define RST_0x10 0x10
#define RST_0x18 0x18
#define RST_0x20 0x20
#define RST_0x28 0x28
#define RST_0x30 0x30
#define RST_0x38 0x38

/* 
    Interrupt Addresses
 */

#define VERT_BLNK_INTR_START        0x40
#define LCDC_STATUS_INTR_START      0x48
#define TIMER_OVERFLOW_INTR         0x50
#define SERIAL_TX_COMPLETION_INTR   0x58
#define HIGH_LOW_P10_P13_INTR       0x60

extern unsigned char tempMemCart[0xFFFF];

void initializeMemory(void);

unsigned char readByteFromMemory(unsigned short* memAddr);
unsigned short readShortFromMemory(unsigned short* memAddr);
void writeByteToMemory(const unsigned short* memAddr, const unsigned char* value);
void writeShortToMemory(unsigned short* memAddr, unsigned short* value);
unsigned char* getPointerToMemory(unsigned short* memAddr);