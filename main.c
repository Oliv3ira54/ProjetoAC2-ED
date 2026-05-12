#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#include "registro.h"
#include "vetor.h"
#include "lista.h"
#include "vetor.c"
#include "lista.c"
#define TOTAL_REGISTROS 100000
#define TOTAL_BUSCAS 50000
#define TOTAL_REMOCOES 10000
#define TOTAL_REGISTROS 100000
#define TOTAL_BUSCAS 50000
#define TOTAL_REMOCOES 10000

Registro gerarRegistro(int id) {

    Registro r;

    r.id = id;

    sprintf(r.nome, "Registro_%d", id);

    r.valor = (float)(rand() % 10000) / 10.0;

    return r;
}

void executarTesteDesempenho(Vetor *vetor, Lista *lista) {

    clock_t inicio, fim;

    double tempoInsercaoVetor;
    double tempoBuscaVetor;
    double tempoRemocaoVetor;

    double tempoInsercaoLista;
    double tempoBuscaLista;
    double tempoRemocaoLista;

    // =========================
    // INSERCAO VETOR
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REGISTROS; i++) {
        inserirVetor(vetor, gerarRegistro(i));
    }

    fim = clock();

    tempoInsercaoVetor =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // INSERCAO LISTA
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REGISTROS; i++) {
        inserirLista(lista, gerarRegistro(i));
    }

    fim = clock();

    tempoInsercaoLista =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // BUSCA VETOR
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_BUSCAS; i++) {
        buscarVetor(vetor, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoBuscaVetor =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // BUSCA LISTA
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_BUSCAS; i++) {
        buscarLista(lista, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoBuscaLista =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // REMOCAO VETOR
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REMOCOES; i++) {
        removerVetor(vetor, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoRemocaoVetor =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // REMOCAO LISTA
    // =========================

    inicio = clock();

    for (int i = 0; i < TOTAL_REMOCOES; i++) {
        removerLista(lista, rand() % TOTAL_REGISTROS);
    }

    fim = clock();

    tempoRemocaoLista =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // =========================
    // RESULTADOS
    // =========================

    printf("\n==============================");
    printf("\n RESULTADOS DE DESEMPENHO");
    printf("\n==============================");

    printf("\n\n--- VETOR ---");
    printf("\nInsercao: %.4f segundos", tempoInsercaoVetor);
    printf("\nBusca: %.4f segundos", tempoBuscaVetor);
    printf("\nRemocao: %.4f segundos", tempoRemocaoVetor);

    printf("\n\n--- LISTA ---");
    printf("\nInsercao: %.4f segundos", tempoInsercaoLista);
    printf("\nBusca: %.4f segundos", tempoBuscaLista);
    printf("\nRemocao: %.4f segundos", tempoRemocaoLista);

    printf("\n\n==============================\n");
}

void mostrarMemoria() {

    printf("\n==============================");
    printf("\n ANALISE DE MEMORIA");
    printf("\n==============================");

    printf("\n\nTamanho Registro: %lu bytes",
           sizeof(Registro));

    printf("\nTamanho No Lista: %lu bytes",
           sizeof(No));

    printf("\n\nMemoria Vetor Aproximada: %lu bytes",
           sizeof(Registro) * TOTAL_REGISTROS);

    printf("\nMemoria Lista Aproximada: %lu bytes",
           sizeof(No) * TOTAL_REGISTROS);

    printf("\n\n==============================\n");
}
void pausarELimpar() {

    printf("\n\nPressione qualquer tecla para continuar...");

    getch();

    system("cls");
}

int main() {

    srand(time(NULL));

    Vetor vetor;
    Lista lista;

    inicializarVetor(&vetor, TOTAL_REGISTROS);
    inicializarLista(&lista);

    int opcao;
    int id;

    Registro r;

    do {

        printf("\n==============================");
        printf("\n SISTEMA DE REGISTROS");
        printf("\n==============================");

        printf("\n1 - Inserir registro");
        printf("\n2 - Buscar registro");
        printf("\n3 - Remover registro");
        printf("\n4 - Executar teste de desempenho");
        printf("\n5 - Mostrar analise de memoria");
        printf("\n0 - Sair");

        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

        case 1:

            printf("\nDigite o ID: ");
            scanf("%d", &r.id);

            printf("Digite o nome: ");
            scanf("%s", r.nome);

            printf("Digite o valor: ");
            scanf("%f", &r.valor);

            inserirVetor(&vetor, r);
            inserirLista(&lista, r);

            printf("\nRegistro inserido com sucesso!\n");

            pausarELimpar();

            break;

        case 2:

            printf("\nDigite o ID para busca: ");
            scanf("%d", &id);

            // =========================
            // BUSCA NO VETOR
            // =========================

            int pos = buscarVetor(&vetor, id);

            if (pos != -1) {

                printf("\n=== REGISTRO ENCONTRADO NO VETOR ===");

                printf("\nID: %d", vetor.dados[pos].id);
                printf("\nNome: %s", vetor.dados[pos].nome);
                printf("\nValor: %.2f\n", vetor.dados[pos].valor);

            } else {

                printf("\nRegistro NAO encontrado no vetor.\n");
            }

            // =========================
            // BUSCA NA LISTA
            // =========================

            No *resultado = buscarLista(&lista, id);

            if (resultado != NULL) {

                printf("\n=== REGISTRO ENCONTRADO NA LISTA ===");

                printf("\nID: %d", resultado->dado.id);
                printf("\nNome: %s", resultado->dado.nome);
                printf("\nValor: %.2f\n", resultado->dado.valor);

            } else {

                printf("\nRegistro NAO encontrado na lista.\n");
            }

            pausarELimpar();

            break;

        case 3:

            printf("\nDigite o ID para remover: ");
            scanf("%d", &id);

            removerVetor(&vetor, id);
            removerLista(&lista, id);

            printf("\nRegistro removido.\n");
            pausarELimpar();

            break;

        case 4:

            executarTesteDesempenho(&vetor, &lista);
            pausarELimpar();
            break;

        case 5:

            mostrarMemoria();
            pausarELimpar();

            break;

        case 0:

            printf("\nEncerrando programa...\n");
            break;

        default:

            printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    liberarVetor(&vetor);
    liberarLista(&lista);

    system("pause");

    return 0;
}
