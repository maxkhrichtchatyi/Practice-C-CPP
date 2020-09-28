/*
 * Fork/Dup and File Entries
 *
 * A fork system call results in descriptors being shared by the parent and
 * child with share by reference semantics. Both the parent and the child are
 * using the same descriptor and reference the same offset in the file entry.
 * The same semantics apply to a dup/dup2 system call used to duplicate a
 * file descriptor.
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    fork();
    write(fd, "abc", 3);
    printf("%ld\n", lseek(fd, 0, SEEK_CUR));
    printf("Current PID: %d, Parrent PID: %d\n", getpid(), getppid());
    close(fd);
    return 0;
}
