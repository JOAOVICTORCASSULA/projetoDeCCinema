#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

void liberarFilme(Filme *filme) {
    free(filme->titulo);
    free(filme->horario);
}

Filme *adicionarFilmeMemoria(Filme *filmes, int *total, int *capacidade) {
    if (*total >= *capacidade) {
        *capacidade *= 2;
        filmes = realloc(filmes, (*capacidade) * sizeof(Filme));
        if (filmes == NULL) {
            printf("❌ Erro ao alocar memória para os filmes!\n");
            exit(1);
        }
    }

    Filme *filme = &filmes[*total];
    filme->titulo = malloc(50 * sizeof(char));
    filme->horario = malloc(10 * sizeof(char));

    printf("🎬 ID do Filme: ");
    scanf("%d", &filme->id);
    printf("🎬 Titulo: ");
    scanf(" %[^\n]s", filme->titulo);
    printf("🕒 Horario (HH:MM): ");
    scanf("%s", filme->horario);
    printf("💲 Valor do Ingresso: ");
    scanf("%f", &filme->valor_ingresso);
    printf("🕔 Duracao (min): ");
    scanf("%d", &filme->duracao);
    printf("🔞 Classificacao indicativa: ");
    scanf("%d", &filme->classificacao);

    (*total)++;
    printf("✅ Filme adicionado com sucesso!\n");
    return filmes;
}

void exibirFilmes(Filme *filmes, int total) {
    if (total == 0) {
        printf("📂 Nenhum filme encontrado.\n");
        return;
    }

    printf("📜 Lista de Filmes:\n\n");
    for (int i = 0; i < total; i++) {
        Filme *filme = &filmes[i];
        printf("🎥 ID: %d\n📖 Titulo: %s\n🕒 Horario: %s\n💲 Valor: R$%.2f\n⏱ Duracao: %d minutos\n🔞 Classificacao: %d anos\n", 
               filme->id, filme->titulo, filme->horario, filme->valor_ingresso, filme->duracao, filme->classificacao);
        printf("----------------------\n");
    }
}

Filme *removerFilmeMemoria(Filme *filmes, int *total, int id) {
    int encontrado = 0;
    for (int i = 0; i < *total; i++) {
        if (filmes[i].id == id) {
            encontrado = 1;
            liberarFilme(&filmes[i]);
            for (int j = i; j < *total - 1; j++) {
                filmes[j] = filmes[j + 1];
            }
            (*total)--;
            break;
        }
    }
    if (encontrado) {
        printf("✅ Filme removido com sucesso!\n");
    } else {
        printf("❌ Filme não encontrado.\n");
    }
    return filmes;
}
