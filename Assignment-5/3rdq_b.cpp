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
cout << "Node with data " << data << " successfully added." << endl;
}
void display (void){//displaying data
    node *tmp = head; 
    while(tmp !=NULL){ 
        cout<<(tmp->data)<<" -> "; 
        tmp = tmp->next;//traversing linked list
         } 
         cout<<"NULL\n";
          }
};

class bubblesort{
    public:
   void sort(node *h){
       
      for(node*i = h;i!=NULL;){
           for(node*j = h;j->next!=NULL;){
               if((j->data) > j->next->data){
                   int t = j->next->data;
                    j->next->data = j->data;
                    j->data = t;
               }j=j->next;
           }i=i->next;
       }return;
   }
};
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
    return (i->next);
}

    void qsort(node* head,node* tail){
       
        if(head!=tail){
           
            node *p =part(head,tail);
           
            qsort(head,p);
           
            qsort((p->next),tail);
        }
    }
};
int main(){
    int x;
    cout<<"Enter size";
    cin>>x;
    linked_list ll1;
    clock_t bs,be,qs,qe;
    bubblesort c;
    quicksort d;
    int i=0;
    while(i<x){
        ll1.insert(rand() % x);
        i++;
    }
    bs = clock();
    c.sort(ll1.head);
    be = clock();
    double bt =(double) (be-bs)/CLOCKS_PER_SEC;
    qs = clock();
    d.qsort(ll1.head,ll1.tail);
    qe = clock();
    double qt = (double)(qe-qs)/CLOCKS_PER_SEC;
    cout<<" bt is "<<bt<<endl;
    cout<<"qt is "<<qt<<endl; 
    return 0;
}