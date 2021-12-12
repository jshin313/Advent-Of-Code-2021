#include <bits/stdc++.h>

using namespace std;

bool is_lowercase(string node) {
    if (node == "start" || node == "end") {
        return false;
    }
    for (auto c: node) {
        if (!(c >= 'a' && c <= 'z')) {
            return false;
        }
    }
    return true;
}

int find_small_cave_paths(int &total, vector<string> &paths, bool has_small, string start_node, unordered_map<string, vector<string>> &adj_list, unordered_map<string, bool> &visited) {
    /* cout << start_node << " "; */
    visited[start_node] = true;
    paths.push_back(start_node);
    int count = 0;
    for (auto node: adj_list[start_node]) {
        if (node == "end") {
            if (has_small) {
                /* cout << " <-- count++"; */
                count++;
            }
            total++;

            paths.push_back(node);
            for (auto node: paths) {
                cout << node << " ";
            }
            cout << endl;
            paths.pop_back();
        } else {
            if (!(is_lowercase(node) && visited[node])) {
                count += find_small_cave_paths(total, paths, has_small, node, adj_list, visited);
                if (is_lowercase(node)) {
                    has_small = true;
                }
            }
        }
    }
    paths.pop_back();
    visited[start_node] = false;

    return count;
}

int count_small_cave_paths(unordered_map<string, bool> &visited, unordered_map<string, vector<string>> &adj_list) {
    vector<string> paths;
    int total = 0;
    int count = find_small_cave_paths(total, paths, false, "start", adj_list, visited);
    cout << total << endl;
    return count;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    unordered_map<string, bool> visited;

    string s;
    unordered_map<string, vector<string>> adj_list;
    while (getline(cin, s)) {
        string first_node = "";
        string second_node = "";

        int i;
        for (i = 0; i < s.size() && s[i] != '-'; i++) {
            first_node += s[i];
        }

        for (++i; i < s.size(); i++) {
            second_node += s[i];
        }

        if (adj_list.find(first_node) == adj_list.end()) {
            vector<string> adj_nodes;
            adj_list[first_node] = adj_nodes;
            visited[first_node] = false;
        }

        if (adj_list.find(second_node) == adj_list.end()) {
            vector<string> adj_nodes;
            adj_list[second_node] = adj_nodes;
            visited[second_node] = false;
        }

        if (first_node != "end" && second_node != "start") {
            adj_list[first_node].push_back(second_node);
        }

        if (second_node != "end" && first_node != "start") {
            adj_list[second_node].push_back(first_node);

        }

    }

    for (auto it: adj_list) {
        cout << it.first << ": ";
        for (auto elem: it.second) {
            cout << elem << ",";
        }
        cout << endl;
    }

    count_small_cave_paths(visited, adj_list);


}
