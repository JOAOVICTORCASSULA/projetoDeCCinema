#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "filme.h"
#include "carrinho.h"

void pause() {
    printf("\nPressione Enter para continuar... ");
    getchar();
    getchar();
    system("cls");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int opcao, id, quantidade;
    Filme *filmes = malloc(2 * sizeof(Filme));
    Carrinho carrinho;
    inicializarCarrinho(&carrinho);

    int total_filmes = 0, capacidade_filmes = 2;

    do {
        printf("\n🎥 ------ Cinema ------ 🎥\n\n");
        printf("1. 📥 Adicionar Filme\n2. 📃 Exibir Filmes\n3. 🗑️ Remover Filme\n4. 🛒 Adicionar ao Carrinho\n5. 💸 Finalizar Compra\n0. 🔚 Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        printf("----------------------\n\n");

        switch (opcao) {
            case 1:
                filmes = adicionarFilmeMemoria(filmes, &total_filmes, &capacidade_filmes);
                break;
            case 2:
                exibirFilmes(filmes, total_filmes);
                break;
            case 3:
                printf("🗑️ ID do Filme para remover: ");
                scanf("%d", &id);
                filmes = removerFilmeMemoria(filmes, &total_filmes, id);
                break;
            case 4:
                printf("🛒 ID do Filme para adicionar ao carrinho: ");
                scanf("%d", &id);
                printf("🔢 Quantidade: ");
                scanf("%d", &quantidade);
                adicionarAoCarrinho(&carrinho, id, quantidade);
                break;
            case 5:
                finalizarCompra(&carrinho, filmes, total_filmes);
                break;
            case 0:
                printf("👋 Até mais!\n");
                break;
            default:
                printf("❌ Opção inválida!\n");
                break;
        }
        pause();
    } while (opcao != 0);

    for (int i = 0; i < total_filmes; i++) {
        liberarFilme(&filmes[i]);
    }
    free(filmes);
    free(carrinho.items);

    return 0;
}
