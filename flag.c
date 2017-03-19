#include <stdio.h>
/* flag manipulation lab */

#define setflag(x) flags=((flags & ~(x)) | (x))
#define clrflag(x) flags=((flags & ~(x)) | 0)
#define notflag(x) flags=((flags & ~(x)) | (~flags & (x)))
#define ifset(x,y) ((x) ? setflag(y) : clrflag(y))
static char flags = 0xd5;
int main(void)
{
	printf("before: %x\n", flags);
	clrflag(0x38);
	printf("%x\n", flags);

}
