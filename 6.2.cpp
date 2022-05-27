#include<iostream>
#include<vector>
using namespace std;
void pick(int n,vector<int>& picked,int toPick){
    if(toPick == 0){
        printPicked(picked);
        return;
    }
    int small = picked.empty() ? 0 : picked.back() + 1;
    for(int next = small; next < n; next++){
        picked.push_back(small);
        pick(n,picked,toPick - 1);
        picked.pop_back();
    }
}