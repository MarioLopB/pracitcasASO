#include <stdio.h>
#include <signal.h>
#include <unistd.h>
struct sigaction sa;
int seconds;
void second(int i)
{
}
int main(void)
{

    int i, j;
    seconds = 0;
    sa.sa_handler = second;
    sigaction(SIGALRM, &sa, NULL);

    while(1){
        seconds++;
        alarm(1);
        pause();
        printf("%d\n", seconds);
    }
    return 0;
}