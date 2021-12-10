#include <bits/stdc++.h>

using namespace std;

unsigned long get_error_score(const string &s) {
    unordered_map<char, char> matching = {{')', '('}, {']', '['}, {'>', '<'}, {'}', '{'}};

    stack<int> stk;
    for (auto c: s) {
        if (matching.find(c) != matching.end()) {
            if (matching[c] != stk.top()) {
                return 0;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    unordered_map<char, int> points = {{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};
    unsigned long score = 0;
    while (!stk.empty()) {
        score *= 5;
        score += points[stk.top()];
        stk.pop();
    }

    return score;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    vector<unsigned long> scores;

    string s;
    while (getline(cin, s)) {
        unsigned long score = get_error_score(s);
        if (score != 0) {
            scores.push_back(score);
            /* cout << score << endl; */
        }
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size() /2] << endl;
}
