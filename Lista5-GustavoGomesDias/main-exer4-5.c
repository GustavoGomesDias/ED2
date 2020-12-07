#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStr.h"

int main(int argc, char **argv){
    int tam;
    printf("Tamanho da string: ");
    scanf("%d", &tam);
    char texto[tam];
    adiciona_char(texto, tam);
    String *new = cria(tam);
    fill(new, texto, tam);
    print_char(new, tam);
    desaloca_string(new);
    return 0;
}