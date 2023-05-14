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

int conta_nos(struct No* no) {
    if (no == NULL)
        return 0;
    else
        return 1 + conta_nos(no->esq) + conta_nos(no->dir); 
}



void elementos_menores_que_n(struct No* no, int n, int* vetor, int* count) {
    if (no == NULL)
        return;
    elementos_menores_que_n(no->esq, n, vetor, count);
    if (no->value < n) {
        vetor[*count] = no->value;
        (*count)++;
    }
    elementos_menores_que_n(no->dir, n, vetor, count);
}


int main() {
    struct No* raiz = cria_no(1);
    raiz->esq = cria_no(6);
    raiz->dir = cria_no(13);
    raiz->esq->esq = cria_no(8);
    raiz->esq->dir = cria_no(3);

    int n;
    printf("Informe um valor inteiro:\n ");
    scanf("%d",&n);

    int tamanho_arvore = (conta_nos(raiz));


    int* vetor = (int*)malloc(sizeof(int) * tamanho_arvore ); // Aloca espaço para o vetor
    int count = 0;
    elementos_menores_que_n(raiz, n, vetor, &count);
     printf("Valores menores que %d na arvore: \n",n);
    for (int i = 0; i < count; i++) {
        printf("%d ", vetor[i]);
    }
    free(vetor); // Libera o espaço alocado para o vetor

    
    return 0;
}
