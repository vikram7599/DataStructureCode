class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
        int size = getSize();
        int ans = pq[0];
        int lastIndexVal = pq[size-1];
        
        pq[0] = lastIndexVal;
        pq.pop_back();
        
        int parentIndex = 0;
        int leftIndex = 2 * parentIndex + 1;
        int rightIndex= 2 * parentIndex + 2;
        
        while(leftIndex < pq.size()){
            int minIndex = parentIndex;
            
            if(pq[minIndex] > pq[leftIndex]){
                minIndex = leftIndex;
            }
            
            if(rightIndex < pq.size() && pq[rightIndex] < pq[minIndex]){
                minIndex = rightIndex;
            }
            
            if(minIndex == parentIndex){
                break;
            }
            
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = minIndex;
            leftIndex = 2 * parentIndex + 1;
            rightIndex= 2 * parentIndex + 2;
            
        }
        
        return ans;
        
    }
    

    
};

void inplaceHeapSort(int input[], int n){
    int i;
    for(i=1; i<n; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            
            if(input[childIndex] < input[parentIndex]){
                int temp = input[parentIndex] ;
                input[parentIndex] = input[childIndex];
                input[childIndex] = temp;
            }
            else{
                break;
            }
            
            childIndex = parentIndex;   
        }
    }
    
    int size = n;
    
    while(size > 1){
        int temp = input[0];
        input[0] = input[size-1];
        input[size-1] = temp;
        
        size--;
        
        int parentIndex = 0;
        int leftIndex = 2*parentIndex + 1;
        int rightIndex = 2*parentIndex + 2;
        
        
        
        while(leftIndex < size){
            int minIndex = parentIndex;
            
            if(input[minIndex] > input[leftIndex]){
                minIndex = leftIndex;
            }
            
            if(rightIndex < size && input[minIndex] > input[rightIndex]){
                minIndex = rightIndex;
            }
            
            if(minIndex == parentIndex){
                break;
            }
            
            temp = input[parentIndex] ;
            input[parentIndex] = input[minIndex] ;
            input[minIndex] = temp ;
            
            parentIndex = minIndex ;
            leftIndex  = 2*parentIndex + 1;
  	        rightIndex = 2*parentIndex + 2;
        }
        
        
        
    }
}