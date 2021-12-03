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
        gamma[i] = ones > zeroes;
        epsilon[i] = !gamma[i];
    }

    for (auto g: gamma) {
        cout << g;
    }
    cout << endl;

    for (auto e: epsilon) {
        cout << e;
    }
    cout << endl;
}
