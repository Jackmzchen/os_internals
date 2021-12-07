	.file	"firstc.c"
	.text
	.globl	i
	.data
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	12345
	.globl	y
	.align 8
	.type	y, @object
	.size	y, 8
y:
	.long	-57724360
	.long	1072939201
	.section	.rodata
.LC1:
	.string	"i=%d, y=%f\n"
	.text
	.globl	display_variables
	.type	display_variables, @function
display_variables:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movl	i(%rip), %eax
	movq	-8(%rbp), %rdx
	movq	%rdx, %xmm0
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	display_variables, .-display_variables
	.section	.rodata
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	y(%rip), %rdx
	movl	i(%rip), %eax
	movq	%rdx, %xmm0
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	call	display_variables
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	movl	$0, %eax
	call	fib
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
	addl	$1, -4(%rbp)
.L3:
	cmpl	$10, -4(%rbp)
	jle	.L4
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.globl	fib
	.type	fib, @function
fib:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L7
	movl	$0, %eax
	jmp	.L8
.L7:
	cmpl	$1, -20(%rbp)
	jne	.L9
	movl	$1, %eax
	jmp	.L8
.L9:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fib
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fib
	addl	%ebx, %eax
.L8:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	fib, .-fib
	.section	.rodata
	.align 8
.LC0:
	.long	-1340029796
	.long	1074882674
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
