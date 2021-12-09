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

int get_size_basin(vector<vector<bool>> &visited, const vector<vector<int>> &matrix, int i, int j) {

        if (visited[i][j] == true) {
            return 0;
        }

        visited[i][j] = true;

        int curr_elem = matrix[i][j];

        if (curr_elem == 9) {
            return 0;
        }

        int size_basin = 1;

        bool curr_is_min = true;

        if (i - 1 >= 0) {
            size_basin += get_size_basin(visited, matrix, i - 1, j);
        }

        if (i+1 < matrix.size()) {
            size_basin += get_size_basin(visited, matrix, i + 1, j);
        }

        if (j-1 >= 0) {
            size_basin += get_size_basin(visited, matrix, i, j - 1);
        }

        if (j+1 < matrix[i].size()) {
            size_basin += get_size_basin(visited, matrix, i, j + 1);
        }

        return size_basin;
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

    int num_basins = 0;
    vector<int> basin_sizes;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (!visited[i][j] && matrix[i][j] != 9) {
                num_basins++;
                int size_basin = get_size_basin(visited, matrix, i, j);
                /* cout << size_basin << endl; */
                basin_sizes.push_back(size_basin);
            }
        }
    }

    unsigned long product = 1;

    make_heap(basin_sizes.begin(), basin_sizes.end());
    product *= basin_sizes.front();
    cout << basin_sizes.front() << endl;
    pop_heap (basin_sizes.begin(), basin_sizes.end()); basin_sizes.pop_back();
    product *= basin_sizes.front();
    cout << basin_sizes.front() << endl;
    pop_heap (basin_sizes.begin(), basin_sizes.end()); basin_sizes.pop_back();
    product *= basin_sizes.front();
    cout << basin_sizes.front() << endl;

    cout << product << endl;
}
