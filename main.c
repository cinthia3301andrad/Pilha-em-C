#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pilha.h"

int testa_cria_pilha() {
  int tamanho;
  scanf("%d", &tamanho);
  
  Pilha *pilha = NULL;
  
  pilha = nova(tamanho);
  
  if(pilha != NULL && size(pilha) == tamanho) {
    return 1;
  } else {
    return -1;
  }
}

int testa_libera_pilha() {
  int tamanho;
  scanf("%d", &tamanho);
    if(tamanho<=0) return -1;
  Pilha *pilha = NULL;
  
  pilha = nova(tamanho);
  
  libera(&pilha);
  
  if(pilha == NULL) {
    return 1;
  } else {
    return -1;
  }
}

int testa_push_pilha() {
  int tamanho;
  scanf("%d", &tamanho);
  
  Pilha *pilha = NULL;
  
  pilha = nova(tamanho);
  
  int quantidade;
  
  scanf("%d", &quantidade);
  if(quantidade>tamanho) return -1;
  
  char simbolo;
  
  for(int i = 0; i < quantidade; i++) {
    scanf("%c", &simbolo);
    if(push(pilha, simbolo) == 0) {
        return -1;
    }
  }
  
  if(quantidade > 0 && empty(pilha) == 1) {
    return -1;
  } else if(quantidade==0 && empty(pilha) == 0){
    return -1;
  }

  return 1;
}

int testa_pop_pilha() {
  int tamanho;
  scanf("%d", &tamanho);
  
  Pilha *pilha = NULL;
  
  pilha = nova(tamanho);
  
  int quantidade;
  
  scanf("%d", &quantidade);
  
  if(quantidade>tamanho) return -1;
  
  char simbolo;
  
  for(int i = 0; i < quantidade; i++) {
    scanf("%c", &simbolo);
    push(pilha, simbolo);
  }
  
  for(int i = 0; i < quantidade; i++) {
    if(pop(pilha) == 0) {
      return -1;
    }
  }
  
  if(!empty(pilha) ) {
    return -1;
  }

  return 1;
}

int testa_top_pilha() {
  int tamanho;
  scanf("%d", &tamanho);
  
  Pilha *pilha = NULL;
  
  pilha = nova(tamanho);
  
  int quantidade;
  
  scanf("%d", &quantidade);
  
  char simbolo = '\0';
  
  for(int i = 0; i < quantidade; i++) {
    scanf("%c", &simbolo);
    push(pilha, simbolo);
  }
  
  if(top(pilha) != simbolo) {
    return -1;
  }
  
  return 1;
}
int testa_validade_expressao(char *expressao) {
  int n = 0;
  
  while(expressao[n]) n++;
  Pilha *pilha = nova(n);
  for(int i=0; i < n ; i++){
    switch(expressao[i]){
      case '(' : push(pilha, expressao[i]);
          break;
      case '{' : push(pilha, expressao[i]);
          break;
      case '[' : push(pilha, expressao[i]);
          break;
      case ')' : if(top(pilha)=='(') pop(pilha); 
                 else {return -1;}
                 break;
      case '}' : if(top(pilha)=='{') pop(pilha);
                 else {return -1;}
                 break;
      case ']' : if(top(pilha)=='[') pop(pilha);
                 else {return -1;}
                 break;
    }
  }
    if(empty(pilha)) return 1;
    else{return -1;}
}
void run_suite_teste() {
  int op;
  char expressao[30];
  scanf("%d", &op);
  
  switch(op) {
  
    case 1: printf("%d", testa_cria_pilha());
            break;
            
    case 2: printf("%d", testa_libera_pilha());
            break;
            
    case 3: printf("%d", testa_push_pilha());
            break;
            
    case 4: printf("%d", testa_top_pilha());
            break;
            
    case 5: printf("%d", testa_pop_pilha());
            break;
            
    case 6: scanf("%s", expressao);
            printf("%d", testa_validade_expressao(expressao));
            break;
  
  }
}


int main(void) {
  run_suite_teste();
	return 0;
}