#include<iostream>
using namespace std;

// Node of a linked list. 

class node{
public:
	int data;
	node *next; // Pointer to next node
};

class queue{
	node *head;
    node *tail;

public:
	queue(){
		head = NULL;
        tail = NULL;
	}
	void inqueue(int value){
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
        if (head!=NULL){
            tail->next = temp;
        }
        else{
        head = temp;
        }
        tail = temp;
	}
	void dequeue(){
        if(head == NULL){
            cout<<"Queue doesn't exist";
        }
        else{
            head = head->next;
        }
	}
	void show(){
		node *curr = head;
		while (curr!=NULL){
			cout << curr->data << "->" ;
			curr = curr->next;
		}
		cout << "NULL" <<endl;
    
	}
};

int main(){
 queue s;
    int choice;
    int x;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tQueue USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY QUEUE\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                s.inqueue(x);
                break;
            case 2:
                s.dequeue();
                break;
            case 3:
                s.show();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"\nPlease enter correct choice(1-4)!!";
                break;
        }

    }
    return 0;
}