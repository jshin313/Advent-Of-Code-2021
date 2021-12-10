#include <bits/stdc++.h>

using namespace std;


int get_error_score(string s) {
    unordered_map<char, int> score;
    score[')'] = 3;
    score[']'] = 57;
    score['}'] = 1197;
    score['>'] = 25137;

    stack<int> stk;
    for (auto c: s) {
        if (c == ')') {
            if (stk.top() != '(') {
                return score[c];
            }
            stk.pop();
        } else if (c == ']') {
            if (stk.top() != '[') {
                return score[c];
            }
            stk.pop();
        } else if (c == '}') {
            if (stk.top() != '{') {
                return score[c];
            }
            stk.pop();
        } else if (c == '>') {
            if (stk.top() != '<') {
                return score[c];
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
