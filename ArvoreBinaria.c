#include <stdio.h>
#include <stdlib.h>

struct No {
    int value;
    struct No* esq;
    struct No* dir;
};

struct No* cria_no(int value) {
    struct No* no = (struct No*) malloc(sizeof(struct No));
    no->value = value;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

int conta_nos(struct No* no) {
    if (no == NULL)
        return 0;
    else
        return 1 + conta_nos(no->esq) + conta_nos(no->dir);
}

int main() {
    // Exemplo de uso
    struct No* raiz = cria_no(1);
    raiz->esq = cria_no(2);
    raiz->dir = cria_no(3);
    raiz->esq->esq = cria_no(4);
    raiz->esq->dir = cria_no(5);

    printf("%d", conta_nos(raiz)); // saída: 5

    return 0;
}
