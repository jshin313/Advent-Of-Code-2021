
#include <bits/stdc++.h>

using namespace std;

int dijkstra_shortest_path(vector<vector<int>> & adj_matrix, int start_node, int end_node) {
    vector<int> processed;
    vector<int> not_processed;
    unordered_map<int, int> distances;
    unordered_map<int, int> predecessors;

    distances[start_node] = 0;

    processed.push_back(start_node);

    for (int i = 1; i < adj_matrix.size(); i++) {
        not_processed.push_back(i);
    }

    for (auto node: not_processed) {
        predecessors[node] = start_node;

        if (adj_matrix[start_node][node] > 0) {
            distances[node] = adj_matrix[start_node][node];
        } else {
            distances[node] = INT_MAX;
        }
    }

    while (!not_processed.empty()) {
        int min = INT_MAX;
        int min_node;
        for (auto u: not_processed) {
            if (min > distances[u]) {
                min = distances[u];
                min_node = u;
            }
        }

        not_processed.erase(std::find(not_processed.begin(), not_processed.end(), min_node));
        processed.push_back(min_node);



        for (int i = 0; i < adj_matrix[min_node].size(); i++) {
            if (adj_matrix[min_node][i] != 0 && distances[min_node] + adj_matrix[min_node][i] < distances[i]) {
                distances[i] = distances[min_node] + adj_matrix[min_node][i];
                predecessors[i] = min_node;
            }
        }
    }
    

    return distances[end_node];
}

int get_id(int i, int j, const vector<vector<int>> &matrix) {
    return i * matrix[i].size() + j;
}

int main(void) {
    freopen("input2.txt", "r", stdin);

    string s;
    vector<vector<int>> risk_map;
    while (getline(cin, s)) {
        vector<int> row;
        for (char c: s) {
            row.push_back(c - '0');
        }
        risk_map.push_back(row);
    }

    int n = risk_map.size() * risk_map[0].size();
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    // Add edges to adj_matrix
    for (int i = 0; i < risk_map.size(); i++) {
        for (int j = 0; j < risk_map[i].size(); j++) {
            if (j+1 < risk_map[i].size()) {
                adj_matrix[get_id(i, j, risk_map)][get_id(i, j+1, risk_map)] = risk_map[i][j+1];
            }
            if (j-1 >= 0) {
                adj_matrix[get_id(i, j, risk_map)][get_id(i, j-1, risk_map)] = risk_map[i][j-1];
            }
            if (i+1 < risk_map.size()) {
                adj_matrix[get_id(i, j, risk_map)][get_id(i+1, j, risk_map)] = risk_map[i+1][j];
            }
            if (i-1 >= 0) {
                adj_matrix[get_id(i, j, risk_map)][get_id(i-1, j, risk_map)] = risk_map[i-1][j];
            }
        }
    }

    int shortest_path_length = dijkstra_shortest_path(adj_matrix, 0, n - 1);
    cout << shortest_path_length << endl;

}
