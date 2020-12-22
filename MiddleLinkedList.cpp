#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void Middle(struct Node *neww){
  int count=0;
  struct Node *mid = neww;

  while(neww->next!=NULL){
    if(count%2==1){//setiap count ganjil
      mid= mid->next;//jadi ceritanya kan si count yang ganjil ini adalah setengah dari banyaknya node neww
      //jadi dia midnya bertambah sebanyak setengah dri jumlah neww dan artinya mid ini nantinya akan ada ditengah
      //tapi jika genap, dia ambil midnya yang sebelah kiri 
    }
    count++;
    neww= neww->next;
  }
  if(mid!=NULL){
    printf("Mid:  %d\n", mid->data);
  }
}

struct Node *createNode(int data){
  struct Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=NULL;
  return newNode;
}

void push(struct Node **Neww, int data){
  struct Node *temp = createNode(data);
  temp->next= *Neww;
  *Neww=temp;
}

void Print(Node *Neww){
  while(Neww!=NULL){
    printf("%d->", Neww->data);
    Neww= Neww->next;
  }
  printf("NULL\n");
}
int main(){
  struct Node *neww = NULL;

  push(&neww, 10);
  push(&neww, 11);
  push(&neww, 13);
  push(&neww, 21);
  Print(neww);
  Middle(neww);


  return 0;
}