class Solution {
public:
bool search(int i,int j,int k,vector<vector<char>>&board,string word)
{  if(k==word.size())
     return true;
     if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[k])
     return false;
     char temp=board[i][j];
     board[i][j]='#';
     bool found=search(i+1,j,k+1,board,word)||search(i-1,j,k+1,board,word)||search(i,j+1,k+1,board,word)||search(i,j-1,k+1,board,word);
     board[i][j]=temp;
   return found;  
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int  i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0]&&search(i,j,0,board,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};