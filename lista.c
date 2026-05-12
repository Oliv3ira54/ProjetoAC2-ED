#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

void inserirLista(Lista *l, Registro r) {
    No *novo = (No*) malloc(sizeof(No));

    novo->dado = r;
    novo->prox = l->inicio;

    l->inicio = novo;
    l->tamanho++;
}

No* buscarLista(Lista *l, int id) {
    No *atual = l->inicio;

    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

void removerLista(Lista *l, int id) {
    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->dado.id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {

        if (anterior == NULL) {
            l->inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }

        free(atual);
        l->tamanho--;
    }
}

void liberarLista(Lista *l) {
    No *atual = l->inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}