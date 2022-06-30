#include<iostream>
#include<vector>
#include<set>
using namespace std;
//set,multiset stl 자유롭게 이용할 수 있게 학습
int order(const vector<int>& op,const vector<int>& us){
    int n = op.size(), wins = 0;
    multiset<int> ratings(us.begin(), us.end());
    for(int i = 0; i < n; i++){
        //우리팀에서 레이팅이 가장높은 사람이 상대팀 특정선수를 이길 수 없는 case
        if(*ratings.rbegin() < op[i]){
            ratings.erase(ratings.begin());
        }
        //이길 수 있는 case
        else{
            ratings.erase(ratings.lower_bound(op[i]));
            wins++;
        }
    }
    return wins;
}