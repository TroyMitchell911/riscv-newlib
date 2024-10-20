/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>

#define SYS_fork    1
#define SYS_exit    2
#define SYS_wait    3
#define SYS_pipe    4
#define SYS_read    5
#define SYS_kill    6
#define SYS_exec    7
#define SYS_fstat   8
#define SYS_chdir   9
#define SYS_dup    10
#define SYS_getpid 11
#define SYS_sbrk   12
#define SYS_sleep  13
#define SYS_uptime 14
#define SYS_open   15
#define SYS_write  16
#define SYS_unlink 18
#define SYS_link   19
#define SYS_close  21
#define SYS_clone  120
#define SYS_getcwd 121

int chdir(const char *path)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_chdir));
}

int clone(int (*fn)(void *), void *child_stack, int flags, void *arg, ...)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_clone));
}

int close(int fd)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_close));
}

int dup(int fd)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_dup));
}

int exec(const char *path, char *const argv[])
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_exec));
}

void _exit(int code)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_exit));
}

int fork()
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_fork));
}

int fstat(int fd, struct stat *buf)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_fstat));
}

int getcwd(char *buf, int size)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_getcwd));
}

int getpid(void)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_getpid));
}

int kill(int pid)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_kill));
}

int link(const char *oldpath, const char *newpath)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_link));
}

int open(const char *name, int flags, ...)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_open));
}

int pipe(int *pipefd)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_pipe));
}

int read(int fd, char *buf, int count)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_read));
}

char* sbrk(int increment)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_sbrk));
}

int sleep(int seconds)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_sleep));
}

int unlink(const char *pathname)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_unlink));
}

int uptime(void)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_uptime));
}

int wait(int *status)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_wait));
}

int write(int fd, const char *buf, int count)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_write));
}
