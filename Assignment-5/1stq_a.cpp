#include<iostream>
using namespace std;

class bubblesort{
    public:
    void sort(int a[], int l){
        for(int i=0;i<l;i++){
            for(int j=0;j<(l-i-1);j++){
                if(a[j]>a[j+1]){
                    int t = a[j+1];
                    a[j+1] = a[j];
                    a[j] = t;
                }
            }
        }
    }
};

int main(){
    int x;
    cout<<"Enter size";
    cin>>x;
    int b[x];
    bubblesort c;
    for(int i=0;i<x;i++){
        b[i]= rand() % x ;
        cout<<b[i]<<"  ";
    }
    c.sort(b,x);
    for(int i=0;i<x;i++){
        cout<<b[i];
    }
    return 0;
}