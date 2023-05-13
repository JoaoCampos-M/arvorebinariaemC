#include<stdio.h>
#include<stdlib.h>
#include"ArvoreBinaria.h"

struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
}

ArvBin* raiz;