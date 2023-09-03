//find the minimum edge which is connected!
#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=1e3+1;

class Graph{
public:
    map<int,vector<int>> adj;
    void addEdge(int u,int v){  //add u to v
        adj[u].push_back(v);
    }
    void createGraph(bool *a,int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(a[i*(n+1)+j])
                    addEdge(i,j);
        }
    }
};
class vertex{
public:
    int weight;
    bool state;
};
vertex Edge[maxn][maxn];
void initial(){
    Edge[1][6].weight=10;
    Edge[1][2].weight=28;
    Edge[2][1].weight=28;
    Edge[2][3].weight=16;
    Edge[2][7].weight=14;
    Edge[3][2].weight=16;
    Edge[3][4].weight=12; 
    Edge[4][3].weight=12;
    Edge[4][5].weight=22;
    Edge[4][7].weight=18;
    Edge[5][4].weight=22;
    Edge[5][6].weight=25;
    Edge[5][7].weight=24;
    Edge[6][1].weight=10;
    Edge[6][5].weight=25;
    Edge[7][5].weight=24;
    Edge[7][2].weight=14;
    Edge[7][4].weight=18;
}
void Prim(Graph G,set<int> &newGraph,vector<int> &answer,int remain){
    while(remain--){
        vector<pair<int,int>> temporary1;
        vector<int> temporary2;
        for(auto m:newGraph){
            for(auto n:G.adj[m]){
                if(Edge[m][n].state==false){
                    temporary1.push_back(make_pair(m,n));
                    temporary2.push_back(Edge[m][n].weight);
                }
            }
        }
        int minu=1e6;
        int index=0;
        for(int i=0;i<temporary2.size();i++){
        
            if(temporary2[i]<minu){
                minu=temporary2[i];
                index=i;
            }
        }
        answer.push_back(minu);
        Edge[temporary1[index].first][temporary1[index].second].state=true;
        Edge[temporary1[index].second][temporary1[index].first].state=true;
        newGraph.insert(temporary1[index].first);
        newGraph.insert(temporary1[index].second);
    }
}
int main()
{
    initial();
    bool a[]={
        0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,1,0,
        0,1,0,1,0,0,0,1,
        0,0,1,0,1,0,0,0,
        0,0,0,1,0,1,0,1,
        0,0,0,0,1,0,1,1,
        0,1,0,0,0,1,0,0,
        0,0,1,0,1,1,0,0
    };
    Graph G;
    int minu=1e6;
    int root,node;
    G.createGraph(a,7);
    for(int i=1;i<=7;i++){
        for(auto &m:G.adj[i])
        {
            if(Edge[i][m].weight<minu){
                minu=Edge[i][m].weight;
                root=i;
                node=m;
            }
        }       
    }
    set<int> newGraph;
    vector<int> answer;
    newGraph.insert(root);
    newGraph.insert(node);
    answer.push_back(minu);
    Edge[root][node].state=true;
    Edge[node][root].state=true;
    int remain=7-2;
    Prim(G,newGraph,answer,remain);
    for(auto &m:answer)
        cout<<m<<" ";
    cout<<endl;
    
    return 0;
}