#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pid = getpid();

    printf("PID: %d\n", pid);

    execl("/usr/bin/cal", "cal", "-j", (char *)0);

    printf("PID: %d", pid);
}