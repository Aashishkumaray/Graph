//Is used to detect cycle in DAG(Directed Acyclic graph)
//Kahns Alogorithm is applicable on Directed Acyclic graph
// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>//this header is used to take all requierd header file through 1 line
using namespace std;

vector<list<int> > graph;
int v;//no ogf vertices

void add_edge(int a,int b,bool bidir=true){
    graph[a].push_back(b);//bidir is false, it adds a directed edge from a to b only. other wise in both direction
    if(bidir){//bidr is true
        graph[b].push_back(a);
    }
}

void topoBFS(){
    //Kahn Algo
    vector<int> indegree(v,0);
    //for countg indegree of each node
    for(int i=0;i<v;i++){
        for(auto neighbour:graph[i]){
            //i---> neighbour
            indegree[neighbour]++;
        }
    }
    //Applying bfs
    queue<int>qu;
    unordered_set<int> vis;//vis is an unordered set that keeps track of visited nodes to avoid processing the same node multiple times.
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qu.push(i);
            vis.insert(i);
        }
    }
    cout<<"start";
    //multisource bfs
    while(not qu.empty()){
        int node=qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neighbour:graph[node]){
            if(not vis.count(neighbour)){//not vis.count(neighbour) returns true if neighbour is not in the vis set, meaning it hasn't been processed yet.
                indegree[neighbour]--;////indegree me minus
                if(indegree[neighbour]==0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
    
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());//Resizes the graph vector to hold v vertices, each with an empty list to store connected vertices.
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    topoBFS();
}

// 1 1 0 1
// 0 1 0 1
//graph[i].push_back(j) means i->j
