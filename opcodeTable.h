typedef union {
    unsigned char* sizeChar;
    unsigned short* sizeShort;
} uPointerType;

extern enum {
    eNoOperands,
    eOperandChar,
    eOperandShort,
    eOperandMemAddr
} operandType;

struct opcodeDefs {      
    enum {
        eDestNone,
        eDestChar,
        eDestShort
    } destType;

    enum {
        eSrcNone,
        eSrcChar,
        eSrcShort
    } srcType;

    uPointerType destPtr;
    uPointerType srcPtr;

    enum {
        flagNotSet,
        flagSet,
        noCondition
    } condition;
};

struct opcode {
    char* name;
    struct opcodeDefs defs;
    unsigned char operand;
    void *function;
} extern const baseOpcodeTable[256], CBOpcodeTable[256];

