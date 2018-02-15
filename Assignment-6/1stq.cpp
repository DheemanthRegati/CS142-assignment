#include<iostream>
using namespace std;
int bsearch(int arr[],int l,int h,int k){
    int m=(l+h)/2;
    if(k<arr[l]||k>arr[h]){
        return -1;
    }
    if(arr[m]==k){
        return m;
    }
    else if(arr[m]>k){
        bsearch(arr,0,(m-1),k);
    }
    else if(arr[m]<k){
        bsearch(arr,m+1,h,k);
    }
    else{
        return -1;
    }
}

int main(){
    int b[5]={1,2,3,4,5};
    cout<<"choose key";
    int key;
    cin>>key;
    int ans=bsearch(b,0,4,key);
    cout<<ans;
    return 0;
}