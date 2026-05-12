#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void inicializarVetor(Vetor *v, int capacidade) {
    v->dados = (Registro*) malloc(sizeof(Registro) * capacidade);
    v->tamanho = 0;
    v->capacidade = capacidade;
}

void inserirVetor(Vetor *v, Registro r) {
    if (v->tamanho < v->capacidade) {
        v->dados[v->tamanho++] = r;
    }
}

int buscarVetor(Vetor *v, int id) {
    for (int i = 0; i < v->tamanho; i++) {
        if (v->dados[i].id == id) {
            return i;
        }
    }
    return -1;
}

void removerVetor(Vetor *v, int id) {
    int pos = buscarVetor(v, id);

    if (pos != -1) {
        for (int i = pos; i < v->tamanho - 1; i++) {
            v->dados[i] = v->dados[i + 1];
        }

        v->tamanho--;
    }
}

void liberarVetor(Vetor *v) {
    free(v->dados);
}