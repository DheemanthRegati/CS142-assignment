#include <iostream>
using namespace std;


class node
{
public:
int data;
node *next;

node() { //constructor
    data = 0;
    next = nullptr;
}
};
class linked_list
{
public:
node *head, *tail;

linked_list(){
    head = NULL;
    tail = NULL;
}

void insert (int data){//inserting nodes
    //cout<<"test n"<<endl;
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
cout << "Node with data " << data << " successfully added."<<endl;
}

void display (void){//displaying data

    cout << "\nDISPLAYING\n";
    node *tmp = head; 
    while(tmp !=NULL){ 
        cout<<(tmp->data)<<" -> "; 
        tmp = tmp->next;//traversing linked list
         } 
         cout<<"NULL\n";
          }
};
linked_list ll1;
class quicksort{
    public:
    node* part(node* h,node* t){
         node* pivot = t;   
        node* i = new node;
        i->next = h;
       
        node* j = h; 
        while((j->next)!=t)
        {
            
         if (j->data <= pivot->data)
            {
                
                i=i->next;
                int tmp=i->data;
                i->data=j->data;
                j->data=tmp;
         }
         j=(j->next);
     }
               if(t->data<i->next->data)
              {  int tmp=i->next->data;
                i->next->data=t->data;
                t->data=tmp;}
                ll1.display();
    return (i->next);
}

    void sort(node* head,node* tail){
       
        if(head!=tail){
           
            node *p =part(head,tail);
           
            sort(head,p);
           
            sort((p->next),tail);
        }
    }
};
int main(){
    int x;
    cout<<"Enter size";
    cin>>x;
    quicksort c;
    int i=0;
    while(i<x){
        ll1.insert(rand() % x);
        i++;
    }
    /*ll1.insert(4);
    ll1.insert(3);
    ll1.insert(2);
    ll1.insert(1);*/
    cout<<"input list is ";
    ll1.display();
    c.sort(ll1.head,ll1.tail);
    cout<<"too many tests 3"<<endl;
    ll1.display();
    return 0;
}