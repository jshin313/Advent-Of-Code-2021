#include <bits/stdc++.h>

using namespace std;

void printVector(vector<string> &v) {
    cout << endl;
    cout << endl;
    for (auto c: v) {
        cout << c << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

int one_or_zero(vector<string>& strs, int i) {
    int ones = 0;
    int zeroes = 0;
    for (auto str: strs) {
        if (str[i] == '0') {
            zeroes++;
        } else {
            ones++;
        }
    }

    if (ones > zeroes) {
        return 1;
    } else if (ones < zeroes) {
        return 0;
    } else {
        return -1;
    }
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    vector<int> input;
    string s;
    vector<string> strings;
    vector<string> strings2;

    while (cin >> s) {
        strings.push_back(s);
        strings2.push_back(s);
    }

    int n = strings[0].size();

    // oxygen
    for (int i = 0; i < n; i++) {
        int curr_digit = one_or_zero(strings, i);
        if (curr_digit == -1){
            curr_digit = 1;
        }
        for (auto it = strings.begin(); it != strings.end();) {

            auto str = *it;
            if (strings.size() == 1) {
                cout << *strings.begin() << endl;
                goto end1;
            }

            if (str[i] - '0' != curr_digit) {
                it = strings.erase(it);
            } else {
                it++;
            }
        }
        if (strings.size() == 1) {
            cout << *strings.begin() << endl;
            break;
        }
    }
    
end1:
    cout << endl;
    // co2
    for (int i = 0; i < n; i++) {
        int curr_digit = one_or_zero(strings2, i);
        if (curr_digit == -1) {
            curr_digit = 0;
        } else {
            curr_digit = !curr_digit;
        }

        for (auto it = strings2.begin(); it != strings2.end();) {
            auto str = *it;
            if (strings2.size() == 1) {
                cout << *strings2.begin() << endl;
                goto end2;
            }

            if (str[i] - '0' != curr_digit) {
                it = strings2.erase(it);
            } else {
                it++;
            }
        }
        if (strings2.size() == 1) {
            cout << *strings2.begin() << endl;
            break;
        }
    }
end2:
    cout << endl;
}
