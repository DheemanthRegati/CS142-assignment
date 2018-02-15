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

    void qsort(int a[],int l, int h){
        if(l<h){
            int p=part(a,l,h);
            qsort(a,l,(p-1));
            qsort(a,(p+1),h); 
        }
    }
};


int main(){
    int x;
    cout<<"Enter size";
    cin>>x;
    int b[x];ala
    bubblesort c;
    quicksort d;
    clock_t bs,be,qs,qe;
    for(int i=0;i<x;i++){
        b[i]= rand() % x ;
         cout<<b[i]<<"  ";
    }
    bs = clock();
    c.sort(b,x);
    be = clock();
    /*for(int i=0;i<x;i++){
        cout<<b[i];
    }*/
    double bt =(double) (be-bs)/CLOCKS_PER_SEC;
     qs = clock();
     d.qsort(b,0,x-1);
     qe = clock();
     double qt = (double)(qe-qs)/CLOCKS_PER_SEC;
    cout<<" bt is "<<bt<<endl;
    cout<<"qt is "<<qt<<endl; 
    return 0;
}
