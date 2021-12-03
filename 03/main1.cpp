#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    vector<int> input;
    string s;
    vector<string> strings;

    while (cin >> s) {
        strings.push_back(s);
    }

    int n = strings[0].size();

    vector<int> gamma(n, 0);
    vector<int> epsilon(n, 0);
    int ones = 0;
    int zeroes = 0;
    for (int i = 0; i < n; i++) {
        ones = 0;
        zeroes = 0;
        for (auto str: strings) {
            if (str[i] == '1') {
                ones++;
            } else {
                zeroes++;
            }
        }
        if (ones > zeroes) {
            gamma[i] = 1;
            epsilon[i] = 0;
        } else {
            gamma[i] = 0;
            epsilon[i] = 1;
        }
    }

    for (auto c: gamma) {
        cout << c;
    }
    cout << endl;

    for (auto c: epsilon) {
        cout << c;
    }
    cout << endl;
}
