#include<iostream>
#include<vector>
using namespace std;
int n;
int main(void){
    cin >> n;
    int begin[100], end[100];
    for(int i = 0; i < n; i++){
        cin >> begin[i] >> end[i];
    }

    vector<pair<int,int> > order;
    for(int i = 0; i < n; i++) order.push_back(make_pair(end[i],begin[i]));
    sort(order.begin(),order.end());
    //earliest - 다음 회의가 시작할 수 있는 가장 빠른 시간 selected - 지금까지 선택한 회의의 수
    int earliest = 0, selected = 0;
    for(int i = 0; i < order.size(); i++){
        int mstart = order[i].second , mend = order[i].first;
        if(earliest <= mstart){
            earliest = mend;
            selected++;
        }
    }
}

