//cycle detection for  undirected Graph
// #include<iostream>
// #include<vector>
// #include<unordered_set>
// #include<list>
#include<bits/stdc++.h>
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
bool bfs(int src){
    unordered_set<int> vis;
    queue<int> q;
    vector<int> parent(v,-1);
    q.push(src);
    vis.insert(src);
    while(not q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(vis.count(neighbour) and parent[curr]!=neighbour) return true;//detect cycle
            if(!vis.count(neighbour)){//neighbour not visiste then visist
                vis.insert(neighbour);
                parent[neighbour]=curr;
                q.push(neighbour);

            }

        }
    }

}

bool has_cycle(){
    unordered_set<int> vis;
    for(int i=0;i<v;i++){
        if(!vis.count(i)){//every vertex ke dfs chala rahe hai
            bool result=bfs(i);//true
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

