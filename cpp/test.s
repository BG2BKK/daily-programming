	.file	"test.c"
	.globl	globalHeader
	.section	.rodata
.LC0:
	.string	"hello"
	.data
	.align 8
	.type	globalHeader, @object
	.size	globalHeader, 8
globalHeader:
	.quad	.LC0
	.globl	globalArrayHeader
	.type	globalArrayHeader, @object
	.size	globalArrayHeader, 6
globalArrayHeader:
	.string	"hello"
	.section	.rodata
.LC1:
	.string	"%p\n"
.LC2:
	.string	"%d\n"
	.text
	.globl	func
	.type	func, @function
func:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %r12
	movl	$10000000, -44(%rbp)
	movl	-44(%rbp), %ebx
	movslq	%ebx, %rax
	subq	$1, %rax
	movq	%rax, -40(%rbp)
	movslq	%ebx, %rax
	movq	%rax, %rsi
	movl	$0, %edi
	movslq	%ebx, %rax
	movq	%rax, %rdx
	movl	$0, %ecx
	movslq	%ebx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movslq	%ebx, %rax
	salq	$2, %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movq	%r12, %rsp
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L2
	call	__stack_chk_fail
.L2:
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	func, .-func
	.section	.rodata
.LC3:
	.string	"Media Player"
.LC4:
	.string	"globalHeader\t%p\n"
.LC5:
	.string	"globalArrayHeader\t%p\n"
.LC6:
	.string	"localHeader\t%p\n"
.LC7:
	.string	"localArrayHeader\t%p\n"
.LC8:
	.string	"staticHeader\t%p\n"
.LC9:
	.string	"staticArrayHeader\t%p\n"
.LC10:
	.string	"heapHeader\t%p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$464, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$400, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$4, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$4, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movb	$97, -449(%rbp)
	movl	$1, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC3, %eax
	movb	%al, -18(%rbp)
	movq	$.LC0, -448(%rbp)
	movl	$1819043176, -16(%rbp)
	movw	$111, -12(%rbp)
	movl	$6, %edi
	call	malloc
	movq	%rax, -440(%rbp)
	movq	-440(%rbp), %rax
	movl	$1819043176, (%rax)
	movw	$111, 4(%rax)
	movq	globalHeader(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$globalArrayHeader, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-448(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movq	staticHeader.2980(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	$staticArrayHeader.2982, %esi
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
	movq	-440(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC0, %eax
	movb	%al, -17(%rbp)
	movzbl	-17(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.data
	.align 8
	.type	staticHeader.2980, @object
	.size	staticHeader.2980, 8
staticHeader.2980:
	.quad	.LC0
	.type	staticArrayHeader.2982, @object
	.size	staticArrayHeader.2982, 6
staticArrayHeader.2982:
	.string	"hello"
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2.1) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
