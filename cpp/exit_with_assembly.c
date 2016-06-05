// http://www.chongh.wiki/blog/2016/04/08/linux-syscalls/
// Linux系统调用，通过汇编触发系统调用
	int
main(int argc, char *argv[])
{
	unsigned int syscall_nr = 1;
	int exit_status = 42;

	asm ("movl %0, %%eax\n"
			"movl %1, %%ebx\n"
			"int $0x80"
			: /* output parameters, we aren't outputting anything, no none */
			/* (none) */
			: /* input parameters mapped to %0 and %1, repsectively */
			"m" (syscall_nr), "m" (exit_status)
			: /* registers that we are "clobbering", unneeded since we are calling exit */
			"eax", "ebx");
}

