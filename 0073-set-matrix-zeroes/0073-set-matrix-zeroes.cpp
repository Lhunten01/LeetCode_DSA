class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>visited(m,(vector<int>(n,0)));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { 
              if(matrix[i][j]==0)
             { q.push({i,j});
               visited[i][j]=1;
             }
            }
        }

        while(!q.empty())
        {
            auto it=q.front();
            int x=it.first;
            int y=it.second;
            q.pop();
           for(int i=x;i<m;i++)
           {
            matrix[i][y]=0;
           }
           for(int i=x;i>=0;i--)
           {
            matrix[i][y]=0;
           }
           for(int i=y;i<n;i++)
           {
            matrix[x][i]=0;
           }
           for(int i=y;i>=0;i--)
           {
            matrix[x][i]=0;
           }
        }


    }
};