	.file	"main.c"
	.text
	.globl	nouveau
	.type	nouveau, @function
nouveau:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, %eax
	movq	%rcx, -48(%rbp)
	movw	%ax, -36(%rbp)
	movl	$512, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	movq	-8(%rbp), %rax
	leaq	300(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcpy@PLT
	movq	-8(%rbp), %rax
	movzwl	-36(%rbp), %edx
	movw	%dx, 500(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 504(%rax)
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L2
.L3:
	movq	-16(%rbp), %rax
	movq	504(%rax), %rax
	movq	%rax, -16(%rbp)
.L2:
	movq	-16(%rbp), %rax
	movq	504(%rax), %rax
	testq	%rax, %rax
	jne	.L3
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 504(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	nouveau, .-nouveau
	.globl	AfficheList
	.type	AfficheList, @function
AfficheList:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L5
.L6:
	movq	-8(%rbp), %rax
	addq	$300, %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-8(%rbp), %rax
	movq	504(%rax), %rax
	movq	%rax, -8(%rbp)
.L5:
	movq	-8(%rbp), %rax
	movq	504(%rax), %rax
	testq	%rax, %rax
	jne	.L6
	movq	-8(%rbp), %rax
	addq	$300, %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	AfficheList, .-AfficheList
	.section	.rodata
.LC0:
	.string	"Da vinci code"
.LC1:
	.string	"Dan BROWN"
.LC2:
	.string	"Le malade imaginaire"
.LC3:
	.string	"Moli\303\250re"
.LC4:
	.string	"Les mis\303\251rables"
.LC5:
	.string	"Victor HUGO"
.LC6:
	.string	"Les fleurs du mal"
.LC7:
	.string	"Charles BAUDELAIRE"
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
	movl	$512, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movabsq	$2336916755888567379, %rdx
	movq	%rdx, (%rax)
	movl	$1196312907, 8(%rax)
	movb	$0, 12(%rax)
	movq	-8(%rbp), %rax
	addq	$300, %rax
	movabsq	$7308892947752182092, %rcx
	movq	%rcx, (%rax)
	movl	$1919252000, 8(%rax)
	movw	$25972, 12(%rax)
	movb	$0, 14(%rax)
	movq	-8(%rbp), %rax
	movw	$1996, 500(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 504(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	movl	$2006, %edx
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	nouveau
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	movl	$1673, %edx
	leaq	.LC2(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	call	nouveau
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	movl	$1862, %edx
	leaq	.LC4(%rip), %rsi
	leaq	.LC5(%rip), %rdi
	call	nouveau
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	movl	$1857, %edx
	leaq	.LC6(%rip), %rsi
	leaq	.LC7(%rip), %rdi
	call	nouveau
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	AfficheList
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	4
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
