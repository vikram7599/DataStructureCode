#include "binaryTreeClass.h"
#include<bits/stdc++.h>

using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin >> rootData;
    queue<BinaryTreeNode<int>*> q;

    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter left child of " << front->data ;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            q.push(leftChild);
        }

        cout << "Enter right child of " << front->data ;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            q.push(rightChild);
        }

    }

    return root;

}

BinaryTreeNode<int>* takeInput(){

    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}

int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}




int diameter(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}


// F(n) = n * k + F(n-1);
// O(nlogn) O(n2) == O(nh)







pair<int, int> diameterBetter(BinaryTreeNode<int> *root){

    if(root == NULL){
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }

    pair<int, int> leftHeight = diameterBetter(root->left);
    pair<int, int> rightHeight = diameterBetter(root->right);

    int rootHeight = max(leftHeight.second , rightHeight.second) + 1;

    int option1 = leftHeight.second + rightHeight.second ;
    int option2 = leftHeight.first;
    int option3 = rightHeight.first;

    pair<int, int> ans;
    ans.first = max(option1, max(option2, option3));
    ans.second = rootHeight;

    return ans; 

}

int main(){




    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;
}