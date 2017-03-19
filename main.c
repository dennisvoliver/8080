
#include "defs.h"

byte_t memory[MAXMEM];
byte_t regis[MAXREG];
byte_t flags = 0;

int main(void)
{


	test6();

}


int test6(void)
{
	byte_t a = 0x80;
	setflag(FLG_C);
	alu(ALU_LOD, a);
	alu(ALU_RAL, 0);
	printf("a = %x\n", alu(ALU_STO, 0));
	printf("carry: %x sign: %x zero: %x\n",
	chkflag(FLG_C), chkflag(FLG_S), chkflag(FLG_Z));
}
int test5(void)
{
	byte_t a = 0x80;
	byte_t b = 0x80;
	alu(ALU_LOD, a);
	alu(ALU_CMP, b);
	printf("carry: %x sign: %x zero: %x\n",
	chkflag(FLG_C), chkflag(FLG_S), chkflag(FLG_Z));
}

int test4(void)
{
	byte_t a = 0x38;
	byte_t b = 0x21;
	alu(ALU_LOD, a);
	alu(ALU_OR, b);
	printf("%x\n", alu(ALU_STO, 0));
}
int test1(void)
{

	byte_t minh, minl, subh, subl;
	word_t min = 0xff03;
	word_t sub = 0xfdff;

	minh = (min & 0xff00) / 0x100;
	minl = min & 0x00ff;
	subh = (sub & 0xff00) / 0x100;
	subl = sub & 0x00ff;
	word_t diff;
	alu(ALU_LOD, minl);
	diff = alu(ALU_SUB, subl);
	alu(ALU_LOD, minh);
	diff += (alu(ALU_SBB, subh) * 0x100);
	printf("%x - %x = %x\n", min, sub, diff);
	printf("minh: %x minl %x subh %x subl %x\n", 
	minh, minl, subh, subl);
}
int test2(void)
{

	printf("flags :%x\n", flags);
	printf("ifset(true) %x\n", ifset(1, FLG_C));
	printf("ifset(false) %x\n", ifset(0, FLG_C));
}

int test3(void)
{
	byte_t minh, minl, subh, subl;
	word_t min = 0xedff;
	word_t sub = 0xba04;

	minh = (min & 0xff00) / 0x100;
	minl = min & 0x00ff;
	subh = (sub & 0xff00) / 0x100;
	subl = sub & 0x00ff;
	word_t diff;
	alu(ALU_LOD, minl);
	diff = alu(ALU_ADD, subl);
	alu(ALU_LOD, minh);
	diff += (alu(ALU_ADC, subh) * 0x100);
	printf("%x + %x = %x\n", min, sub, diff);
	printf("minh: %x minl %x subh %x subl %x\n", 
	minh, minl, subh, subl);
}
