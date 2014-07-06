#include <iostream>
#include <vector>
#include <string>
using namespace std;

//http://www.cnblogs.com/remlostime/archive/2012/11/16/2772827.html
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) return false;
        totalRow = board.size();
        totalCol = board[0].size();
        vector<vector<bool> > visited(totalRow, vector<bool>(totalCol, false));

        bool result = false;
        for(int i = 0; i < totalRow && !result; ++i){
            for(int j = 0; j < totalCol && !result; ++j){
                dfs(0, word.size(), i, j, visited, board, word, result);
            }
        }

        return result;
    }

    void dfs(int curDep, int maxDep, int row, int col, vector<vector<bool> > &visited, vector<vector<char> > &board, string &target, bool &result){
        if(result) return;
        if(curDep > maxDep) return;

        if(curDep == maxDep){
            result = true;
        }else{
            if(row < 0 || row >= totalRow || col < 0 || col >= totalCol || visited[row][col])
                return;

            if(board[row][col] == target[curDep]){
                visited[row][col] = true;
                dfs(curDep + 1, maxDep, row - 1, col, visited, board, target, result);
                dfs(curDep + 1, maxDep, row + 1, col, visited, board, target, result);
                dfs(curDep + 1, maxDep, row, col - 1, visited, board, target, result);
                dfs(curDep + 1, maxDep, row, col + 1, visited, board, target, result);
                visited[row][col] = false;
            }
        }
    }
private:
    int totalRow, totalCol;
};

int main()
{
    vector<char> row1({'A', 'B', 'C', 'E'});
    vector<char> row2({'S', 'F', 'C', 'S'});
    vector<char> row3({'A', 'D', 'E', 'E'});
    vector<vector<char> > board;
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);

    Solution sln;
    cout<<sln.exist(board, "ABCCED")<<endl;

    return 0;
}
