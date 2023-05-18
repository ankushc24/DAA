#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printBFS(int **edges,int v,int sv,bool *visited){
    queue<int> q;

    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
      int current = q.front();
      q.pop();
      cout<<current<<" ";
      for (int i = 0; i < v; i++) {
        if (edges[current][i] == 1 && visited[i] == false) {
          q.push(i);
          visited[i] = true;
        }
      }
    }
    }
    void BFS(int ** edges,int v){
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            printBFS(edges,v,i,visited);
        }
    }
    }


int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
    }
    for(int i=0;i<v ;i++){
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }

    BFS(edges,v);

}