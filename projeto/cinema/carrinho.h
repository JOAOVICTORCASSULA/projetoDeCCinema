#ifndef CARRINHO_H
#define CARRINHO_H

#include "filme.h"

typedef struct {
    int id;
    int quantidade;
} ItemCarrinho;

typedef struct {
    ItemCarrinho *items;
    int total_items;
    int capacidade;
} Carrinho;

void inicializarCarrinho(Carrinho *carrinho);
void adicionarAoCarrinho(Carrinho *carrinho, int id, int quantidade);
void finalizarCompra(Carrinho *carrinho, Filme *filmes, int total_filmes);

#endif // CARRINHO_H
