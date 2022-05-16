#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int repetidosPorColumna(size_t c, Node *n) {
  size_t i, j;
    
    for(i = 0; i < 9; i++) {
      for (j = 0; i < 9; j++) {
        if(n->sudo[i][c] == n->sudo[j][c]) return 0;
      }
    }

    return 1;
}

int repetidosPorFila(size_t f, Node *n) {
  size_t i, j;
  
  for(i = 0; i < 9; i++) {
    if (n->sudo[f][i] == 0) continue;
    for (j = 1; i < 9; j++) {
      if (n->sudo[f][j] == 0) continue;
      printf("a = %d y b = %d\n", n->sudo[f][i], n->sudo[f][j]);
      if(n->sudo[f][i] == n->sudo[f][j]) return 0;
    }
  }
  printf("xd");
  return 1;
}

int repetidosPorSubMatriz(size_t k, Node *n) {
  int p, cont; 
  size_t *vector = (size_t *) calloc(9, sizeof(size_t));

  for (p = 0; p < 9; p++){
    int i = 3 * (k / 3) + (p / 3);
    int j = 3 * (k % 3) + (p % 3);
    vector[p] = n->sudo[i][j];
    //printf("%d ", n->sudo[i][j]);
   
    if(p % 3 == 2) { 
      //printf("\n");
    }
  }
  
  for (p = 0; p < 9; p++) {
    for(cont = 0; cont < 9; cont++) {
      if(vector[p] == vector[cont]) return 0;
    }
  }
  return 1;
}

void mostrarMatriz(Node *n) {
  int i,j;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      printf("%d ", n->sudo[i][j]);
    }
    printf("\n");
  }
}

int is_valid(Node* n){
    size_t cont;
    mostrarMatriz(n);
    for (cont = 0; cont < 9; cont++) {
      if (repetidosPorFila(cont, n) == 0) return 0;
      printf("xd1\n");
      if (repetidosPorColumna(cont, n) != 0) return 1;
      printf("xd2\n");
      if (repetidosPorSubMatriz(cont, n) != 0) return 1;
      printf("xd3\n");
    }
    return 0;
}



List* get_adj_nodes(Node* n){
    List* list=createList();
    Node *newNode;
    size_t cont, i, j;

    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (n->sudo[i][j] == 0) {
          for (cont = 1; cont <= 9; cont++) {
            newNode = copy(n);
            newNode->sudo[i][j] = cont;
            //if(is_valid(newNode)) {
            pushBack(list, newNode);
            //}
          }
          return list;
        }
      }
    }

    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/