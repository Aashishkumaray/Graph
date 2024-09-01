#include<iostream>
#include<vector>
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

//for printing
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" → ";
        for(auto ele:graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
    
}
int main(){
    cout<<"ENter thenumber of vertex";
    cin>>v;
    // graph.size(v, list<int> ());
    graph.resize(v);
    int e;
    cout<<"eneter the edge";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    display();
}