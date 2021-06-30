// sudoku solver
// https://leetcode.com/problems/sudoku-solver/

bool isSafe(vector<vector<char>> &board, int row, int col, int digit){
    // vertical row
    for(int i=0;i<9;i++){
        int boardDigit = board[i][col] - '0';
        if(boardDigit==digit)
            return false;
    }
    
    //horizontal row
    for(int j=0;j<9;j++){
        int boardDigit = board[row][j] - '0';
        if(boardDigit==digit)
            return false;
    }
    
    //sub-grid
    int sgRow = (row/3)*3,sgCol = (col/3)*3;
    for(int i=sgRow;i<sgRow+3;i++){
        for(int j=sgCol;j<sgCol+3;j++){
            int boardDigit = board[i][j] - '0';
            if(boardDigit==digit)
                return false;
        }
    }
    return true;
}

pair<int,int> unassigned(vector<vector<char>> &board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')
                return {i,j};
        }
    }
    return {9,9};
}

bool sudokuHelper(vector<vector<char>> &board){
    pair<int,int> coords = unassigned(board);
    if(coords.first==9){
        return true;
    }
    
    int row = coords.first,col = coords.second;
    
    for(int i=1;i<=9;i++){
        if(isSafe(board,row,col,i)){
            board[row][col] = '0'+i;
            if(sudokuHelper(board))
                return true;
            else
                board[row][col] = '.';
        }
    }
    
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    sudokuHelper(board);
}