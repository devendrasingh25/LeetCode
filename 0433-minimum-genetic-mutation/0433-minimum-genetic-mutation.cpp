class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
       int m  = bank.size();
       vector<bool> used( m ,false);
        queue<string> q;
        int level = 0 ;
        q.push(start);

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == end) return level;

                for( char ch :string("ACGT")){
                    for( int i= 0; i< curr.length() ;i++){
                        string nb = curr;
                        nb[i] = ch;

                        for( int j =0 ; j< m ; j++){
                            if(!used[j] && bank[j] == nb){
                                used[j] =true ;
                                q.push(nb);
                                break ;
                            }
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};