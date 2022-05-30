#include<iostream>
using namespace std;
class TreeNode{
    public:
        int size;
        string label;
        TreeNode* children[];
    private:
};
void printLabels(TreeNode* root){
    cout << root->label <<endl;//수행하는 기능
    for(int i = 0; i < root->size; i++){
        printLabels(root->children[i]);
    }//이 다음에 적용해야하는 대상들,printLabels함수가 내가 생각하는 기능을 수행한다고 가정하고
}
int height(TreeNode* root){
    int h;
    for(int i = 0; i < root->size; i++){
        h = max(h,1 + height(root->children[i]));
    }
    return h;
}