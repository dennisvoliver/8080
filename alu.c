
#include "defs.h"



byte_t alu(ctrl_t op, byte_t data)
{
	static word_t accu = 0;
	switch (op) {
	case ALU_STO:
		/* get value of accuumulator */
		break;
	case ALU_LOD:
		/* put data to accuumulator */
		accu = data;
		break;
	case ALU_ADC:
		/* add with carry */
		data += (chkflag(FLG_C));
		/* fall through */
	case ALU_ADD:
		accu += data;
		/* overflow */
		ifset(accu & 0xff00, FLG_C);
		ifset(accu & 0x0080, FLG_S);
		ifset(!accu, FLG_Z);
		break;
	case ALU_SBB:
		/* subtraction with borrow */
		data += (chkflag(FLG_C));
		/* fall through, do not add a break */
	case ALU_SUB:
		/* add two's complement */
		accu += ((~data + 1) & 0xff);
		/* underflow */
		ifset(!(accu & 0xff00), FLG_C);
		ifset(accu & 0x0080, FLG_S);
		ifset(!(accu & 0xff), FLG_Z);
		break;
	case ALU_AND:
		accu &= data;
		clrflag(FLG_C);
		ifset(accu & 0x0080, FLG_S);
		ifset(!accu, FLG_Z);
		break;
	case ALU_XOR:
		accu ^= data;
		clrflag(FLG_C);
		ifset(accu & 0x0080, FLG_S);
		ifset(!accu, FLG_Z);
		break;
	case ALU_OR:
		accu |= data;
		clrflag(FLG_C);
		ifset(accu & 0x0080, FLG_S);
		ifset(!accu, FLG_Z);
		break;
	case ALU_CMP:
		{
		auto word_t tmp;
		tmp = accu;
		/* add two's complement */
		tmp += ((~data + 1) & 0xff);
		printf("debug: %x\n", tmp);
		/* underflow */
		ifset(!(tmp & 0xff00), FLG_C);
		ifset(tmp & 0x0080, FLG_S);
		ifset(!(tmp & 0xff), FLG_Z);
		}
		break;
	case ALU_RLC:
		/* rotate left, touch carry */
		accu = (accu << 1) + ((accu & 0x80) > 0);
		ifset((accu & 0x80) > 0, FLG_C);
		break;
	case ALU_RRC:
		/* rotate right, touch carry */
		accu = (accu >> 1) | ((accu << 7) & 0xff);
		ifset((accu & 0x80) > 0, FLG_C);
		break;
	case ALU_RAL:
		/* rotate left _through_ carry */
		accu = (accu << 1) + chkflag(FLG_C);
		ifset((accu & 0x0100), FLG_C);
		break;
	case ALU_RAR:
		/* inverse of above */
		accu |= (chkflag(FLG_C) << 8);
		ifset(accu & 0x01, FLG_C);
		accu >>= 1;
		break;
	default:
		fprintf(stderr, "crashed and burned\n");
		exit(-1);
		break;
	}


	accu &= 0xff;
	return accu;
}
