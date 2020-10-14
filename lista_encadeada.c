#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"





typedef struct No No;

//Definição do tipo lista
typedef struct lista{
    No *inicio;
    int size; // quantidade de elementos na lista 
    int sorted; // indica se a lista é ordenada 
} Lista;
//Definição do nó da lista
struct No{
  No *prox;
  struct aluno dado;
};

Lista* cria_lista(int n){
  Lista *li;

  li = (Lista*) malloc(sizeof(struct lista)); // poderia ser Lista

  if( li == NULL){
    return li;
  }
  li->size=0;
  li->sorted=n;
  li->inicio = NULL;

  return li;
}

int insere_lista_inicio(Lista* li, struct aluno al){
  if( li == NULL){
    return 0;
  }
  if( li->sorted == 1){
    return -4;
  }
  No *novo_no = (No*) malloc(sizeof(struct No));

  if(novo_no == NULL){
    return 0;
  }

  novo_no->dado = al;

  novo_no->prox = li->inicio;
  li->inicio = novo_no;
  li->size+=1;
  return 1;
}
int insere_lista_pos(Lista* li, int pos, struct aluno al)
{
  

  if (li == NULL)
    return -1;
  
  if( li->sorted == 1){
    return -4;
  }
  if ( (pos <=0) || (pos > li->size))
    return -2; // erro de posição inválida
  
  int cont=1;
  No *aux = li->inicio;
  No *novo_no = (No*) malloc(sizeof(struct No));
  novo_no->dado=al;
 
      if(aux->prox == NULL || pos  == 1)
      {
          insere_lista_inicio(li,al);
          return 0;
      }
  while(aux != NULL)
  {
     if(pos-1  == cont)
       {

          novo_no->prox = aux->prox;
          aux->prox = novo_no;
          li->size++;
          return 0;
       }
       
    cont++;
    aux = aux->prox;
  }
  
  return -2;


}
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return -1;

    if( li->sorted == 0){
    return -4;
  }
    
    No *aux = li->inicio;
  
    No *novo_no = (No*) malloc(sizeof(struct No));
    novo_no->dado=al;
     if(li->inicio == NULL )
      {
        novo_no->prox = li->inicio;
        li->inicio = novo_no;
        li->size+=1;

          return 0;
      }
    while(aux != NULL)
    {   
      
      
      if(al.matricula  > aux->dado.matricula)
       {

          novo_no->prox = aux->prox;
          aux->prox = novo_no;
          li->size++;
          return 0;
       }
    aux = aux->prox;
    }   
    li->size++;
    return 0;
 }

int insere_lista_final(Lista* li, struct aluno al){
  if( li == NULL){
    return 0;
  }
  if( li->sorted == 1){
    return -4;
  }
  No *novo_no = (No*) malloc(sizeof(struct No));

  if(novo_no == NULL){
    return 0;
  }

  novo_no->dado = al;
  novo_no->prox = NULL;

  if(li->inicio == NULL){
    li->inicio = novo_no;
    li->size++;
    return 0;
  }

  No* aux = li->inicio;
  while(aux->prox != NULL){
    aux = aux->prox;
  }

  aux->prox = novo_no;
  li->size+=1;
  return 0;
}

int remove_lista_inicio(Lista* li){
  if( li == NULL){
    return 0;
  }

  if( li->inicio == NULL ){
    return 0;
  }

  No *aux = li->inicio;

  li->inicio = aux->prox; 

  free(aux);
  li->size--;
  return 1;
}

int remove_lista_final(Lista *li){
  if( li == NULL){
    return 0;
  }

  if(li->inicio == NULL){
    return 0;
  }

  if(li->inicio->prox == NULL){
    free(li->inicio);
    li->inicio = NULL;
    return 1;
  }

  No *ant = NULL;
  No *aux = li->inicio;

  while(aux->prox != NULL){
    ant = aux;
    aux = aux->prox;
  }


  ant->prox = NULL;
  free(aux);
  li->size--;
  return 1;
}

void libera_lista(Lista* li){
  if(li == NULL){
    return;
  }

  No *aux = li->inicio;
  No *b = NULL;
  while(aux != NULL){
    b = aux;
    aux = aux->prox;
    free(b);
  }

  free(li);
}

void imprime_lista(Lista *li){
  if(li == NULL){
    return;
  }

  No *aux = li->inicio;
  printf("\n\nLista: \n");
  while(aux != NULL){
    printf("Matricula: %d\n",aux->dado.matricula);
    printf("Nome: %s\n",aux->dado.nome);
    printf("Notas: %.2f, %.2f, %.2f\n",aux->dado.n1,aux->dado.n2,aux->dado.n3);
    printf("-------------------------------\n");
    aux = aux->prox;
  }
  return;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){

  if (li == NULL)
    return -1;

  if ( (pos <=0) || (pos > li->size))
    return -2; // erro de posição inválida
  
  int cont=1;
  No *aux = li->inicio;
  while(aux != NULL)
  {
    if(pos == cont)
    {  
      *al = aux->dado;
      return 0;
    }
    cont++;
    aux = aux->prox;
  }
  
  return -3;
}
int consulta_lista_mat(Lista* li, int mat, struct aluno *al)
{
    if(li == NULL)
        return -1;
  
  No *aux = li->inicio;
  while(aux != NULL)
  {
    if(mat == aux->dado.matricula)
    {  
      *al = aux->dado;
      return 0;
    }
    
    aux = aux->prox;
  }
 
    return -2;
}
int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->size;
}
int lista_vazia(Lista* li)
{
    if(li == NULL)
        return -1;
    if(li->size == 0)
        return 0;
    return -2;
}
int lista_cheia(Lista* li)
{
    
        return false;
   
}
