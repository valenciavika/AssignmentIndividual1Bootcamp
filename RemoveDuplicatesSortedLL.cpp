#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

struct Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=NULL;
  return newNode;
}

void push(Node **Neww, int data){
  Node *temp = createNode(data);
  temp->next= *Neww;
  *Neww=temp;
}

void removeDup(Node *Head){
  Node *cur = Head;
  Node *next2;

  if(cur==NULL)return;//tidak ada data
  
  while(cur->next!=NULL){
    if(cur->next->data == cur->data){//jika data sama dengan data selanjutnya
      next2=cur->next->next;//simpan data selanjutnya yang kedua di variabel next2
      free(cur->next);//free atau hilangkan si data selanjutnya yang sama
      cur->next=next2;//data selanjutnya menjadi dua data didepan data yang sudah disimpan di next2
    }
    else{
      cur= cur->next; //lanjut ke data selanjutnya jika beda
    }
  }
}

void Print(Node *Neww){
  while(Neww!=NULL){
    printf("%d->", Neww->data);
    Neww= Neww->next;
  }
  printf("NULL\n");
}

int main(){
  Node *newData = NULL;

  push(&newData, 7);
  push(&newData, 7);
  push(&newData, 6);
  push(&newData, 4);
  push(&newData, 3);
  push(&newData, 3);
  Print(newData);
  removeDup(newData);
  Print(newData);

  return 0;
}