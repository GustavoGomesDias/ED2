#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exer3.h"

struct cadastro{
    char nome[100]; 
    char end[100];
    char tipo[8];
    char tel[9];
    char DDD[3];
};

cadastro *criaCadatro(){
    cadastro *A;
    A = malloc(sizeof(cadastro));
    return A;
}

void set_nome(cadastro *A, char *nome){
    strcpy(A->nome, nome);
}

char *get_nome(cadastro *A){
    return A->nome;
}

void set_end(cadastro *A, char *end){
    strcpy(A->end, end);
}

char *get_end(cadastro *A){
    return A->end;
}

void set_tipo(cadastro *A, char *tipo){
    strcpy(A->tipo, tipo);
}

char *get_tipo(cadastro *A){
    return A->tipo;
}

void set_DDD(cadastro *A, char *DDD){
    strcpy(A->DDD, DDD);
}

char *get_DDD(cadastro *A){
    return A->DDD;
}

void set_tel(cadastro *A, char *tel){
    strcpy(A->tel, tel);
}

char *get_tel(cadastro *A){
    return A->tel;
}

void popula_cad(cadastro *A){
    char nome[100];
    char end[100];
    char tipo[8], DDD[3], tel[10];

    printf("Nome: ");
    scanf(" %[^\n]", nome);
    set_nome(A, nome);

    printf("Endereço: ");
    scanf(" %[^\n]", end);
    set_end(A, end);
    
    printf("Celular ou fixo? ");
    scanf(" %s", tipo);
    set_tipo(A, tipo);

    printf("Telefone de no máximo 10 números (sem DDD): ");
    scanf(" %s", tel);
    set_tel(A, tel);

    printf("Digite o DDD (3 números): ");
    scanf(" %s", DDD);
    set_DDD(A, DDD); 
}

void imprime(cadastro *A){
    printf("Nome: %s\n", get_nome(A));
    printf("Endereço: %s\n", get_end(A));
    printf("Tipo: %s\n", get_tipo(A));
    printf("Número: %s\n", get_tel(A));
    printf("DDD: %s", get_DDD(A));
}