#include<iostream>
using namespace std;

class quicksort{
    public:
    int part(int arr[],int low,int high){
         int pivot = arr[high];   
        int i = (low - 1);  
 
        for (int j = low; j <= high- 1; j++)
        {
         if (arr[j] <= pivot)
            {
                i++;
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
         }
     }
                int t=arr[i+1];
                arr[i+1]=arr[high];
                arr[high]=t;
    return (i + 1);
}

    void sort(int a[],int l, int h){
        if(l<h){
            int p=part(a,l,h);
            sort(a,l,(p-1));
            sort(a,(p+1),h); 
        }
    }
};

int main(){
    int x;
    cout<<"Enter size";
    cin>>x;
    int b[x];
    quicksort c;
    for(int i=0;i<x;i++){
        b[i]= rand() % x ;
        cout<<b[i]<<"  ";
    }
    c.sort(b,0,x-1);
    for(int i=0;i<x;i++){
        cout<<b[i];
    }
    return 0;
}