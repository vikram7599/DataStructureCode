#include<bits/stdc++.h>
using namespace std;
void pairsort(int *a, int *b, int n, int inc) 
{ 
    pair<int, int> pairt[n]; 
  
    // Storing the respective array 
    // elements in pairs. 
    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    // Sorting the pair array. 
    if(inc)
        sort(pairt, pairt + n); 
    else
    {
        sort(pairt, pairt + n, greater<pair<int, int>>()); 
    }
    
    // Modifying original arrays 
    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
} 


vector<int> sortByFreq(int arr[],int n)
{
    //Your code here
    
    unordered_map<int, int> omap;
    for(int i=0; i<n; i++){
        omap[arr[i]]++; 
    }
    
    int uniqueElements = 0;
    
    for(auto it = omap.begin(); it != omap.end(); it++)
    {
        uniqueElements++;    
    }
    int *elem = new int[uniqueElements];
    int *count= new int[uniqueElements];
    
    int i =0;
    for(auto it = omap.begin(); it != omap.end(); it++)
    {
        elem[i] = it->first;
        count[i] = it->second;
        i++;
    }
    
    
    pairsort(elem, count, uniqueElements, 1);
    
    pairsort(count, elem, uniqueElements, 0);
    
    vector<int> ansVec;
    for(int i=0; i<uniqueElements; i++){
        int currCount = count[i];
        int currElem = elem[i];
        for(int j=0; j<currCount; j++){
            ansVec.push_back(currElem);
        }
    }
    
    return ansVec;
    
}

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> ansVec = sortByFreq(arr, n);

    for(int i=0; i<ansVec.size(); i++){
        cout << ansVec[i] << " ";
    }
    cout << endl;

}