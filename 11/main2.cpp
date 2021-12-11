#include <bits/stdc++.h>

using namespace std;

const int STEPS = 2000;

void print_matrix(const vector<vector<int>> & matrix) {
    for (auto row: matrix) {
        for (auto elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}


int count_flashes_recur(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &has_flashed) {
    if (i < 0 || j < 0 || j >= matrix[i].size() || i >= matrix.size()) {
        return 0;
    }

    if (!has_flashed[i][j]) {
        matrix[i][j]++;
    }

    int flashes = 0;
    if (matrix[i][j] > 9) {
        if (!has_flashed[i][j]) {
            has_flashed[i][j] = true;
            flashes++;
            matrix[i][j] = 0;
            flashes += count_flashes_recur(i, j + 1, matrix, has_flashed);
            flashes += count_flashes_recur(i, j - 1, matrix, has_flashed);
            flashes += count_flashes_recur(i + 1, j, matrix, has_flashed);
            flashes += count_flashes_recur(i + 1, j + 1, matrix, has_flashed);
            flashes += count_flashes_recur(i + 1, j - 1, matrix, has_flashed);
            flashes += count_flashes_recur(i - 1, j, matrix, has_flashed);
            flashes += count_flashes_recur(i - 1, j - 1, matrix, has_flashed);
            flashes += count_flashes_recur(i - 1, j + 1, matrix, has_flashed);
        }
    }

    return flashes;
}

bool count_flashes(vector<vector<int>> &matrix) {
    int flashes = 0;

    vector<vector<bool>> has_flashed;
    for (int i = 0; i < matrix.size(); i++) {
        vector<bool> row;
        for (int j = 0; j < matrix[i].size(); j++) {
            row.push_back(false);
        }
        has_flashed.push_back(row);
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            flashes += count_flashes_recur(i, j, matrix, has_flashed);
        }
    }

    /* cout << flashes << endl; */

    if (flashes == matrix.size() * matrix[0].size()) {
        return true;
    }

    return false;
}


int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    vector<vector<int>> matrix;
    string s;
    while (getline(cin, s)) {
        vector<int> row;
        for (auto c: s) {
            row.push_back(c - '0');
        }
        matrix.push_back(row);
    }

    /* print_matrix(matrix); */

    int flashes = 0;
    for (int i = 0; i < STEPS; i++) {
        if (count_flashes(matrix)) {
            cout << i + 1 << endl;
            break;
        }
    }
}
