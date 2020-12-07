#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exer1.h"

struct cadastro{
    char nome[100]; 
    char end[100];
    char tel[10];
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

void set_tel(cadastro *A, char *tel){
    strcpy(A->tel, tel);
}

char *get_tel(cadastro *A){
    return A->tel;
}

void popula_cad(cadastro *A){
    char nome[100];
    char end[100];
    char tel[10];

    printf("Nome: ");
    scanf(" %[^\n]", nome);
    set_nome(A, nome);
    printf("Endereço: ");
    scanf(" %[^\n]", end);
    set_end(A, end);
    
    printf("Telefone de no máximo 10 números (sem DDD): ");
    scanf(" %s", tel);
    printf("\n");
    set_tel(A, tel);
}

void imprime(cadastro *A){
    printf("Nome: %s\n", get_nome(A));
    printf("Endereço: %s\n", get_end(A));
    printf("Número: %s", get_tel(A));
}