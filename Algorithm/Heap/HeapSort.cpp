//Heap Sort
#include<iostream>
#include<cstdio>
#include<vector>
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
void adjust(vector<int> &answer,int pos){
    while(answer[parent(pos)] <answer[pos]){
            std::swap(answer[parent(pos)],answer[pos]);
            pos=parent(pos);
            if(pos==0)
                break;
    }
}
vector<int> CreateHeap(int *a,int size){    //successful
    vector<int> answer;
    for(int i=0;i<size;i++){
        answer.push_back(a[i]);
        adjust(answer,i);
    }
    return answer;
}
void Delete(vector<int> &Heap){     //successful
    int size=Heap.size()-1;
    while(size>0){
        swap(Heap[0],Heap[size]);
        size--;
        for(int i=size;i>0;i--){
            adjust(Heap,i);
        }
    }
}
vector<int>  HeapSort(int *a,int size){
    vector<int> answer;
    answer=CreateHeap(a,size);
    Delete(answer);
    return answer;
}
int main()
{
    int a[]={10,20,15,30,40};   //{40,30,15,10,20};
    vector<int> answer=HeapSort(a,5);
    for(auto m:answer)
        cout<<m<<" ";
    cout<<endl;
    return 0;
}