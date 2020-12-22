#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  Node *next;
};

Node *createNode(int data){
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

Node *Last(Node *Neww, int search){
  int count=0;

  Node *cur=Neww;
  while(cur!=NULL){
    count++;//untuk menghitung banyak data
    cur=cur->next;
  }

  if(count>=search){
    cur=Neww;//dari awal lagi;
    int i=0;
    // 1 2 3 4 5 
    //5 data, search data ke 2 dari belakang
    //berarti data indeks ke 3 dari depan
    //count-search;
    while(i<count-search){
      cur= cur->next;
      i++;
    }
  }

  return cur;
}

void Print (Node *Neww){
  while(Neww!=NULL){
    printf("%d->", Neww->data);
    Neww=Neww->next;
  }
  printf("NULL\n");
}

int main(){
  Node *newData=NULL;

  push(&newData, 9);
  push(&newData, 5);
  push(&newData, 63);
  push(&newData, 4);
  push(&newData, 31);
  push(&newData, 21);
  Print(newData);
  
  int k;
  printf("n :");
  scanf("%d", &k);
  getchar();

  Node *node = Last(newData, k);
  
  if(node!=NULL){
    printf("The %d element from the last is %d\n", k, node->data);
  }

  return 0;
}