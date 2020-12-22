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

void descending(Node **Neww){
  Node *cur = *Neww;//menandakan current yaitu di head
  Node *Next = NULL;
  Node *prev = NULL;

  while(cur!=NULL){
    // NULL  <- 1  ->   2   ->   3   ->   4   ->  NULL
    //                 next
    //       cur
    //prev
    Next = cur->next;
    cur->next = prev;// disini dia akan berubah arah

    prev=cur;
    cur= Next;
  }

  *Neww=prev;//neww ini adalah headnya, jadi prevnya sudah dibagian tail sehingga headnya mulainya dari tail.
}


void Print (Node *Neww){
  while(Neww!=NULL){
    printf("%d->", Neww->data);
    Neww=Neww->next;
  }
  printf("NULL\n");
}

int main(){
  Node *newData = NULL;

  push(&newData, 33);
  push(&newData, 21);
  push(&newData, 20);
  push(&newData, 17);
  push(&newData, 5);
  push(&newData, 4);
  Print(newData);
  descending(&newData);
  Print(newData);

  return 0;
}