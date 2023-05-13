#include<stdio.h>
#include<stdlib.h>
#include"ArvoreBinaria.h"

struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
}

ArvBin* raiz;

void libera_NO (struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
 }
 void libera_ArvBin(ArvBin* raiz) {
    if(raiz == NULL)
        return;
        libera_mo(*raiz);
        free (raiz)
 }
 