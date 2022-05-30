#include<iostream>
#include<vector>
using namespace std;
vector<int> slice(const vector<int>& v,int a,int b){
    return vector<int>(v.begin() + a,v.begin() + b);//백터 복사에선 마지막원소의 뒷원소의 인댁스가 두번째 인자로 들어감
}
void printPostOrder(const vector<int>& pre,const vector<int>&in){
    if(pre.empty()) return;
    int root = pre[0];
    const int N = pre.size();
    const int L = find(in.begin(),in.end(),root) - in.begin();
    const int R = N - 1 - L;
    printPostOrder(slice(pre,1,L+1),slice(in,0,L));
    printPostOrder(slice(pre,L+1,N),slice(in,L+1,N));//첫번째 index는 몇번째인지 생각하고 1뺀다 생각,그 원소앞까지의 원소수 = 그 원소의 인댁스

    //in에서 루트로 왼쪽오른쪽 잘라서 inleft,inright백터만들기
    // 백터의 개수세서 pre에서 또 자르기
    // 왼쪽재귀호출 - 백터를 잘라낸것중 왼쪽
    // 오른쪽재귀호출 - 오른쪽
    // 루트출력
    cout << root;
}
int main(void){
    int t,nnum;
    vector<int> preorder,inorder;
    cin >> t;
    while(t--){
        cin >> nnum;
        //입력받기
        for(int i = 0; i < nnum; i++) cin >> preorder[i];
        for(int i = 0; i < nnum; i++) cin >> inorder[i];

        // 조합해서 계산
        

    }
}