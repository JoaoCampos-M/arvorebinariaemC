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

int conta_nos_nao_folha(struct No* no) {
    if (no == NULL || (no->esq == NULL && no->dir == NULL))
        return 0;
    else
        return 1 + conta_nos_nao_folha(no->esq) + conta_nos_nao_folha(no->dir);
}

int altura(struct No* no) {
    if (no == NULL)
        return -1;
    else {
        int esq_altura = altura(no->esq);
        int dir_altura = altura(no->dir);
        if (esq_altura > dir_altura)
            return esq_altura + 1;
        else
            return dir_altura + 1;
    }
}

int soma_arvore(struct No* no) {
    if (no == NULL)
        return 0;
    else
        return no->value + soma_arvore(no->esq) + soma_arvore(no->dir);
}

float media(struct No* no) {
    int num_nos = conta_nos(no);
    if (num_nos == 0)
        return 0;
    else
        return (float) soma_arvore(no) / num_nos;
}

int main() {
    // Exemplo de uso
    struct No* raiz = cria_no(1);
    raiz->esq = cria_no(6);
    raiz->dir = cria_no(13);
    raiz->esq->esq = cria_no(8);
    raiz->esq->dir = cria_no(3);

    printf("a quantidade de nós é %d", conta_nos(raiz)); // saída: 5
    printf("\n a quantidade de nós não folha é: %d", conta_nos_nao_folha(raiz)); // saída: 5
    printf("\n a altura é: %d", altura(raiz)); 
    printf("\n a soma dos nós é: %d", soma_arvore(raiz)); 
    printf("\n a média dos nós é: %.2f", media(raiz)); 

    return 0;
}
