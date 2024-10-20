#include <sys/unistd.h>
#include <fcntl.h>

#define SYS_mknod  17
#define SYS_mkdir  20

/**  
 *@description:
 * This function retrieves the status information of a file given its path `path` and stores it in the `struct stat` `st`.  
 * @param {char} path Path to the file for which status information is to be retrieved  
 * @param {stat} st Pointer to a `struct stat` where the file status information will be stored  
 * @return Returns 0 on success, -1 on failure  
 */
int stat(const char *path, struct stat *st)
{
        int fd, ret;

        fd = open(path, O_RDONLY);
        if(fd == -1)
                return -1;
        
        ret = fstat(fd, st);
        close(fd);
        
        return ret;
}

int mkdir(const char *pathname, mode_t mode)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_mkdir));
}

int mknod(const char *pathname, mode_t mode, dev_t dev)
{
	asm volatile("li a7, %0; ecall;" : : "i" (SYS_mknod));
}

