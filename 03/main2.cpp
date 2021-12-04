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

string oxygen(vector<string> strings) {
    // oxygen
    int n = strings[0].size();

    for (int i = 0; i < n; i++) {
        int curr_digit = one_or_zero(strings, i);
        if (curr_digit == -1){
            curr_digit = 1;
        }
        for (auto it = strings.begin(); it != strings.end();) {

            auto str = *it;
            if (strings.size() == 1) {
                return *strings.begin();
            }

            if (str[i] - '0' != curr_digit) {
                it = strings.erase(it);
            } else {
                it++;
            }
        }
        if (strings.size() == 1) {
            return *strings.begin();
        }
    }
    return nullptr;
}


string co2(vector<string> strings) {

    int n = strings[0].size();
    // co2
    for (int i = 0; i < n; i++) {
        int curr_digit = one_or_zero(strings, i);
        if (curr_digit == -1) {
            curr_digit = 0;
        } else {
            curr_digit = !curr_digit;
        }

        for (auto it = strings.begin(); it != strings.end();) {
            auto str = *it;
            if (strings.size() == 1) {
                return *strings.begin();
            }

            if (str[i] - '0' != curr_digit) {
                it = strings.erase(it);
            } else {
                it++;
            }
        }
        if (strings.size() == 1) {
            return *strings.begin();
        }
    }
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    vector<int> input;
    string s;
    vector<string> strings;

    while (cin >> s) {
        strings.push_back(s);
    }

    cout << oxygen(strings) << endl;
    cout << co2(strings) << endl;
}
