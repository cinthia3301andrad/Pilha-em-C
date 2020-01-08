#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pilha.h"

struct pilha {
  int tamanho;
  int topo;  
  char *elementos;
};

Pilha *nova(int tamanho) {
  if(tamanho <= 0) return NULL;
  Pilha *p = (Pilha*)malloc(sizeof(Pilha));
  char *elementos = (char*)malloc(tamanho * sizeof(char));
  p->elementos = elementos;
  p->topo = -1;
  p->tamanho = tamanho;
  return p;
}
/* Libera a memória de uma pilha previamente criada */
void libera(Pilha **pilha) {
  free(*pilha);
  *pilha = NULL;
}
/* Adiciona um símbolo na pilha. Retorna 1 se der certo e 0 caso contrário */ 
int push(Pilha *pilha, char simbolo) {
  if(pilha->topo == (pilha->tamanho) -1){
    return 0;
  }
   pilha->topo ++;
  (pilha->elementos)[pilha->topo] = simbolo;
  return 1;
}
/* Remove um símbolo da pilha. Retorna 1 se der certo e 0 caso contrário */
int pop(Pilha *pilha) { 
  if(empty(pilha) == 1) return 0;
  pilha->topo--; 
  return 1;

}
/* Retorna o símbolo do topo pilha, ou \0 caso contrário */

char top(Pilha *pilha) {
  if(empty(pilha) == 1) return '\0';
  return ((pilha->elementos)[pilha->topo]);
}
/* Retorna o tamanho da pilha */ 
int size(Pilha *pilha) {
  return (pilha -> tamanho);
}

int empty(Pilha *pilha) { /* Retorna 1 se a pilha estiver vazia e 0 caso contrário */ 
  if(pilha->topo == -1){
    return 1;
  } return 0;
}