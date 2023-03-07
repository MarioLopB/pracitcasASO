#include <stdio.h>
#include <unistd.h>

int main(){
    char entrada[100] = "Hola mundo";
    char salida[10];

    int tubo[2];

    pipe(tubo);

    __pid_t hijo = fork();

    if(hijo == 0){
        write(tubo[1], &entrada, sizeof(entrada));
    } else{
        int n = read(tubo[0], &salida, sizeof(salida));
        printf("Ha leido %d caracteres y son: %s", n,  salida);
    }

    return 0;
}