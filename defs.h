#include <stdio.h>
#include <stdlib.h>

#define regget(x) (regis[x])
#define regput(x,y) (regget(x) = (y))
#define memget(x) (memory[x])
#define memput(x,y) (memory[x] = (y))
#define setflag(x) (flags=((flags & ~(x)) | (x)))
#define clrflag(x) (flags=((flags & ~(x)) | 0))
#define notflag(x) (flags=((flags & ~(x)) | (~flags & (x))))
#define ifset(x,y) ((x) ? setflag(y) : clrflag(y))
#define chkflag(x) ((flags & (x)) > 0)

#define FLG_C 0x01
#define FLG_S 0x02
#define FLG_Z 0x04
#define MAXMEM 0x10000
#define MAXREG 0x08


enum ctrls {
	ALU_STO,
	ALU_LOD,
	ALU_ADD,
	ALU_ADC,
	ALU_SUB,
	ALU_CMC,
	ALU_STC,
	ALU_SBB,
	ALU_AND,
	ALU_XOR,
	ALU_OR,
	ALU_CMP,
	ALU_RLC,
	ALU_RRC,
	ALU_RAL,
	ALU_RAR,
};

typedef unsigned char byte_t;
typedef unsigned short int word_t;
typedef int ctrl_t;

extern byte_t memory[MAXMEM];
extern byte_t regis[MAXREG];
extern byte_t flags;
byte_t alu(ctrl_t op, byte_t data);
