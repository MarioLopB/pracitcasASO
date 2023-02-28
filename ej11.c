#include <stdio.h>
#include <signal.h>

struct sigaction sa, saa;

void handler(int sig)
{
    printf(" SIGINT received %d\n", sig);

    sigaction(SIGINT, &saa, NULL);
}

int main(void)
{
    int sig_type = 0;
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, &saa);
    while (1)
    {
    }
    return 0;
}