unordered_map<int,int> m;
   
   for(int i=0;i<n;i++){
      int key=input[i];
        m[key]++;
    }
    for(int i=0;i<n;i++){
          int key= input[i];
          if(key==0){
             int a = m[key];
             int count =((a-1)*a)/2;
              for(int j=0;j<count;j++){
                cout<<key<<" " <<key<<endl;
               }
            }
         else{
              int a=key+k;
               int b =key-k;
           
               int count=m[key];
               int count1 =m[a];
               int count2=m[b];
                for(int j=0;j<count*count1;j++){
                      cout<<min(a,key)<<" "<<max(a,key)<<endl;
                     }
                 for(int j=0;j<count*count2;j++){
                    cout<< min(b,key)<<" "<<max(b,key)<<endl;
                  }
               }
           m.erase(key);
      }