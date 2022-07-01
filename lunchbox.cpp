#include<iostream>
#include<vector>
#include<algorithm>
#define Max_N 10000
using namespace std;
int main(void){
    int n, e[Max_N], m[Max_N];
    //pair vector에 넣고 부호를 넣어 역순정렬을 쉽게 구현
    vector<pair<int,int> > order;
    for(int i = 0; i < n; i++) order.push_back(make_pair(-e[i], i));
    sort(order.begin(), order.end());
    int time = 0, begin = 0;
    for(int i = 0; i < n; i++){
        int box = order[i].second;
        begin += m[box];
        time = max(time, begin + e[box]); // 이부분 구현이 핵심 - 이전 case에 여러 경우를 고려할 수도 있었을 것을 문제 특성을 고려하고 max를 이용해 간단하게 처리함
    }
}

