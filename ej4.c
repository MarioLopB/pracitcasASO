#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(void)
{
    int pid = fork();
    if (pid == 0)
    {
        sleep(1);
        printf("[H] ppid = %5d, pid = %5d\n", getppid(), getpid());
        exit(33);
    }
    else
    {
        printf("[P] ppid = %5d, pid = %5d, H = %5d\n", getppid(), getpid(), pid);
        int status, salida;
        waitpid(pid, &status, NULL);
        salida = WEXITSTATUS(status);
        printf("[P] el proceso pid = %d acaba de terminar con estado %d y salida %d", pid, status, salida);
    }
    return 0;
}