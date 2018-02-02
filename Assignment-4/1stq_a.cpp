#include<iostream>
using namespace std;

// Node of a linked list. 

class node{
public:
	int data;
	node *next; // Pointer to next node
};

class StackLL{
	node *top;

public:
	StackLL(){
		top =NULL;
	}
	void push(int value){
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if(top!=NULL){
			temp->next = top;
		}
		top = temp;
	}
	void pop(){
        if(top == NULL){
            cout<<"Nothing to pop\n";
        }
        else{
            top = top->next;
        }
    }   

	void show(){
		node *curr = top;
		while (curr!=NULL){
			cout << curr->data << "->" ;
			curr = curr->next;
		}
		cout << "NULL" <<endl;
	}
};

int main(){
 StackLL s;
    int choice;
    int x;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tStack USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY Stack\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                s.push(x);
                break;
            case 2:
                s.pop();
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