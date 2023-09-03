#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class Node{
public:
    char name;
    int weight;
    Node *parent;
    Node *left;
    Node *right;
    string code;
    Node(char name,int weight):name(name),weight(weight){};
};
bool comp(Node *s1,Node *s2){
    return s1->weight<s2->weight;
}
Node* Merge(Node *s1,Node *s2){
    Node *temporary;
    temporary=new Node('*',s1->weight+s2->weight);
    temporary->left=s1;
    temporary->right=s2;
    s1->parent=temporary;
    s2->parent=temporary;
    return temporary;
}
void encode(vector<Node*>&s){
    while(s.size()>1){
        std::sort(s.begin(),s.end(),comp);
        s[0]=Merge(s[0],s[1]);
        s.erase(s.begin()+1);
    }
}
void createCode(Node *it,string &code){
    
    if(it->name!='*'){
        it->code=code;
        return;
    }
    else if(it->name=='*'){
        for(int i=0;i<=1;i++){
            i==0?(it=it->left,code+='0'):(it=it->right,code+='1');
            Node *temporary=it;
            createCode(it,code);
            code.erase((code.length()-1),1);
            it=it->parent;
        }
    }
}
char decode(Node *it,string code){
    char c;
    while(code.length()!=0){
        char a=code[0];
        code.erase(0,1);
        if(a=='0')
            it=it->left;
        else
            it=it->right;
    }
    c=it->name;
    return c;
}
int main()
{
    Node a('a',1);
    Node b('b',5);
    Node c('c',6);
    Node d('d',4);
    Node e('e',2);
    vector<Node*> s={&a,&b,&c,&d,&e};
    encode(s);
    string code="";
    Node *it=*s.begin();
    createCode(it,code);
    cout<<"encoding:"<<endl;
    cout<<"a:"<<a.code<<endl;
    cout<<"b:"<<b.code<<endl;
    cout<<"c:"<<c.code<<endl;
    cout<<"d:"<<d.code<<endl;
    cout<<"e:"<<e.code<<endl;
    
    it=*s.begin();
    cout<<"decoding"<<endl;
    cout<<"000 :"<<decode(it,"000")<<endl;
    cout<<"10 :"<<decode(it,"10")<<endl;
    cout<<"11 :"<<decode(it,"11")<<endl;
    cout<<"01 :"<<decode(it,"01")<<endl;
    cout<<"001 :"<<decode(it,"001")<<endl;
    return 0;
}