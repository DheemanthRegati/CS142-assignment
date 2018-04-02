#include <iostream>//NOT FIGURED OUT DELETE YET!!!
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
        cout << val <<" present!" << endl;}
      if (curr != NULL){
        if (val > curr->data){
          bsearch(curr->right,val);}
        if (val < curr->data) {
          bsearch(curr->left,val);}
        if (val == curr->data){
          cout << val << " present!"<< endl;}
      }
      else{
        cout << val << " absent!" << endl;}
    }
    return curr;
  }
  void deleteN(int key){
    node* temp = bsearch(root,key);
    if(temp->left==NULL && temp->right==NULL){
      if(temp->parent->left == temp){
        temp->parent->left = NULL;
      }
      else{
        temp->parent->right = NULL;
      }
    }
    else if(temp->left==NULL && temp->right!=NULL){
      if(temp->parent->left == temp){
        temp->right->parent = temp->parent;
        temp->parent->left = temp->right;
      }
      else{
        temp->right->parent = temp->parent;
        temp->parent->right = temp->right;
      }
    }
    else if(temp->left!=NULL && temp->right==NULL){
      if(temp->parent->left == temp){
        temp->left->parent = temp->parent;
        temp->parent->left = temp->left;
      }
      else{
        temp->left->parent = temp->parent;
        temp->parent->right = temp->left;
      }
    }
    else{
      node *p = temp->left;
      while(p->right != NULL){
        p=p->right;
      }
      int t = p->data;
      p->data = temp->data;
      temp->data= t;
      if(p->left != NULL){
        p->left->parent = p->parent;
      }
      p->parent->right=p->left;
    }
  }

};


int main(){
  BST bst;
  int a;
  while(true){//user interface
        cout<<"insert-1\n display -2\n search-3\n delete-4\n exit-5\n";
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
        }
        else if(a==4){
          int b;
          cout<<"element to delete?";
          cin>>b;
          bst.deleteN(b);
        }
        else if(a==5){
            return 0;
            }
        }
}