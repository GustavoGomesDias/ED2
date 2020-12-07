#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStr.h"

int main(int argc, char **argv){
    int tam, tam2;
    printf("Tamanho da string: ");
    scanf("%d", &tam);
    String *new = cria(tam);
    preence_string(new, tam);
    print_char(new, tam);
    printf("\n");

    printf("Tamanho da string: ");
    scanf("%d", &tam2);
    String *new2 = cria(tam2);
    preence_string(new2, tam2);
    print_char(new2, tam2);
    printf("\n");
    
    String *conc = concatena_string(new, new2, (tam + tam2));
    print_char(conc, (tam + tam2));
    return 0;
}