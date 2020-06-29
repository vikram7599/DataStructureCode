#include<vector>
class PriorityQueue{
    vector<int> pq;

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){

        if(isEmpty()){
            return NULL;
        }

        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);

        int size = getSize();

        int childIndex = size-1;
        
        while(childIndex > 0)
        {
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;

            }
            else{
                break;
            }

            childIndex = parentIndex;
        }
        

    }

    int removeMin(){
        int ans = pq[0];

        pq[0] = pq[pq.size()-1];
        pq.pop_back();


        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1, rightChildIndex = 2 * parentIndex + 2;


        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex ;

            if(pq[leftChildIndex] < pq[minIndex]){
                minIndex = leftChildIndex;
            }

            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]){
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex){
                break;
            }

            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex ;

            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
}