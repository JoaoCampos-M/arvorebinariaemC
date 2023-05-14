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

int altura(struct No* no) {
    if (no == NULL)
        return -1;
    else {
        int esq_altura = altura(no->esq); //percorre a arvore dos contando os nos, o localizado mais a fundo na arvore sera a altura
        int dir_altura = altura(no->dir);
        if (esq_altura > dir_altura)
            return esq_altura + 1; // no raiz conta como 0 por isso +1
        else
            return dir_altura + 1;
    }
}

int esta_balanceada(struct No* no) {
    if (no == NULL)
        return 1;
    else {
        int esq_altura = altura(no->esq);
        int dir_altura = altura(no->dir);
        if (abs(esq_altura - dir_altura) <= 1 &&
            esta_balanceada(no->esq) &&
            esta_balanceada(no->dir))
            return 1;
        else
            return 0;
    }
}

int main() {
    struct No* raiz = cria_no(1);
    raiz->esq = cria_no(6);
    raiz->dir = cria_no(13);
    raiz->esq->esq = cria_no(8);
    raiz->esq->esq->esq = cria_no(3);

    if (esta_balanceada(raiz))
        printf("A arvore esta balanceada");
    else
        printf("A arvore nao esta balanceada");

    return 0;
}
