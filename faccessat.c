#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>

int faccessat(int fd, const char *filename, int amode, int flag)
{
        return syscall(SYS_faccessat, fd, filename, amode, flag);
}

int euidaccess(const char *filename, int amode)
{
        return faccessat(AT_FDCWD, filename, amode, AT_EACCESS);
}

int eaccess(const char *filename, int amode)
{
        return euidaccess(filename, amode);
}
