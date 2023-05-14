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


int nos_com_unico_fileo(struct No* no) {
    if (no == NULL)
        return 0;
    int count = 0;
    if ((no->esq != NULL && no->dir == NULL) || (no->esq == NULL && no->dir != NULL))// verifica esq e dir, caso tenha filho em so 1 deles, caso isso, conta
        count = 1;
    count += nos_com_unico_fileo(no->esq);// quantidade de filhos esq
    count += nos_com_unico_fileo(no->dir);// quantidade de filhos dir
    return count;
}

int main() {
    struct No* raiz = cria_no(1);
    raiz->esq = cria_no(6);
    raiz->dir = cria_no(13);
    raiz->esq->esq = cria_no(8);
    raiz->esq->dir- = cria_no(3);

    printf("Nós com um unico filho: %d", nos_com_unico_fileo(root));
    
    return 0;
}
