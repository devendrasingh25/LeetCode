class MyHashMap {
public:
    vector<pair<int,int>> hash ;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int n = hash.size();
       for( int i =0 ;i < n ;i++){
         if( hash[i].first == key){
            hash[i].second = value;
            return ;
         }
        }
       hash.push_back({key,value});
    }
    
    int get(int key) {
        int n  = hash.size();
        for( int i = 0; i < n ;i ++){
            if(hash[i].first == key) return hash[i].second;
           
        }
        return -1;
    }
    
    void remove(int key) {
        int n = hash.size();
        for( int i =0 ; i < n ; i++){
            if( hash[i].first == key){
                hash.erase(hash.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */