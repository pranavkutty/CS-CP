// rat in a maze
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

vector<int> xMoves = {0,-1,0,1};
vector<int> yMoves = {-1,0,1,0};
vector<char> Moves = {'L','U','R','D'};

bool isSafe(vector<vector<int>> &mat,vector<vector<bool>> &visited,int row,int col){
    int m = mat.size(),n = mat[0].size();
    if(row>=m || row<0 || col>=n || col<0 || mat[row][col]==0 || visited[row][col]==1)
        return false;
    else 
        return true;
}

void findPathHelper(vector<vector<int>> &mat,vector<vector<bool>> &visited,vector<string> &res,string &currRes, int row,int col){
    int m=mat.size(),n=mat[0].size();
    
    if(row==m-1 && col==n-1){
        res.push_back(currRes);
        return;
    }
    
    visited[row][col] = true;
    for(int i=0;i<POSSIBLE_MOVES;i++){
        int nextX = row+xMoves[i];
        int nextY = col+yMoves[i];
        if(isSafe(mat,visited,nextX,nextY)){
            currRes.push_back(Moves[i]);
            findPathHelper(mat,visited,res,currRes,nextX,nextY);
            currRes.pop_back();
        }
    }
    visited[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &mat, int N) {
    int m = mat.size(),n=mat[0].size();
    vector<string> res;
    if(mat[0][0]==0) return res;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    string currRes = "";
    findPathHelper(mat,visited,res,currRes,0,0);
    sort(res.begin(),res.end());
    return res;
}