#include<iostream>
#include "treeNode.h"

using namespace std;

TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> qt;

    qt.push_back(root);

    while(qt.size() != 0){
        TreeNode<int> *front = qt.front();
        qt.pop();
        int numChild;
        cin >> numChild;
        for(int i=0; i<numChild; i++){
            int childValue;
            cin >> childValue;
            TreeNode<int> *child = new TreeNode<int>(childValue);
            front->children.push_back(child);
        }
    }    

    return root;
}

TreeNode<int>* takeInput(){
    int rootData;

    cout << "Enter root data\t" ;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int> *root){

    if(root == NULL){
        return ;
    }

    cout << root->data << ": " << endl;

    for(int i=0; i<root->children.size(); i++){
        cout << root->children[i] <<", ";
    }
    cout << endl;

    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }

}

int main(){

    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

    printTree(root);

}