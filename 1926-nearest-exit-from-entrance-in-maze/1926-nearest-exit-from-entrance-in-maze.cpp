class Solution {
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
       int n  = maze.size();
       int m = maze[0].size();
   
       queue<pair<int,int>> q ;
       int step =0 ;
       q.push({ent[0] ,ent[1]});

       maze[ent[0]][ent[1]] = '+' ;

       int dr [] = {0 , -1, 0 , +1 };
       int dc [] = {+1 ,0 , -1 ,0 };

       while(!q.empty()){
         int sz= q.size() ;

         while( sz-- ){
            auto [r, c] = q.front();
                q.pop();
         

         if( (r == 0 || c == 0 || r == n-1 || c == m-1 ) &&  ! ( r == ent[0]  && c == ent[1]))return step ;

           for( int i =0 ;i < 4 ; i++ ){
             int nr = dr[i] + r ;
             int nc = dc[i] + c ;

             if( (nr >= 0 && nc  >= 0 && nr < n && nc < m) && maze[nr][nc] == '.'){
                maze[nr][nc] = '+';
                q.push({nr,nc});
             }
           }
         }
            step++;
       }
     
     return -1;
       
    }
};