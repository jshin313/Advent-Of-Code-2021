#include <bits/stdc++.h>

using namespace std;

unsigned long get_error_score(string s) {
    stack<int> stk;
    for (auto c: s) {
        if (c == ')') {
            if (stk.top() != '(') {
                return 0;
            }
            stk.pop();
        } else if (c == ']') {
            if (stk.top() != '[') {
                return 0;
            }
            stk.pop();
        } else if (c == '}') {
            if (stk.top() != '{') {
                return 0;
            }
            stk.pop();
        } else if (c == '>') {
            if (stk.top() != '<') {
                return 0;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }


    unsigned long score = 0;
    while (!stk.empty()) {
        switch (stk.top()) {
            case '[':
                score *= 5;
                score +=2;
                break;
            case '(':
                score *= 5;
                score += 1;
                break;
            case '{':
                score *= 5;
                score+= 3;
                break;
            case '<':
                score *= 5;
                score += 4;
                break;
        }
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
