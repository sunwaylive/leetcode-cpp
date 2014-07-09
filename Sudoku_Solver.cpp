#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(int k = 1; k <= 9; ++k){
                        board[i][j] = '0' + k;
                        if(checkValid(board, i, j) && solveSudoku(board))
                            return true;
                        board[i][j] = '.';//undo
                    }
                    //if for all 1 ~ 9 fails, then return false
                    return false;
                }//end for if
            }
        }
        //all board have been filled
        return true;
    }

private:
    bool checkValid(vector<vector<char> > &board, int x, int y){
        int i = 0, j = 0;
        //check row
        for(j = 0; j < 9; ++j)
            if(j != y && board[x][j] == board[x][y])
                return false;
        //check col
        for(i = 0; i < 9; ++i)
            if(i != x && board[i][y] == board[x][y])
                return false;
        //check  3*3 square
        for(i = 3 * (int)(x / 3); i < 3 * (int)(x / 3) + 3; ++i)
            for(j = 3 * (int)(y / 3); j < 3 * (int)(y / 3) + 3; ++j)
                if((i != x || j != y) && board[i][j] == board[x][y])
                    return false;

        return true;
    }
};

int main()
{
    vector<char> row1({'.', '.', '9', '7', '4', '8', '.', '.', '.'});
    vector<char> row2({'7', '.', '.', '.', '.', '.', '.', '.', '.'});
    vector<char> row3({'.', '2', '.', '1', '.', '9', '.', '.', '.'});
    vector<char> row4({'.', '.', '7', '.', '.', '.', '2', '4', '.'});
    vector<char> row5({'.', '6', '4', '.', '1', '.', '5', '9', '.'});
    vector<char> row6({'.', '9', '8', '.', '.', '.', '3', '.', '.'});
    vector<char> row7({'.', '.', '.', '8', '.', '3', '.', '2', '.'});
    vector<char> row8({'.', '.', '.', '.', '.', '.', '.', '.', '6'});
    vector<char> row9({'.', '.', '.', '2', '7', '5', '9', '.', '.'});

    vector<vector<char> > board;
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);
    board.push_back(row6);
    board.push_back(row7);
    board.push_back(row8);
    board.push_back(row9);
    Solution sln;
    cout<<sln.solveSudoku(board)<<endl;
    return 0;
}
