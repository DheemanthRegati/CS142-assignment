#include <iostream>
using namespace std;

struct node                         

{   int data;
    struct node *parent;
    struct node *left;
    struct node *right;

}*root;

class BST{
  public:
  BST(){
  root = NULL;}
  
  void insert(node *tree, int a){
    node *temp = new node;
    temp->data = a;
    temp->parent = NULL;
    temp->right = NULL;              
    temp->left = NULL;
    if (root == NULL){
      root=temp;
    }
    if (tree != NULL){               
      if (temp->data > tree->data){
        if (tree->right != NULL){
          insert(tree->right,temp->data);}
        else{
          temp->parent = tree;
          tree->right = temp;}
      }
      if (temp->data < tree->data){
        if (tree->left != NULL){
        insert(tree->left,temp->data);}
        else{
          temp->parent = tree;
        tree->left = temp;}
        
      }
      if (temp->data == tree->data){
        cout << "node exists already";
      }
    }

  }

  void display(node *curr){        
    if (root == NULL){
      cout << "tree is empty"<<endl; 
    }
    if(curr != NULL){
      display(curr->left);
      cout << curr->data << " ";
      display(curr->right);}

  }
  node* bsearch(node *curr,int val){      
    if (root != NULL){
      if (root->data == val){
        cout << val <<" present!" << endl;
        return root;
      }}
      if (curr != NULL){
        if (val > curr->data){
          curr = bsearch(curr->right,val);}
        else if (val < curr->data) {
          curr = bsearch(curr->left,val);}
        else if (val == curr->data){
          cout << val << " present!"<< endl;
	}
      }
      else{
        cout << val << " absent!" << endl;
	return NULL;}
	return curr;}
  void deleteN(int key){
    node* temp = bsearch(root,key);
    if(temp==NULL){cout<<"no such element";
	return;}
    if(temp->left==NULL && temp->right==NULL){
	if(temp==root){
	    root=NULL;
	    return;}
        if(temp->parent->left == temp){ //
            temp->parent->left = NULL;}
        else{
            temp->parent->right = NULL;}
	}
    else if(temp->left==NULL && temp->right!=NULL){
	if(temp==root){
	    root=root->right;
	    return;}
        if(temp->parent->left == temp) {
            temp->right->parent = temp->parent;
            temp->parent->left = temp->right;
        }
        else {
            temp->right->parent = temp->parent;
            temp->parent->right = temp->right;
        }
    }
    else if(temp->left!=NULL && temp->right==NULL){
	if(temp==root){
	    root=root->left;
	    return;}
        if(temp->parent->left == temp) {
            temp->left->parent = temp->parent;
            temp->parent->left = temp->left;
        }
        else {
            temp->left->parent = temp->parent;
            temp->parent->right = temp->left;
        }
    }
   else {
        node *p = temp->left;
        while(p->right != NULL){
            p=p->right;
        }
        int t = p->data;
        p->data = temp->data;
        temp->data= t;
        if(p->left != NULL){
            p->left->parent = p->parent;
            p->parent->right=p->left;        
	}
	//  Special case for leaf
	else{
	    if(p->parent->left==p){
	        p->parent->left=NULL;}
	    else{
		p->parent->right=NULL;}
	}
        return;
    }
  }
  int c=0;
  void count(node* temp){
      if (temp!=NULL) {
          count(temp->left);
          c++;       
          count(temp->right);
      }
  }
  int d=0;
    void rangedisplay(node *curr,int l,int m){        
    if (root == NULL){
      cout << "tree is empty"<<endl; 
    }
    if(curr != NULL){
      rangedisplay(curr->left,l,m);
      if(curr->data>(l-1)&&curr->data<(m+1)){
          cout << curr->data << " ";
          d++;
      }
      rangedisplay(curr->right,l,m);}
  }

};


int main(){
  BST bst;
  int a;
  while(true){//user interface
        cout<<"insert-1\n display -2\n search-3\n delete-4\n count-5\n rangesearch-6\n exit\n";
        cin>>a;
        if(a==1){
            int b;
            cout<<"data?";
            cin>>b;
            bst.insert(root,b);
        }
        else if(a==2){
            bst.display(root);
        }
        else if(a==3){
            int b;
            cout<<"element to search?";
            cin>>b;
            node*p = new node;
            p = bst.bsearch(root,b);
	    if(p==NULL){
		cout<<"NULL";}
        }
        else if(a==4){
          int b;
          cout<<"element to delete?";
          cin>>b;
          bst.deleteN(b);
        }
        else if(a==5){
            bst.count(root);
            cout << "c = " << bst.c;
            }
        else if(a==6){
            int f,g;
            cout<<"enter minimum of range";
            cin>>f;
            cout<<"enter maximum of range";
            cin>>g;
            bst.rangedisplay(root,f,g);
            cout<<"total elements in range "<<bst.d;
        }
        else{
            return 0;
        }
        }
}
