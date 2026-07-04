class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin() , bank.end());

          if (bankset.find(end) == bankset.end()) return -1; 
        unordered_set<string> visited ;

        queue<string> q;
        visited.insert(start);
        int level =0 ;

        q.push(start);
        while(!q.empty()){
        int n = q.size();

        while(n--){
            string curr = q.front();
            q.pop();

            if( curr == end) return level ;

            for( char ch : string("ACGT")){
                for( int i =0 ;i < curr.length() ; i++){
                    string nb = curr;
                    nb[i] = ch ;
                    if(visited.find(nb) == visited.end() && bankset.find(nb) != bankset.end()){
                        visited.insert(nb);
                        q.push(nb);
                    }
                }
            }
        }
        level++ ;
        }
        return -1;
    }
};