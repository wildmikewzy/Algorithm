#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(int a,int b){
    return a>b;
}
int Optimal_Merge_Pattern(vector<int> x){
    int ans=0;
    while(x.size()!=1){
        int temporary;
        temporary=*(x.end()-1);
        x.pop_back();
        *(x.end()-1)+=temporary;
        ans+=*(x.end()-1);
        sort(x.begin(),x.end(),comp);
    }
    return ans;
}
int main()
{
    vector<int> x={20,10,5,30,30};
    sort(x.begin(),x.end(),comp);
    cout<<Optimal_Merge_Pattern(x)<<endl;
    return 0;
}