//use heapify to create heap
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int parent(int i){
    return i%2==0? i/2-1:i/2;
}
int leftChild(int i){
    return i*2+1;
}
int rightChild(int i){
    return i*2+2;
}
void heapify(int *a,int i,int size){
    if(rightChild(i)>size-1 || leftChild(i)>size-1)
        return;
    else{
        int maxindex=i;
        if(a[leftChild(i)]>a[maxindex])
            maxindex=leftChild(i);
        if(a[rightChild(i)]>a[maxindex])
            maxindex=rightChild(i);
        if(maxindex!=i){
            std::swap(a[i],a[maxindex]);
        heapify(a,maxindex,size);
        }
    }
    
}
void makeHeap(int *a,int size){
    for(int i=(size-1)/2;i>=0;i--){
        heapify(a,i,size);
    }
}
int main(int argc, char const *argv[])
{
    int a[]={10,20,15,30,40};   //{40,30,15,10,20};
    int size=5;
    makeHeap(a,size);
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
