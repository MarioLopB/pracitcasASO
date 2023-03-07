#include <stdio.h>
#include <unistd.h>

int main(){
    int tubo[2];
    int abuelo;
    int hijo;

    pipe(tubo);

    __pid_t p = fork();
    hijo = p;

    if(p == 0){
        int padre = getppid();

        read(tubo[0], &abuelo, sizeof(abuelo));
        
        printf("[H] Mi padre = %d , yo = %d , mi abuelo = %d", padre, getpid(), abuelo);
    } else{
        int padre = getppid();
        abuelo = padre;
        int yo = getpid();

        write(tubo[1], &abuelo, sizeof(abuelo));
        printf("[P] Mi padre = %d , yo = %d , mi hijo = %d", padre, yo, p);
    }

    return 0;
}