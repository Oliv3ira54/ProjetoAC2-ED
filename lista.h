#ifndef LISTA_H
#define LISTA_H

#include "registro.h"

typedef struct No {
    Registro dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

void inicializarLista(Lista *l);
void inserirLista(Lista *l, Registro r);
No* buscarLista(Lista *l, int id);
void removerLista(Lista *l, int id);
void liberarLista(Lista *l);

#endif