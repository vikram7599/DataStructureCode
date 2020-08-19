#include<bits/stdc++.h>
using namespace std;


int findMinIndex(queue<int> &q, int sortIndex){
    int min_index = -1;
    int minVal = INT_MAX;
    int n = q.size();

    for(int i=0; i<n; i++){
        int front = q.front();
        q.pop();

        if(front <= minVal && i <= sortIndex){
            min_index = i;
            minVal = front;
        }
        q.push(front);
    }

    return min_index;
}

void sortQueue(queue<int> &q, int minIndex){

    int n = q.size();
    int minVal = -1;
    for(int i=0; i<n; i++){
        int front = q.front();
        q.pop();
        if(i == minIndex){
            minVal = front;
        }
        else{
            q.push(front);
        }
    }

    q.push(minVal);
}

void queueSort(queue<int> &q){
    for(int i=1; i<=q.size(); i++){
        int minIndex = findMinIndex(q, q.size()-i);
        sortQueue(q, minIndex);
    }
}

int main(){

    queue<int> q;
    q.push(30);
    q.push(11);
    q.push(15);
    q.push(4);
    queueSort(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}