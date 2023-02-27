#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int hijos[5];
    pid_t pid;

    for (int i = 0; i < 5; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            if (i == 0)
            {
                execl("/usr/bin/xeyes", "xeyes", (char *)0);
            }
            else if (i == 1)
            {
                execl("/usr/bin/xlogo", "xlogo", (char *)0);
            }
            else if (i == 2)
            {
                execl("/usr/bin/xload", "xload", (char *)0);
            }
            else if (i == 3)
            {
                execl("/usr/bin/xcalc", "xcalc", (char *)0);
            }
            else if (i == 4)
            {
                execl("/usr/bin/xclock", "xclock", "-update", "1", (char *)0);
            }
        }
        else
        {
            hijos[i] = pid;
        }
    }

    while (1)
    {
        pid_t muerto = wait(NULL);

        for (int i = 0; i < 5; i++)
        {
            if (hijos[i] == muerto)
            {
                pid = fork();
                if (pid == 0)
                {
                    if (i == 0)
                    {
                        execl("/usr/bin/xeyes", "xeyes", (char *)0);
                    }
                    else if (i == 1)
                    {
                        execl("/usr/bin/xlogo", "xlogo", (char *)0);
                    }
                    else if (i == 2)
                    {
                        execl("/usr/bin/xload", "xload", (char *)0);
                    }
                    else if (i == 3)
                    {
                        execl("/usr/bin/xcalc", "xcalc", (char *)0);
                    }
                    else if (i == 4)
                    {
                        execl("/usr/bin/xclock", "xclock", "-update", "1", (char *)0);
                    }
                }
                else
                {
                    hijos[i] = pid;
                    break;
                }
            }
        }
    }
}