#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  int flag;
  struct Node *next;
};

Node *createNode(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data=data;
  newNode->flag=0;
  newNode->next=NULL;
  return newNode;
}

void push(Node **Neww, int data){
  Node *temp = createNode(data);
  temp->next = *Neww;
  *Neww = temp;
}

bool loop(Node *neww){
  while(neww!=NULL){
    if(neww->flag==1){
      return true;
    }
    neww->flag=1;//jika sudah pernah dikunjungi atau dilihat
    neww=neww->next;
  }
  return false;
}

int main(){
  struct Node *dataa = NULL;

  push(&dataa, 10);
  push(&dataa, 20);
  push(&dataa, 100);
  push(&dataa, 52);

  dataa->next->next->next->next=dataa;//this is for the cycle
  if(loop(dataa)==true){
    printf("There is a cycle\n");
  }
  else{
    printf("There is no cycle\n");
  }



  return 0;
}