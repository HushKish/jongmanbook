#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > adj; // 그래프의 인접리스트 표현
vector<int> bfs(int start){
    vector<bool> disco(adj.size(), false);
    queue<int> q;
    vector<int> order;
    disco[start] = true;
    q.push(start);
    while(!q.empty()){
        int here = q.front(); q.pop();
        order.push_back(here);
        for(int i  = 0; i < q.size(); i++){
            int there = adj[here][i];
            if(!disco[there]){
                q.push(there);
                disco[there] = true;
            }
        }
    }
    return order;
}