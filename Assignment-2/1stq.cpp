#include <iostream>
using namespace std;
class node
{
public:
int data;
node *next;
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
    node *tmp = new node; 
    tmp->data = (head->data); 
    tmp->next = (head->next); 
    while(tmp !=NULL){ 
        cout<<(tmp->data)<<" -> "; 
        tmp = tmp->next;
         } 
         cout<<"NULL";
          }
int main(){
linked_list ll1;
ll1.insert(1);
ll1.insert(2);
ll1.insert(3);
ll1.display();
}
