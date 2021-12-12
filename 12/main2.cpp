#include <bits/stdc++.h>

using namespace std;

int lowercase_pairs_visited = 0;

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

void print_path(const vector<string> &visited) {
    for (auto node: visited) {
        cout << node << " ";
    }
    cout << endl;
}

int find_paths(string start_node, unordered_map<string, vector<string>> &adj_list, vector<string> &visited) {
    int count = 0;
    for (auto node: adj_list[start_node]) {
        visited.push_back(node);
        if (node == "end") {
            count++;
            /* print_path(visited); */
            /* cout << visited_two << endl; */
        } else {
            int tmp = lowercase_pairs_visited;
            if (is_lowercase(node) && std::count(visited.begin(), visited.end(), node) >= 2) {
                lowercase_pairs_visited++;
            } else {
                /* print_path(visited); */
                /* cout << is_lowercase(node) << " " << std::count(visited.begin(), visited.end(), node) << " "; */
                /* cout << node << " " << lowercase_pairs_visited << endl; */
            }
            if (!is_lowercase(node) || lowercase_pairs_visited <= 1) {
                count += find_paths(node, adj_list, visited);
            }
            lowercase_pairs_visited = tmp;
        }
        visited.pop_back();
    }

    return count;
}

int count_paths(unordered_map<string, vector<string>> &adj_list) {
    vector<string> visited;

    visited.push_back("start");
    return find_paths("start", adj_list, visited);
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

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

        if (first_node != "end" && second_node != "start") {
            if (adj_list.find(first_node) == adj_list.end()) {
                vector<string> v;
                adj_list[first_node] = v;
            }
            adj_list[first_node].push_back(second_node);
        }

        if (first_node != "start" && second_node != "end") {
            if (adj_list.find(second_node) == adj_list.end()) {
                vector<string> v;
                adj_list[second_node] = v;
            }
            adj_list[second_node].push_back(first_node);
        }
    }

    for (auto it: adj_list) {
        cout << it.first << ": ";
        for (auto elem: it.second) {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << count_paths(adj_list) << endl;

}
