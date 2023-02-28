#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int handler = open(argv[1], O_CREAT | O_RDWR);

    write(handler, "Hola Mundo", 10);

    close(handler);
}