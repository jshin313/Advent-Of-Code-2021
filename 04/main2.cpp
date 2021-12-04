#include <bits/stdc++.h>

using namespace std;

constexpr int MARK = -1;
constexpr int BOARD_SIDE_LEN = 5;

void print_board(const vector<vector<int>> & board) {
    for (auto row: board) {
        for (auto elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int get_uncalled_num_sum(const vector<vector<int>> & board) {
    int sum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != MARK) {
                sum+=board[i][j];
            }
        }
    }
    return sum;
}

bool check_bingo(const vector<vector<int>> & board) {
    // Check rows for bingo
    for (int i = 0; i < board.size(); i++) {
        bool is_bingo = true;
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != MARK) {
                is_bingo = false;
                break;
            }
        }
        if (is_bingo) { return true; }
    }


    // Check columns for bingo
    for (int j = 0; j < board[0].size(); j++) {
        bool is_bingo = true;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][j] != MARK) {
                is_bingo = false;
                break;
            }
        }
        if (is_bingo) { return true; }
    }

    return false;
}

int score(const vector<int>& called_nums, vector<vector<vector<int>>> &boards) {
    int bingo_wins = 0;
    for (auto called_num: called_nums) {
        for (auto it = boards.begin(); it != boards.end(); ) {
            auto &board = *it;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == called_num) {
                        /* cout << board[i][j] << endl; */
                        board[i][j] = MARK;
                    }


                }
            }
            if (check_bingo(board)) {
                if (boards.size() == 1) {
                    print_board(board);
                    return called_num * get_uncalled_num_sum(board);
                } else {
                    it = boards.erase(it);
                }
            } else {
                it++;
            }
        }
    }

    for (auto board: boards) {
        print_board(board);
    }

    return 0;

}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    string s;

    cin >> s;

    // https://stackoverflow.com/a/1894955/9512643
    std::vector<int> nums_called;

    std::stringstream ss(s);

    for (int i; ss >> i;) {
        nums_called.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

    vector<vector<vector<int>>> boards;
    vector<vector<int>> board;
    vector<int> row;

    int num;
    while (cin >> num) {
        if (board.size() == BOARD_SIDE_LEN) {
            boards.push_back(board);
            board.clear();
        } else if (board.size() > BOARD_SIDE_LEN) {
            throw runtime_error{"The given board is not a square board as expected for a bingo board."};
        }

        if (row.size() == BOARD_SIDE_LEN) {
            board.push_back(row);
            row.clear();
        } else if (row.size() > BOARD_SIDE_LEN) {
            throw runtime_error{"The given board is not a square board as expected for a bingo board."};
        }


        row.push_back(num);
    }
    if (board.size() > BOARD_SIDE_LEN) {
        throw runtime_error{"The given board is not a square board as expected for a bingo board."};
    } else if (row.size() > BOARD_SIDE_LEN) {
        throw runtime_error{"The given board is not a square board as expected for a bingo board."};
    }
    board.push_back(row);
    boards.push_back(board);

    /* for (auto b: boards) { */
    /*     for (auto r: b) { */
    /*         for (auto elem: r) { */
    /*             cout << elem << " "; */
    /*         } */
    /*         cout << endl; */
    /*     } */
    /*     cout << endl; */
    /*     cout << endl; */
    /* } */

    cout << score(nums_called, boards) << endl;
}
