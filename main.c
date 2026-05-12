#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "registro.h"
#include "vetor.h"
#include "lista.h"
#include "vetor.c"
#include "lista.c"
#define TOTAL_REGISTROS 50000
#define TOTAL_BUSCAS 10000
#define TOTAL_REMOCOES 10000

Registro gerarRegistro(int id) {
    Registro r;

    r.id = id;
    sprintf(r.nome, "Registro_%d", id);
    r.valor = (float)(rand() % 10000) / 10.0;

    return r;
}

int main() {

    srand(time(NULL));

    Vetor vetor;
    Lista lista;

    clock_t inicio, fim;

    double tempoInsercaoVetor;
    double tempoBuscaVetor;
    double tempoRemocaoVetor;

    double tempoInsercaoLista;
    double tempoBuscaLista;
    double tempoRemocaoLista;

    inicializarVetor(&vetor, TOTAL_REGISTROS);
    inicializarLista(&lista);

    // =========================
    // INSERÇÃO VETOR
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REGISTROS; i++) {
        inserirVetor(&vetor, gerarRegistro(i));
    }

    fim = clock();

    tempoInsercaoVetor =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // INSERÇÃO LISTA
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REGISTROS; i++) {
        inserirLista(&lista, gerarRegistro(i));
    }

    fim = clock();

    tempoInsercaoLista =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // BUSCA VETOR
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_BUSCAS; i++) {
        buscarVetor(&vetor, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoBuscaVetor =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // BUSCA LISTA
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_BUSCAS; i++) {
        buscarLista(&lista, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoBuscaLista =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // REMOÇÃO VETOR
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REMOCOES; i++) {
        removerVetor(&vetor, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoRemocaoVetor =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // REMOÇÃO LISTA
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REMOCOES; i++) {
        removerLista(&lista, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoRemocaoLista =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // RESULTADOS
    // =========================

    printf("\n===== RESULTADOS =====\n");

    printf("\n--- VETOR ---\n");
    printf("Insercao: %.4f segundos\n", tempoInsercaoVetor);
    printf("Busca: %.4f segundos\n", tempoBuscaVetor);
    printf("Remocao: %.4f segundos\n", tempoRemocaoVetor);

    printf("\n--- LISTA ---\n");
    printf("Insercao: %.4f segundos\n", tempoInsercaoLista);
    printf("Busca: %.4f segundos\n", tempoBuscaLista);
    printf("Remocao: %.4f segundos\n", tempoRemocaoLista);

    // =========================
    // ANÁLISE DE MEMÓRIA
    // =========================

    printf("\n===== USO DE MEMORIA =====\n");

    printf("\nTamanho Registro: %lu bytes",
           sizeof(Registro));

    printf("\nTamanho No Lista: %lu bytes",
           sizeof(No));

    printf("\nMemoria Vetor Aproximada: %lu bytes",
           sizeof(Registro) * TOTAL_REGISTROS);

    printf("\nMemoria Lista Aproximada: %lu bytes\n",
           sizeof(No) * TOTAL_REGISTROS);

    liberarVetor(&vetor);
    liberarLista(&lista);

    system("pause");

    return 0;

}
