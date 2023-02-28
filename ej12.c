#include <stdio.h>
#include <signal.h>

struct sigaction sa, saa, so;

void handler2(int sig)
{
    printf(" Adios %d\n", sig);

    sigaction(SIGINT, &so, NULL);
}


void handler1(int sig)
{
    printf(" Hola %d\n", sig);

    sigaction(SIGINT, &saa, &so);
}
int main(void)
{
    int sig_type = 0;
    sa.sa_handler = handler1;
    saa.sa_handler = handler2;
    sigaction(SIGINT, &sa, NULL);
    while (1)
    {
    }
    return 0;
}