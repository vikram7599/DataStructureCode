#include<bits/stdc++.h>
using namespace std;

TreeNode *findPredecessor(TreeNode *current){

    TreeNode *temp = current->left;

    while(temp->right != NULL && temp->right != current){
        temp = temp->right;
    }

    return temp;
}

void morrisCode(TreeNode *root){
    TreeNode *current = root;

    while(current != NULL){
        if(current->left == NULL){
            cout << current->data <<" ";
            current = current->right;
        }
        else
        {
            TreeNode *pred = findPredecessor(current);

            if(pred->right == NULL){
                pred->right = current;
                current = current->left;
            }
            else{
                pred->right = NULL;
                cout << current->data <<" ";
                current = current->right;
            }
        }
    }

    return;
}