#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 6
typedef struct node{
  int data;
  node * next;
}node;
node *h;

// create copies of a list
node* copy(node* p) {
    node* begin = NULL;
    node* end = NULL;

    while (p) {
        node* aux = (node*) malloc(sizeof(node));
        aux->data = p->data;
        aux->next = NULL;

        if (end) end->next = aux;
        else begin = aux;

        end = aux;
        p = p->next;
    }
    return begin;
}

void insert(int x,int n){
    node *t1;
    t1=(node*)malloc(sizeof(node));
    t1->data=x;
    if(n==1){
      t1->next=h;
      h=t1;
      return;
    }
    else{
      node *t2;
      t2=h;
      for(int i=0;i<n-2;i++){
          t2=t2->next;
      }
      t1->next=t2->next;
      t2->next=t1;
      return;
    }
}
void finsert(int x,int item){
  node *p=h;
  node *t1=(node*)malloc(sizeof(node));
  t1->data=x;
  while(p->data!=item){
    p=p->next;
  }
  t1->next=p->next;
  p->next=t1;
  return;
}
void print(){
    node *t=h;
    while(t!=NULL){
      cout<<t->data<<" ";
      t=t->next;
    }
    cout<<"\n";
    return; 
}
int main(){
    h=NULL;
    insert(23,1);
    insert(22,2);
    insert(21,3);
    insert(24,4);
    insert(49,1);
    finsert(23,22);
    print();


  return 0;
}

