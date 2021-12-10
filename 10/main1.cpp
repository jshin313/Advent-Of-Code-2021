#include <bits/stdc++.h>

using namespace std;


int get_error_score(const string & s) {
    unordered_map<char, int> points = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
    unordered_map<char, char> matching = {{')', '('}, {']', '['}, {'>', '<'}, {'}', '{'}};

    stack<int> stk;
    for (auto c: s) {
        if (matching.find(c) != matching.end()) {
            if (matching[c] != stk.top()) {
                return points[c];
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    int score = 0;

    string s;
    while (getline(cin, s)) {
        /* cout << s; */
        score += get_error_score(s);
    }
    cout << score << endl;
}
