#include <bits/stdc++.h>

using namespace std;

#define MARK -1

void print_board(vector<vector<int>> & board) {
    for (auto row: board) {
        for (auto elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int get_uncalled_num_sum(vector<vector<int>> & board) {
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

bool check_bingo(vector<vector<int>> & board) {
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

int score(vector<int>& called_nums, vector<vector<vector<int>>> &boards) {
    for (auto called_num: called_nums) {
        for (auto &board: boards) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == called_num) {
                        /* cout << board[i][j] << endl; */
                        board[i][j] = MARK;
                    }

                    /* print_board(board); */
                    if (check_bingo(board)) {

                        return called_num * get_uncalled_num_sum(board);
                    }

                }
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
    std::vector<int> vect;

    std::stringstream ss(s);

    for (int i; ss >> i;) {
        vect.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

    vector<vector<vector<int>>> boards;
    vector<vector<int>> board;
    vector<int> row;

    int num;
    while (cin >> num) {
        if (board.size() >= 5) {
            boards.push_back(board);
            board.clear();
        }

        if (row.size() >= 5) {
            board.push_back(row);
            row.clear();
        }

        row.push_back(num);
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

    cout << score(vect, boards) << endl;
}
