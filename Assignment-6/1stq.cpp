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
    int x;
    cout<<"Enter length";
    cin>>x;
    int b[x];
    for(int i=0;i<x;i++){
        b[i]= i;
    }
    cout<<"choose key";
    int key;
    cin>>key;
    int ans=bsearch(b,0,x-1,key);
    cout<<ans;
    return 0;
}