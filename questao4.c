#include <stdio.h>
#include <stdlib.h>

struct No {
    int value;
    struct No* esq;
    struct No* dir;
};

//criação da arvore
struct No* cria_no(int value) {
    struct No* no = (struct No*) malloc(sizeof(struct No));
    no->value = value;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}


int e_estritamente_binaria(struct No* no) {
    if (no == NULL)
        return 1;
    if (no->esq == NULL && no->dir == NULL)//verifica cada arvore e cada sub arvore vendo se ela tem 0 nos filhos
        return 1;
    if (no->esq != NULL && no->dir != NULL) //verifica a arvore e cada sub arvore vendo se ela tem 2 nos filhos
        return e_estritamente_binaria(no->esq) && e_estritamente_binaria(no->dir);
    return 0;
}

int main() {
    struct No* raiz = cria_no(1);
    raiz->esq = cria_no(6);
    raiz->dir = cria_no(13);
    raiz->esq->esq = cria_no(8);
    raiz->esq->dir- = cria_no(3);

    if (e_estritamente_binaria(raiz))
        printf("A arvore e estritamente binaria.\n");
    else
        printf("A arvore nao e estritamente binaria.\n");

    return 0;
}
