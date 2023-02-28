#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BLOQUE 4096

int main(int argc, char *argv[])
{
    char buffer[4096];
    int leido;

    int handler1 = open(argv[1], O_RDWR);

    int handler2 = open(argv[2], O_CREAT | O_RDWR, 0600);

    do{
        leido = read(handler1, buffer, BLOQUE);
        write(handler2, buffer, leido);
    } while(leido == BLOQUE);

    close(handler1);

    close(handler2);
}