#include <stdio.h>
#include <stdlib.h>
typedef struct node {int i;struct node* next;} node; //typedef to avoid repeating struct
void print_list(node* p){ //prints with brackets
  printf("[");
  while(p->next){
    printf("%i, ",p->i);
    p = p->next;
  }
  printf("%i]\n\n",p->i);
}
node* insert_front(node* p, int i){
  node* newp = malloc(sizeof(node));
  newp->i = i;
  newp->next = p;
  return newp;
}
node* free_list(node* p) {//frees each node until ptr goes to null
  while(p!=NULL){
    node* temp = p;
    free(temp);
    p = p->next;
    //p!=NULL ? print_list(p) : "(null)";
  }
  return p;
}
int main(){
  node* list = malloc(sizeof(node));list->i = 1;list->next = NULL; //original linked list node with value as int 1
  printf("Initial list with 1 value:\n\n");print_list(list);
  int i;
  for(int i = 2; i <= 20; i++){list = insert_front(list,i);}
  printf("Updated list with 19 integers appended to front: \n\n");print_list(list);
  free_list(list);
  printf("What head pointer points to after freeing list:\n\n %s\n\n",*list);
return 0;
}