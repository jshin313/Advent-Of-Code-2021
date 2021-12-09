#include <bits/stdc++.h>

using namespace std;

void print_matrix(const vector<vector<int>> &matrix) {
    for (auto row: matrix) {
        for (auto elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int get_risk_level(vector<vector<bool>> &visited, const vector<vector<int>> &matrix, int i, int j) {

        if (visited[i][j] == true) {
            return 0;
        }

        visited[i][j] = true;

        int curr_elem = matrix[i][j];
        int risk_level = 0;

        bool curr_is_min = true;

        if (i - 1 >= 0) {
            risk_level += get_risk_level(visited, matrix, i - 1, j);
            if (curr_elem >= matrix[i-1][j]) {
                curr_is_min = false;
            }
        }

        if (i+1 < matrix.size()) {
            risk_level += get_risk_level(visited, matrix, i + 1, j);
            if (curr_elem >= matrix[i+1][j]) {
                curr_is_min = false;
            }
        }

        if (j-1 >= 0) {
            risk_level += get_risk_level(visited, matrix, i, j - 1);
            if (curr_elem >= matrix[i][j-1]) {
                curr_is_min = false;
            }
        }

        if (j+1 < matrix[i].size()) {
            risk_level += get_risk_level(visited, matrix, i, j + 1);
            if (curr_elem >= matrix[i][j+1]) {
                curr_is_min = false;
            }
        }

        if (curr_is_min) {
            risk_level += curr_elem + 1;
        }

        /* cout << risk_level << endl; */
        return risk_level;
}

void initialize(vector<vector<bool>> &visited, const vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        vector<bool> row(matrix[i].size(), false);
        visited.push_back(row);
    }
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    vector<vector<int>> matrix;

    string s;
    while (getline(cin, s)) {
        /* cout << s; */
        vector<int> row;
        for (auto c: s) {
            row.push_back(c - '0');
        }
        matrix.push_back(row);
    }

    /* print_matrix(matrix); */

    // Perform depth first search, find strongly connected components

    // Store whether we've visited or not
    vector<vector<bool>> visited;
    
    // Set to all false
    initialize(visited, matrix);

    int risk_level = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (!visited[i][j]) {
                risk_level += get_risk_level(visited, matrix, i, j);
                /* cout << i << " "<< j << ": " << risk_level << endl; */
            }
        }
    }

    cout << risk_level << endl;
}
