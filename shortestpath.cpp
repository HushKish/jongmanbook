#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void){

}
vector<vector<int> > adj;//그래프 정보를 저장하고 있는 인접리스트 

void bfs2(int start, vector<int>& distance,vector<int>& parent){
    distance = vector<int>(adj.size(), -1); //start에서 i노드 까지의 최단거리
    parent = vector<int>(adj.size(), -1); // 부모노드의 값을 저장하고 있는 백터, 루트일 경우 자신의 값을 가짐

    queue<int> q;
    distance[start] = 0;
    parent[start] = start;
    q.push(start);
    while(!q.empty()){
        int here = q.front(); q.pop();
        for(int i = 0; i < adj[here].size(); i++){
            int there = adj[here][i];
            if(distance[there] == -1){
                distance[there] = distance[here] + 1;
                parent[there] = here;
            } 
        }
    }
}
//parent -> bfs spanning tree구현한 것
vector<int> shortesetPath(int v, const vector<int>& parent){
    vector<int> path(1,v);//v를 유일한 원소로 갖는 백터 하나 선언
    while(parent[v] != v){//루트인지 검사하는 코드
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}