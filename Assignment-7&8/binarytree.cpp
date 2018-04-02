#include <iostream>//NOT FIGURED OUT DELETE YET!!!
using namespace std;

struct node                         

{   int data;
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
          tree->right = temp;}
      }
      if (temp->data < tree->data){
        if (tree->left != NULL){
        insert(tree->left,temp->data);}
        else{
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
  void bsearch(node *curr,int val){      
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
  }

};


int main(){
  BST bst;
  int a;
  while(true){//user interface
        cout<<"insert-1\n display -2\n search-3\n exit-4\n";
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
            bst.bsearch(root,b);
        }
        else if(a==4){
            return 0;
            }
        }
}