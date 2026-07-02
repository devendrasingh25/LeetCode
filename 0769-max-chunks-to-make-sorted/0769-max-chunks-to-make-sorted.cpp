class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
          stack<int> st;
          for( int x : arr){
            if( st.empty() || x >= st.top()){
                st.push(x);
            }
            else{
                int u = st.top();
                st.pop();
                while(!st.empty() &&  st.top() > x){
                    st.pop();
                }
                st.push(u);
            }
            
          }
        return st.size();
    }
};