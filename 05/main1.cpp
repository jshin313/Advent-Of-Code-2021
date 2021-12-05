#include <bits/stdc++.h>

using namespace std;


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

void print_intervals(const vector<vector<int>> & intervals) {
    for (auto interval: intervals) {
        cout << "(" << interval[0] << ", " << interval[1] << ") ";
    }
    cout << endl;
}

bool is_vert(const vector<int> &p1, const vector<int> &p2) {
    if (p1[0] == p2[0]) {
        return true;
    }
    return false;
}

bool is_hor(const vector<int> &p1, const vector<int> &p2) {
    if (p1[1] == p2[1]) {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    string s;

    vector<vector<int>> hor_intervals;
    vector<vector<int>> vert_intervals;

    int max_vert = 0;
    int max_hor = 0;

    while (getline(cin, s)) {
        std::stringstream ss(s);

        vector<int> p1(2, 0); 
        vector<int> p2(2, 0);

        ss >> p1[0]; ss.ignore(); ss >> p1[1];
        ss.ignore(4);
        ss >> p2[0]; ss.ignore(); ss >> p2[1];
        
        /* cout << p1[0] << " " << p1[1] << endl; */
        /* cout << p2[0] << " " << p2[1] << endl; */
        /* cout << endl; */

        if (is_vert(p1, p2)) {
            if (p1[1] > p2[1]) {
                swap(p1[1], p2[1]);
            }
            vector<int> interval{p1[1], p2[1], p1[0]};
            vert_intervals.push_back(interval);

            if (interval[1] > max_vert) {
                max_vert = interval[1];
            }
        }

        if (is_hor(p1, p2)) {
            if (p1[0] > p2[0]) {
                swap(p1[0], p2[0]);
            }
            vector<int> interval{p1[0], p2[0], p1[1]};
            hor_intervals.push_back(interval);

            if (interval[1] > max_hor) {
                max_hor = interval[1];
            }
        }

    }

    /* print_intervals(vert_intervals); */
    /* print_intervals(hor_intervals); */

    /* cout << max_hor << endl; */
    /* cout << max_vert << endl; */
    /* cout << endl; */

    vector<vector<int>> matrix;
    int n = max(max_hor, max_vert);

    for (int i = 0; i < n + 1; i++) {
        matrix.push_back(vector<int>(n+1, 0));
    }

    for (auto interval: hor_intervals) {
        for (int i = interval[0]; i <= interval[1]; i++) {
            matrix[interval[2]][i]++;
        }
    }

    for (auto interval: vert_intervals) {
        for (int i = interval[0]; i <= interval[1]; i++) {
            matrix[i][interval[2]]++;
        }
    }


    print_matrix(matrix);

    int num_points = 0;
    for (auto row: matrix) {
        for (auto elem: row) {
            if (elem >= 2) {
                num_points++;
            }
        }
    }
    cout << num_points << endl;

}
