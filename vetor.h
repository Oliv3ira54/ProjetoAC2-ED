#ifndef VETOR_H
#define VETOR_H

#include "registro.h"

typedef struct {
    Registro *dados;
    int tamanho;
    int capacidade;
} Vetor;

void inicializarVetor(Vetor *v, int capacidade);
void inserirVetor(Vetor *v, Registro r);
int buscarVetor(Vetor *v, int id);
void removerVetor(Vetor *v, int id);
void liberarVetor(Vetor *v);

#endif