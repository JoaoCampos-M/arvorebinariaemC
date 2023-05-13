#include<stdio.h>
#include<stdlib.h>
#include"ArvoreBinaria.h"

struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
}

int conta_NO = 0;

ArvBin* raiz;

ArvBin*cria_ArvBin(){
  ArvBin*raiz = (CriaArvBin*) malloc(sizeof (CriaArvBin));
  if(raiz != NULL)
    *raiz = NULL
    return raiz;
}

CriaArvBin raiz = cria_ArvBin();

void conta_NO (struct NO* no){
    conta_NO++;
    if(no == NULL)
        return;
    conta_NO(no->esq);
    conta_NO(no->dir);

 }
 void conta_ArvBin(ArvBin* raiz) {
    if(raiz == NULL)
        return;
        conta_NO(*raiz);
        printf(conta_NO)
        counta (raiz);
 }
 
 int main();
