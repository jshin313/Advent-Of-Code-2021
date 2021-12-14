
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    freopen("input2.txt", "r", stdin);

    string polytemplate;
    cin >> polytemplate;
    cout << polytemplate << endl;

    unordered_map<string, char> hmap;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (getline(cin, s)) {
            string delim = " -> ";
            int pos = s.find(delim);
            string pairs = s.substr(0, pos);
            string to_insert = s.substr(pos + delim.size());
            hmap[pairs] = to_insert[0];
            /* cout << pairs << " " << hmap[pairs] << endl; */
    }
    for (int cntr = 0; cntr < 40; cntr++) {
        string new_polymer = "";
        for (int i = 0; i < polytemplate.size() - 1; i++) {
            string window = "";
            window += polytemplate[i];
            window += polytemplate[i+1];
            /* cout << window << endl; */
            new_polymer += polytemplate[i];
            if (hmap.find(window) != hmap.end()) {
                new_polymer += hmap[window];
            }
        }
        new_polymer += polytemplate[polytemplate.size() - 1];
        polytemplate =  new_polymer;
        cout << "Step " << cntr +1  << ": " << polytemplate << endl;
    }

    unordered_map<char, int> occurences;
    for (auto c: polytemplate) {
        if (occurences.find(c) == occurences.end()) {
            occurences[c] = 1;
        } else {
            occurences[c]++;
        }
    }

    int max_occ = 0;
    int min_occ = INT_MAX;

    for (auto it: occurences) {
        max_occ = max(max_occ, it.second);
        min_occ = min(min_occ, it.second);
    }

    cout << max_occ - min_occ << endl;
}
