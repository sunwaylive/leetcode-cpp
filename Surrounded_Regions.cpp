#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    //method 1: iterative solution
    void solve2(vector<vector<char> > &board){
        if(board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                vector<pair<int, int> > curPath;
                bool isSurrounded = true;
                if(!visited[i][j])
                    bfs(i, j, board, visited, curPath, isSurrounded);

                //modify
                if(isSurrounded){
                    for(int k = 0; k < curPath.size(); ++k)
                        board[curPath[k].first][curPath[k].second] = 'X';
                }
            }//end for n
        }//end for m
    }

    void bfs(int r, int c, vector<vector<char> > &board, vector<vector<bool> > &visited,
             vector<pair<int, int> > &curPath, bool &isSurrounded){
        if(board.empty() || board[0].empty()) return;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int> > posQ;
        posQ.push(pair<int, int>(r, c));

        while(!posQ.empty()){
            int curR = posQ.front().first;
            int curC = posQ.front().second;
            posQ.pop();

            if(board[curR][curC] == 'O' && !visited[curR][curC]){
                curPath.push_back(pair<int, int>(curR, curC));// add all adjacent elems
                visited[curR][curC] = true;// update visit status
                //expand in 4 directions
                for(int k = 0; k < 4; ++k){
                    int newR = curR + dir[k][0];
                    int newC = curC + dir[k][1];
                    //defend
                    if(newR < 0 || newR >= m || newC < 0 || newC >= n){
                        isSurrounded = false;//they have reach beyond the board
                    }else if(!visited[newR][newC]){
                        posQ.push(pair<int, int>(newR, newC));//inside the board and go on searching
                    }
                }//end for
            }
        }//end while
    }

    //method 2: recursive solution, run time error for large stack space needed
    void solve(vector<vector<char> > &board) {
        if(board.empty() || board[0].size() == 0) return ;

        m = board.size(), n = board[0].size();
        //traversal first and last row
        for(int j = 0; j < n; ++j){
            dfs(0, j, board);
            dfs(m - 1, j, board);
        }

        //traversal first and last column
        for(int i = 0; i < m; ++i){
            dfs(i, 0, board);
            dfs(i, n - 1, board);
        }

        //change
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] = (board[i][j] == 'A') ? '0' : 'X';
            }
        }
    }

    void dfs(int x, int y, vector<vector<char> > &board){
        if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == '0'){
            board[x][y] = 'A';
            dfs(x + 1, y, board);
            dfs(x - 1, y, board);
            dfs(x, y + 1, board);
            dfs(x, y - 1, board);
        }
    }

public:
    int m, n;

};

vector<vector<char> > createBoard(int m, int n)
{
    vector<vector<char> > board;
    for(int i = 0; i < m; ++i){
        vector<char> row;
        for(int j = 0; j < n; ++j){
            char tmp = (rand() % 2) == 1 ? '0' : 'X';
            row.push_back('X');
        }
        board.push_back(row);
    }
    return board;
}

void printBoard(const vector<vector<char> > &board)
{
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout<<board[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<char> > board = createBoard(3, 3);
    board[1][1] = '0';
    printBoard(board);

    Solution sln;
    sln.solve2(board);

    printBoard(board);
    return 0;
}
