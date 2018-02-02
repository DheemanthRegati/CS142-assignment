#include<iostream>
using namespace std;

// Node of a linked list. 

class node{
public:
	int data;
	node *next; // Pointer to next node
};

class stack{
    public:
	node *top;

public:
	stack(){
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

class queue{
    stack s1,s2;
    public:
    void enqueue(int d){
        s1.push(d);
    }
   void dequeue(){
       if((s1.top)->data == NULL){
           cout<<"Nothing in queue";
       }
       else{
           while((s1.top->data)!=NULL){
               s2.push(s1.top->data);
               s1.pop();
           }
           s2.pop();
           while((s2.top->data)!=NULL){
               s1.push(s2.top->data);
               s2.pop();
           }
       }
   }
   void displayQueue(){
       if(s1.top->data==NULL){
           cout<<"Nothing in queue";
       }
       else{
           while((s1.top->data)!=NULL){
               s2.push(s1.top->data);
               s1.pop();
           }
           s2.pop();
           while((s2.top->data)!=NULL){
               cout<<s2.top->data;
               s1.push(s2.top->data);
               s2.pop();
           }
       }
   }
};
int main(){
 queue s;
    int choice;
    int x;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tQueue USING two stacks\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY QUEUE\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout << "Enter the number to push:";
            	cin >> x;
                s.enqueue(x);
                break;
            case 2:
                s.dequeue();
                break;
            case 3:
                s.displayQueue();
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