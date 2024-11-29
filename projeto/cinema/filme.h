#ifndef FILME_H
#define FILME_H

typedef struct {
    int id;
    char *titulo;
    char *horario;
    float valor_ingresso;
    int duracao;
    int classificacao;
} Filme;

void liberarFilme(Filme *filme);
Filme *adicionarFilmeMemoria(Filme *filmes, int *total, int *capacidade);
void exibirFilmes(Filme *filmes, int total);
Filme *removerFilmeMemoria(Filme *filmes, int *total, int id);

#endif // FILME_H
