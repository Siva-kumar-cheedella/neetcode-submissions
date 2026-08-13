class Solution {
public:
    bool isValidSubMatrix(int i, int j, int k, int l, vector<vector<char>>& board){
        map<char,int> mp;
        for(int x=i; x<=k; x++){
            for(int y=j; y<=l; y++){
                if(mp.find(board[x][y])!=mp.end()){
                    return false;
                }
                if(board[x][y]!='.')
                mp[board[x][y]] = 1;
             }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
     
     for(int i=0; i<9; i++){
        map<int,int> mp;
        for(int j=0; j<9; j++){
            if(mp.find(board[i][j])!=mp.end()){
                return false;
            }
            if(board[i][j]!='.')
            mp[board[i][j]] = 1;
        }
     }

     for(int j=0; j<9; j++){
        map<int,int> mp;
        for(int i=0; i<9; i++){
            if(mp.find(board[i][j])!=mp.end()){
                return false;
            }
            if(board[i][j]!='.')
            mp[board[i][j]] = 1;
        }
     }
    cout<<"HI";
     return isValidSubMatrix(0,0,2,2,board) &&
     isValidSubMatrix(0,3,2,5,board) &&
     isValidSubMatrix(0,6,2,8,board) &&
     isValidSubMatrix(3,0,5,2,board) &&
     isValidSubMatrix(3,3,5,5,board) &&
     isValidSubMatrix(3,6,5,8,board) &&
        isValidSubMatrix(6,0,8,2,board) &&
        isValidSubMatrix(6,3,8,5,board) &&
        isValidSubMatrix(6,6,8,8,board); 
     //0,0 -> 2,2
     //0,3 -> 2,5
     //0,6 -> 2,8

     //3,0 -> 5,2
     //3,3 -> 5,5
     //3,6 -> 5,8

     //6,0 -> 8,2
     //6,3 -> 8,5
     //6,6 -> 8,8
    }
};
