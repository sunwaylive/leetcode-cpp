#include <iostream>
#include <vector>

using namespace std;

bool check(char ch, bool used[])
{
    if(ch == '.') return true;
    if(used[ch - '1']) return false;

    used[ch - '1'] = true;
    return true;
}

bool isValidSudoku(vector<vector<char> > &board)
{
    bool used[9];
    int i, j;
    for(i = 0; i < 9; ++i){
        //check row
        fill(used, used + 9, false);
        for(j = 0; j < 9; ++j){
            if(!check(board[i][j], used))
                return false;
        }

        //check column
        fill(used, used + 9, false);
        for(j = 0; j < 9; ++j){
            if(!check(board[j][i], used))
                return false;
        }
    }

    //check for 9 sub cells
    for(int r = 0; r < 3; ++r){
        for(int c = 0; c < 3; ++c){
            fill(used, used + 9, false);

            cout<<"r: "<<r <<" c: "<<c <<endl;
            for(i = 0; i < 3; ++i){
                for(j = 0; j < 3; ++j){
                    if(!check(board[3 * r + i][3 * c + j], used))
                        return false;
                }
            }
        }
    }

    return true;
}


int main()
{
    vector<vector<char> > board;
    vector<char> vec;
    vec.push_back('4');vec.push_back('6');vec.push_back('3');vec.push_back('7');vec.push_back('2');vec.push_back('8');vec.push_back('9');vec.push_back('5');vec.push_back('1');
    board.push_back(vec);
    vec.clear();
    vec.push_back('2');vec.push_back('5');vec.push_back('9');vec.push_back('4');vec.push_back('6');vec.push_back('1');vec.push_back('7');vec.push_back('3');vec.push_back('8');
    board.push_back(vec);
    vec.clear();
    vec.push_back('7');vec.push_back('8');vec.push_back('1');vec.push_back('3');vec.push_back('5');vec.push_back('9');vec.push_back('6');vec.push_back('4');vec.push_back('2');
    board.push_back(vec);
    vec.clear();
    vec.push_back('5');vec.push_back('3');vec.push_back('2');vec.push_back('1');vec.push_back('9');vec.push_back('7');vec.push_back('4');vec.push_back('8');vec.push_back('6');
    board.push_back(vec);
    vec.clear();
    vec.push_back('9');vec.push_back('1');vec.push_back('4');vec.push_back('6');vec.push_back('8');vec.push_back('2');vec.push_back('5');vec.push_back('7');vec.push_back('3');
    board.push_back(vec);
    vec.clear();
    vec.push_back('6');vec.push_back('7');vec.push_back('8');vec.push_back('5');vec.push_back('4');vec.push_back('3');vec.push_back('1');vec.push_back('2');vec.push_back('9');
    board.push_back(vec);
    vec.clear();
    vec.push_back('8');vec.push_back('2');vec.push_back('6');vec.push_back('9');vec.push_back('7');vec.push_back('5');vec.push_back('3');vec.push_back('1');vec.push_back('4');
    board.push_back(vec);
    vec.clear();
    vec.push_back('1');vec.push_back('4');vec.push_back('7');vec.push_back('2');vec.push_back('3');vec.push_back('6');vec.push_back('8');vec.push_back('9');vec.push_back('5');
    board.push_back(vec);
    vec.clear();
    vec.push_back('3');vec.push_back('9');vec.push_back('5');vec.push_back('8');vec.push_back('1');vec.push_back('4');vec.push_back('2');vec.push_back('6');vec.push_back('7');
    board.push_back(vec);
    vec.clear();

    cout<<isValidSudoku(board)<<endl;
    return 0;
}
