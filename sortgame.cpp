#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int bfs(const vector<int>& perm){
    int n = perm.size();
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());

    queue<vector<int> > q;
    map<vector<int> , int> dist; // 2차원처럼 쓸 수 있음
    dist[perm] = 0;
    q.push(perm);

    while(!q.empty()){
        vector<int> here = q.front(); q.pop();
        if(here == sorted) return dist[here]; // 큐에 넣을 때 dist저장하고 뺄 때 검사해서 출력(언제 저장하고 검사 출력할지 코딩전 계획은 필수)
        int cost = dist[here];
        for(int i = 0; i < n; i++){//이렇게 많고 막연할 것을 어떻게 다하지?라는 생각이 들 때 2중 for문으로 무식하게 다 순회하는 방법 생각
            for(int j = i + 2; j <= n; j++){//백터 reverse할 때 둘째 인자가 마지막 인댁스 + 1이 들어가야하기 때문
                reverse(here.begin() + i,here.begin() + j);
                if(dist.count(here) == 0){ // class map의 count메서드 
                    dist[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
    return -1;
}//대소는 전혀 고려하지 않고 그저 주어진 규칙을 모든 경우에 적용시켜 그중 원하는 상태가 된 것을 찾는 방식