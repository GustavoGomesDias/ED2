#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exer2.h"

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

void popula_cad(cadastro *A){
    printf("Nome: ");
    scanf(" %[^\n]", A->nome);
    printf("Endereço: ");
    scanf(" %[^\n]", A->end);
    printf("Celular ou fixo? ");
    scanf(" %s", A->tipo);
    printf("Telefone de no máximo 10 números (sem DDD): ");
    scanf(" %s", A->tel);
    printf("Digite o DDD (3 números): ");
    scanf(" %s", A->DDD);
}

void imprime(cadastro *A){
    printf("Nome: %s\n", A->nome);
    printf("Endereço: %s\n", A->end);
    printf("Tipo: %s\n", A->tipo);
    printf("Número: %s\n", A->tel);
    printf("DDD: %s ", A->DDD);
} 