#include<bits/stdc++.h>

using namespace std;

#define POSSIBLE_MOVES 4
vector<int> xMove = {0, 0, 1, -1};
vector<int> yMove = {1, -1, 0, 0};
int entRow, entCol, m, n;

bool isExit(int row,int col){
    if(row==entRow && col == entCol)
        return false;
    
    if(row==m-1 || col==n-1)
        return true;
    
    return false;
}

bool isSafe(vector<vector<char>> &maze, int row, int col){
    if(maze[row][col]=='-' || maze[row][col]=='+' || row<0 || row>=m || col<0 || col>=n)
        return false;
    else
        return true;
}

void nearestExitHelper(vector<vector<char>> &maze, int row, int col, int &Min, int currCount){
    if(isExit(row,col)){
        Min = min(Min,currCount);
        return;
    }
    
    for(int i=0;i<POSSIBLE_MOVES;i++){
        int x = row + xMove[i];
        int y = col + yMove[i];
        
        if(isSafe(maze,x,y)){
            maze[x][y] = '-';
            nearestExitHelper(maze,x,y,Min,currCount+1);
            maze[x][y] = '.';
        }
    }
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    entRow = entrance[0];
    entCol = entrance[1];
    m = maze.size();
    n = maze[0].size();
    int Min = INT_MAX;
    nearestExitHelper(maze,entRow,entCol,Min,0);
    
    if(Min==INT_MAX)
        return -1;
    else
        return Min;
}


int main(){
    vector<vector<char>> maze = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    vector<int> entrance = {1,0};

    cout<< nearestExit(maze,entrance);
}