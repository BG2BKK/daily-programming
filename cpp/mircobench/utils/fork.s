	.file	"fork.c"
	.text
	.globl	prepare
	.type	prepare, @function
prepare:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movl	-28(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L4
.L5:
	movl	-12(%rbp), %eax
	subl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rcx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movq	%rdx, (%rax)
	movl	-28(%rbp), %eax
	addl	%eax, -12(%rbp)
.L4:
	movl	-12(%rbp), %eax
	cltq
	cmpq	-24(%rbp), %rax
	jb	.L5
	movl	-12(%rbp), %eax
	subl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rax, (%rdx)
	movq	-8(%rbp), %rax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	prepare, .-prepare
	.globl	cooldown
	.type	cooldown, @function
cooldown:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L7
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
.L7:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	cooldown, .-cooldown
	.comm	pid,4,4
	.globl	PROG
	.section	.rodata
.LC0:
	.string	"./hello.o"
	.data
	.align 8
	.type	PROG, @object
	.size	PROG, 8
PROG:
	.quad	.LC0
	.local	uctx_main
	.comm	uctx_main,936,32
	.local	uctx_fsm
	.comm	uctx_fsm,936,32
	.local	fsm_stack
	.comm	fsm_stack,4096,32
	.local	main_stack
	.comm	main_stack,4096,32
	.text
	.globl	fsm
	.type	fsm, @function
fsm:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$uctx_main, %esi
	movl	$uctx_fsm, %edi
	call	swapcontext
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	fsm, .-fsm
	.globl	do_ucontext
	.type	do_ucontext, @function
do_ucontext:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$10000, -4(%rbp)
	jmp	.L10
.L12:
	movl	$uctx_fsm, %edi
	call	getcontext
	movq	$fsm_stack, uctx_fsm+16(%rip)
	movq	$4096, uctx_fsm+32(%rip)
	movq	$uctx_main, uctx_fsm+8(%rip)
	movl	$0, %edx
	movl	$fsm, %esi
	movl	$uctx_fsm, %edi
	movl	$0, %eax
	call	makecontext
	movl	$uctx_fsm, %esi
	movl	$uctx_main, %edi
	call	swapcontext
.L10:
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -4(%rbp)
	testl	%eax, %eax
	jne	.L12
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	do_ucontext, .-do_ucontext
	.globl	do_fork
	.type	do_fork, @function
do_fork:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	fork
	movl	%eax, pid(%rip)
	movl	pid(%rip), %eax
	cmpl	$-1, %eax
	je	.L19
	testl	%eax, %eax
	jne	.L18
	movl	$1, %edi
	call	exit
.L18:
	movl	pid(%rip), %eax
	movl	$0, %edx
	movl	$0, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	waitpid
	jmp	.L17
.L19:
	nop
.L17:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	do_fork, .-do_fork
	.globl	do_forkexec
	.type	do_forkexec, @function
do_forkexec:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	fork
	movl	%eax, pid(%rip)
	movl	pid(%rip), %eax
	cmpl	$-1, %eax
	je	.L26
	testl	%eax, %eax
	jne	.L25
	movl	$1, %edi
	call	close
	movq	PROG(%rip), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	execve
	movl	$1, %edi
	call	exit
.L25:
	movl	pid(%rip), %eax
	movl	$0, %edx
	movl	$0, %esi
	movl	%eax, %edi
	movl	$0, %eax
	call	waitpid
	jmp	.L24
.L26:
	nop
.L24:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	do_forkexec, .-do_forkexec
	.globl	get_iteration
	.type	get_iteration, @function
get_iteration:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$100000, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	get_iteration, .-get_iteration
	.globl	get_total_us
	.type	get_total_us, @function
get_total_us:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	imulq	$1000000, %rax, %rsi
	movq	-32(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movabsq	$2361183241434822607, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	sarq	$7, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	addq	%rsi, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	get_total_us, .-get_total_us
	.globl	get_latency
	.type	get_latency, @function
get_latency:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$40, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get_total_us
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	js	.L32
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L33
.L32:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L33:
	pxor	%xmm1, %xmm1
	cvtsi2sd	-36(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	get_latency, .-get_latency
	.globl	get_clock_colapse
	.type	get_clock_colapse, @function
get_clock_colapse:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	call	get_iteration
	cltq
	movq	%rax, -80(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	jmp	.L36
.L37:
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
.L36:
	movq	-80(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -80(%rbp)
	testq	%rax, %rax
	jne	.L37
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, %eax
	call	get_iteration
	movl	%eax, %edx
	leaq	-48(%rbp), %rcx
	leaq	-64(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	get_latency
	movq	%xmm0, %rax
	movq	%rax, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L39
	call	__stack_chk_fail
.L39:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	get_clock_colapse, .-get_clock_colapse
	.globl	get_loop_colapse
	.type	get_loop_colapse, @function
get_loop_colapse:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	call	get_iteration
	cltq
	movq	%rax, -64(%rbp)
	leaq	-72(%rbp), %rax
	movq	%rax, -72(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	jmp	.L41
.L42:
	movq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -72(%rbp)
.L41:
	movq	-64(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -64(%rbp)
	testq	%rax, %rax
	jne	.L42
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, %eax
	call	get_iteration
	movl	%eax, %edx
	leaq	-32(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	get_latency
	movq	%xmm0, %rax
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L44
	call	__stack_chk_fail
.L44:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	get_loop_colapse, .-get_loop_colapse
	.section	.rodata
	.align 8
.LC1:
	.string	"colapsed: %lf\t latency: %lf us\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	get_loop_colapse
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movl	$0, %eax
	call	get_clock_colapse
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	$.LC1, %edi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
