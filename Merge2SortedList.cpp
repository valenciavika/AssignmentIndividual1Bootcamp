#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
} *newdata, *tail;

Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode -> data = data;
  newNode -> next = NULL;
  return newNode;
}

void push(Node **neww, int data){//memasukkan data ke dalam struct tertentu
  Node *temp = createNode(data);
  temp->next = *neww;
  *neww = temp;
}

void printList(Node *list){//print list
  while(list){
    printf("%d -> ", list->data);
    list=list->next;
  }
  printf("NULL\n");
}

struct Node *sorted(struct Node *l1, struct Node *l2){
  if(!l1)return l2;//jika tidak ada l1 maka langsung saja l2
  if(!l2)return l1;//jika tidak ada l2 maka langsung saja l1

  if(l1->data < l2->data){//jika l1 lebih kecil dari l2
    newdata = l1;//newdata diisi dengan l1
  }
  else{//sebaliknya
    newdata = l2; //diswap
    l2=l1;
    l1= newdata; 
  }

  while(l1->next && l2){//l1nya lanjut dan l2 mentok (?)
    if(l1->next->data > l2->data){//jika besaran l1 entah yang mana
      Node *tmp = l1->next; //swap
      l1->next = l2;
      l2 = tmp; 
    }
   
    l1 = l1->next;//l1nya dimajuin/digerakkan kedepan
  } 
  if (!l1->next) l1->next = l2;//jika l1 habis, maka dilanjutkan l2
  return newdata;
}

int main(){
        Node * L1 = NULL;
        Node * L2 = NULL;
        Node * result = NULL;
        
        push(&L1,5);
        push(&L1,3);
        push(&L1,2);
        push(&L1,1);
     
       
        push(&L2,7);
        push(&L2,6);
        push(&L2,4);
  
        result = sorted(L1,L2); 
        printList(result);
  
        return 0;
}