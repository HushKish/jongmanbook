#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int here){
    //첫번째 노드에서 시작 인접한 노드들 재귀로 호출
    cout << "DFS visits" << here << endl;
    visited[here] = true;
    for(int i = 0; i < adj[here].size(); i++){ // adj[idx]을 하나의 백터변수 v라고 생각
        int there = adj[here][i];
        if(!visited[there]){
            dfs(there);
        }
    }
    //더이상 방문할 것이 없어 이전 호출로 돌아감
}
//모든정점 방문(모든 노드가 연결되어 있다는 보장은 없기 때문에 필요함)
void dfsAll(){
    //모두 false로 초기화
    visited = vector<bool>(adj.size(), false);
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]) dfs(i);           
    }
}