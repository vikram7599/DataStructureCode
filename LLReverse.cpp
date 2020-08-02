#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

Node *reverse(Node *head){
    Node *prev = NULL;
    Node *next ;

    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
}