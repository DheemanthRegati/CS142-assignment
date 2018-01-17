#include <iostream>
using namespace std;
class node
{
public:
int data;
node *next;

node() {
    data = 0;
    next = nullptr;
}
};
class linked_list
{
private:
node *head,*tail;
public:
linked_list() //Constructor
{
head = NULL;
tail = NULL;
}
void insert(int data);
void display();
int countItems();
void Delete(int d);
};
void linked_list::insert (int data){
node *tmp = new node;
tmp->data = data;
tmp->next = NULL;
if(head == NULL)
{
head = tmp;
tail = tmp;
}
else
{
tail->next = tmp;
tail = tail->next;
}
cout << "Node with data " << data << " successfully added." << endl;
}
void linked_list::display (void){ 
    node *tmp = head; 
    while(tmp !=NULL){ 
        cout<<(tmp->data)<<" -> "; 
        tmp = tmp->next;
         } 
         cout<<"NULL\n";
          }

int linked_list::countItems (void){
    node *tmp = head;
    int c=0;
    while(tmp !=NULL){
        tmp = tmp->next;
        c++;
    }
    return c;
}

void linked_list::Delete (int d){
    if(d==1){
        head = NULL;
    }
    else if(d==2){
        head->next=NULL;
    }
    else {

        node *i = head;
        for ( ; i->next->next != NULL ; i = i->next);

        i->next = nullptr;
        tail = i;
    }

}

int main(){
    linked_list ll1;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    int y=ll1.countItems();
    cout<<y<<endl;
    ll1.display();
    ll1.Delete(y);
    ll1.display();
}
