#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Job{
    int profit;
    int deadline;
};
bool comp(Job a,Job b){
    return a.profit>b.profit;
}
void chooseTime(int x,int *time,Job *task){
    for(int i=task[x].deadline;i>=1;i--){
        if(!time[i]){
            time[i]=task[x].profit;
            return;
        }
    }
}
int main()
{
    int n;
    cout<<"The number of jobs you can do is:";
    cin>>n;
    Job task[n];
    int time[n+1];
    memset(time,0,sizeof(time));
    for(int i=0;i<n;i++){
        cin>>task[i].profit>>task[i].deadline;
    }
    std::sort(task,task+n,comp);
    for(int i=0;i<n;i++){
        chooseTime(i,time,task);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=time[i];
    }
    cout<<"The maxinum profit you can get:"<<ans<<endl;
    return 0;
}