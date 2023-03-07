#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int tubo[2];

    int comando;

    pipe(tubo);

    __pid_t p = fork();


    if(p == 0){
        close(tubo[1]);
        dup2(tubo[0], 0);
        execl ("/usr/bin/wc" , "wc" , (char *) 0) ;

    } else {
        close(tubo[0]);
        dup2(tubo[1], 1);
        execl ("/usr/bin/ls" , "ls " , (char *) 0) ;
    }

    return 0;
}