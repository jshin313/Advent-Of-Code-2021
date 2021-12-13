#include <bits/stdc++.h>

using namespace std;

int count_dots(const vector<vector<char>> &graph) {
    int count = 0;
    for (auto row: graph) {
        for (auto elem: row) {
            if (elem == '#')  {
                count++;
            }
        }
    }
    return count;
}

void print_graph(const vector<vector<char>> &graph) {
    for (auto row: graph) {
        for (auto elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void mark(vector<vector<char>> &graph, int x, int y) {
    graph[y][x] = '#';
}

vector<vector<char>> fold_vert(vector<vector<char>> &graph, int line) {
    if (line < graph[0].size() / 2) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = line + 1; j <= 2 * line; j++) {
                if (graph[i][j] == '#') {
                    continue;
                }
                graph[i][j] = graph[i][line - (j - line)];
            }
        }

        vector<vector<char>> new_graph;
        for (int i = 0; i < graph.size(); i++) {
            vector<char> row;
            for (int j = line + 1; j <= graph[i].size(); j++) {
                row.push_back(graph[i][j]);
            }
            new_graph.push_back(row);
        }
        return new_graph;
    } else {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = line + 1; j < graph[i].size(); j++) {
                if (graph[i][line - (j - line)] == '#') {
                    continue;
                }
                graph[i][line - (j - line)] = graph[i][j];
            }
        }

        vector<vector<char>> new_graph;
        for (int i = 0; i < graph.size(); i++) {
            vector<char> row;
            for (int j = 0; j < line; j++) {
                row.push_back(graph[i][j]);
            }
            new_graph.push_back(row);
        }
        return new_graph;
    }
}

vector<vector<char>> fold_hor(vector<vector<char>> &graph, int line) {
    if (line < graph.size() / 2) {
        for (int i = line + 1; i <= 2 * line; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (graph[i][j] == '#') {
                    continue;
                }
                graph[i][j] = graph[line - (i - line)][j];
            }
        }

        vector<vector<char>> new_graph;
        for (int i = line + 1; i < graph.size(); i++) {
            vector<char> row;
            for (int j = 0; j < graph[i].size(); j++) {
                row.push_back(graph[i][j]);
            }
            new_graph.push_back(row);
        }
        return new_graph;
    } else {
        for (int i = line + 1; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (graph[line - (i - line)][j] == '#') {
                    continue;
                }
                graph[line - (i - line)][j] = graph[i][j];
            }
        }

        vector<vector<char>> new_graph;
        for (int i = 0; i < line; i++) {
            vector<char> row;
            for (int j = 0; j < graph[i].size(); j++) {
                row.push_back(graph[i][j]);
            }
            new_graph.push_back(row);
        }
        return new_graph;
    }
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    string s;
    vector<vector<int>> coordinates;
    vector<vector<int>> folds;

    int max_y = 0;
    int max_x = 0;
    while (getline(cin, s)) {

        string fold_delim = "fold along ";
        size_t pos = s.find(fold_delim);
        std::stringstream ss(s);
        if (pos == string::npos) {
            int x; ss >> x;
            ss.ignore();
            int y; ss >> y;
            /* cout << x << " " << y << endl; */
            vector<int> coor_pair{x, y};
            coordinates.push_back(coor_pair);

            max_x = max(max_x, x);
            max_y = max(max_y, y);
        } else {
            ss.ignore(256, '=');
            int line; ss >> line;

            char axis = s[pos + fold_delim.size()];
            /* cout << axis << "=" << line << endl; */
            vector<int> fold{axis, line};
            folds.push_back(fold);
        }
    }

    vector<vector<char>> graph;
    for (int i = 0; i < (max_y + 1); i++) {
        vector<char> row(max_x + 1, '.');
        graph.push_back(row);
    }
    for (auto coord: coordinates) {
        mark(graph, coord[0], coord[1]);
    }

    print_graph(graph);

    for (auto fold: folds) {
        if (fold[0] == 'x') {
            graph = fold_vert(graph, fold[1]);
        } else {
            graph = fold_hor(graph, fold[1]);
        }
        break;
    }

    print_graph(graph);
    cout << "Number of Dots Remaining: " << count_dots(graph) << endl;
}
