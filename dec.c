#include "defs.h"
int main(void)
{


}


void decode(byte_t inst)
{
	if ((inst & MSK_CLASS) == CL_ACU)
		dec_acu(inst);
}


void dec_acu(byte_t inst)
{
	byte_t reg = (inst & MSK_REG);
	byte_t op = ((inst & MSK_DST) >> 3);
	switch(op) {
	case OP_ADD :
		regput(REG_A, alu(ALU_ADD, regget(reg)));
		break;
		default :
			break;
	}
}
