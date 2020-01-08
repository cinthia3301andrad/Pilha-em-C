/* TAD: Pilha (tamanho, topo, elementos)*/ 
typedef struct pilha Pilha;

/* Aloca e retorna uma pilha de tamanho informado */ 
Pilha *nova(int tamanho);

/* Libera a memória de uma pilha previamente criada */ 
void libera(Pilha **pilha);

/* Adiciona um símbolo na pilha. Retorna 1 se der certo e 0 caso contrário */ 
int push(Pilha *pilha, char simbolo);

/* Remove um símbolo da pilha. Retorna 1 se der certo e 0 caso contrário */
int pop(Pilha *pilha);

/* Retorna o símbolo do topo pilha, ou \0 caso contrário */
char top(Pilha *pilha);

/* Retorna o tamanho da pilha */ 
int size(Pilha *pilha);

/* Retorna 1 se a pilha estiver vazia e 0 caso contrário */ 
int empty(Pilha *pilha);
