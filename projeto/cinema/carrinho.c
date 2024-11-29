#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"

void inicializarCarrinho(Carrinho *carrinho) {
    carrinho->capacidade = 2;
    carrinho->total_items = 0;
    carrinho->items = malloc(carrinho->capacidade * sizeof(ItemCarrinho));
    if (carrinho->items == NULL) {
        printf("❌ Erro ao inicializar carrinho!\n");
        exit(1);
    }
}

void adicionarAoCarrinho(Carrinho *carrinho, int id, int quantidade) {
    if (carrinho->total_items >= carrinho->capacidade) {
        carrinho->capacidade *= 2;
        carrinho->items = realloc(carrinho->items, carrinho->capacidade * sizeof(ItemCarrinho));
        if (carrinho->items == NULL) {
            printf("❌ Erro ao redimensionar carrinho!\n");
            exit(1);
        }
    }

    carrinho->items[carrinho->total_items].id = id;
    carrinho->items[carrinho->total_items].quantidade = quantidade;
    carrinho->total_items++;
    printf("✅ Filme adicionado ao carrinho!\n");
}

void finalizarCompra(Carrinho *carrinho, Filme *filmes, int total_filmes) {
    float total = 0.0;
    printf("🛒 Itens no carrinho:\n");
    for (int i = 0; i < carrinho->total_items; i++) {
        for (int j = 0; j < total_filmes; j++) {
            if (filmes[j].id == carrinho->items[i].id) {
                float subtotal = filmes[j].valor_ingresso * carrinho->items[i].quantidade;
                total += subtotal;
                printf("🎬 Filme: %s | Quantidade: %d | Subtotal: R$%.2f\n", filmes[j].titulo, carrinho->items[i].quantidade, subtotal);
                break;
            }
        }
    }
    printf("💰 Total: R$%.2f\n", total);
    carrinho->total_items = 0;
    printf("✅ Compra finalizada e carrinho limpo.\n");
}
