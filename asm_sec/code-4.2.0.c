.data
hello:
	.string "hello world\n"
	length = . - $hello

.global main
main:
	movl	4,%eax
	movl	1,%ebx
	movl	$hello,%ecx
	movl	$length,%edx
	int	$0x80

	movl	1,%eax
	xorl	%ebx,%ebx
	int	$0x80
	