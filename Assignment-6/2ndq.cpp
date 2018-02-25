#include <iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *prev;

node() { //constructor
    data = 0;
    next = nullptr;
    prev = nullptr;
}
};
class linked_list
{
public:
node *head, *tail;

linked_list() //Constructor
{
head = NULL;
tail = NULL;
}
void insert(int data);//functions in linked list
};
//definition of each function
void linked_list::insert (int data){//inserting nodes
node *tmp = new node;
tmp->data = data;
tmp->next = NULL;
tmp->prev = NULL;
if(head == NULL)
{
head = tmp;
tail = tmp;
}
else
{
tail->next = tmp;
tmp->prev = tail;
tail = tail->next;
}
}
int countItems (node* temp,node* temp2){
    int c=0;
    while(temp != temp2->next){
        temp = temp->next;
        c++;
    }
    return c;
}
    linked_list ll1;
int bsearch(node* h,node* t,int k){
    node*curr=h;
    int c=countItems(h,t);
    for(int i=1;i<(c/2);i++){
        curr=curr->next;
    }
    if(curr->data==k){
        return countItems(ll1.head,curr);
    }
    else if(curr->data>k){
        if(curr->data!=curr->prev->data+1){
            cout<<"error";
        }
        return bsearch(h,curr->prev,k);
    }
    else if(curr->data<k){
        if(curr->data!=curr->prev->data+1){
            cout<<"error";
        }
        return bsearch(curr->next,t,k);
    }
    else{
        return -1;
    }
}

int main(){
    int l;
    cout<<"enter size";
    cin>>l;
    for(int i=1;i<=l;i++){
        ll1.insert(i);
    }
    int key;
    cout<<"enter key";
    cin>>key;
    int ans=bsearch(ll1.head,ll1.tail,key);
    cout<<ans;
    return 0;
}