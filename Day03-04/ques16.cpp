// knight tour

#define POSSIBLE_MOVES 8
vector<int> xMoves = {1,-1,1,-1,2,2,-2,-2};
vector<int> yMoves = {2,2,-2,-2,1,-1,1,-1};

bool isSafe(vector<vector<int>> &mat,vector<vector<bool>> &visited,int row,int col){
    int m = mat.size(),n = mat[0].size();
    if(row>=m || row<0 || col>=n || col<0 || visited[row][col]==1)
        return false;
    else 
        return true;
}

bool knightTourHelper(vector<vector<int>> &mat,vector<vector<bool>> &visited, int row,int col){
    int m=mat.size(),n=mat[0].size();
    
    if(row==m-1 && col==n-1){
        return true;
    }
    
    visited[row][col] = true;
    for(int i=0;i<POSSIBLE_MOVES;i++){
        int nextX = row+xMoves[i];
        int nextY = col+yMoves[i];
        if(isSafe(mat,visited,nextX,nextY)){
            if(knightTourHelper(mat,visited,nextX,nextY))
                return true;
        }
    }
    visited[row][col] = false;

    return false;
}

vector<string> knightTour(vector<vector<int>> &board, int N) {
    int m = board.size(),n=board[0].size();
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    return knightTourHelper(board,visited,0,0);
}