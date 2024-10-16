#include <fcntl.h>
#include <stdio.h>

extern void _exit(int code);
extern int main (int argc, char *argv[]);

void _start(int argc, char *argv[]) {
	int ex = main(argc, argv);
	_exit(ex);
}
