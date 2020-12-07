#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStr.h"

/* Struct => exer1 */
struct my_str{
    char *vetor;
    int tam;
};

/* Alocação dinâmica => exer3 */
String *cria(int tam){
    int i;
    String *new = malloc(sizeof(String) * 1);
    new->vetor = malloc(sizeof(char) * tam);
    for(i = 0; i < tam; i++){
        set_char(new, i, '\0');
    }
    set_tam(new, tam);
    return new;
}

/* Exer4 */
void fill(String *s, char *c, int len){
    memcpy(get_vetor(s), c, len);
}

void adiciona_char(char *texto, int len){
    int i;
    for(i = 0; i < len; i++){
        printf("Digite uma letra: ");
        scanf(" %c", &texto[i]);
    }
    printf("\n");
}

/* Exer5 */
void print_char(String *texto, int len){
    int i;
    for(i = 0; i < len; i++){
        printf("%c ", get_char(texto, i));
    }
}

/* Auxiliares */
void set_char(String *arg1, int pos, char l){
    arg1->vetor[pos] = l;
}

char get_char(String *arg1, int pos){
    return arg1->vetor[pos];
}

char *get_vetor(String *arg1){
    return arg1->vetor;
}

void set_tam(String *arg1, int tam){
    arg1->tam = tam;
}

char get_tam(String *arg1){
    return arg1->tam;
}

void preence_string(String *texto, int len){
    int i;
    for(i = 0; i < len; i++){
        char aux;
        printf("Digite uma letra: ");
        scanf(" %c", &aux);
        set_char(texto, i, aux);
    }
}

/* Exer6 */
void desaloca_string(String *arg1){
    free(arg1);
    printf("Excluindo String.");
}

/* Exer7 */
String *concatena_string(String *arg1, String *arg2, int len){
    int i, j, k = 0;
    String *aux = cria(len);
    for(i = 0; i < get_tam(arg1); i++){
        set_char(aux, i, get_char(arg1, i));
    }
    for(j = get_tam(arg1); j < len; j++){
        set_char(aux, j, get_char(arg2, k));
        k++;
    }
    return aux;
}