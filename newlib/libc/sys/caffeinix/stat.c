#include <sys/unistd.h>
#include <fcntl.h>
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
