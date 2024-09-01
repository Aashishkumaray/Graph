#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;
vector<list<int> > graph;
int v;//no. of vertices

//now making connection
void add_edge(int src,int des,bool bi_dir=true){
    graph[src].push_back(des);//source-to -destination
    if(bi_dir){
        graph[des].push_back(src);//if grap is bidirectinal then destination to source connection
    }
}

//for printing adjancy list of the graph
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" → ";
        for(auto ele:graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
    
}


// DFS function for cycle detection
bool dfs(int src,int parent,unordered_set<int> &vis){
    vis.insert(src);
    for(auto neighbour: graph[src]){
        if(vis.count(neighbour) and neighbour!=parent){
            //cycle detected
            return true;
        }
        if(!vis.count(neighbour)){//means neighbourv visist nahi hua toh ham  neighbour visist karenga
            bool res=dfs(neighbour,src,vis);
            if(res==true) return true;
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> vis;
    for(int i=0;i<v;i++){
        if(!vis.count(i)){//every vertex ke dfs chala rahe hai
            bool result=dfs(i,-1,vis);//true
             return true;
        }
    }
    return false;
}


int main(){
    cout<<"Enter thenumber of vertex";
    cin>>v;
    graph.resize(v, list<int> ());
    //graph.resize(v);
    int e;
    cout<<"eneter the edge";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);//// assuming it's a directed graph, so bi_dir=false
    }

    display();
    bool b= has_cycle();
    cout<<b<<"\n"<<"1 means Cycle detected";//
}

