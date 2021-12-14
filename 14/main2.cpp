
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    freopen("input2.txt", "r", stdin);

    string polytemplate;
    cin >> polytemplate;
    cout << polytemplate << endl;

    unordered_map<string, char> insert_rule;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (getline(cin, s)) {
            string delim = " -> ";
            int pos = s.find(delim);
            string pairs = s.substr(0, pos);
            string to_insert = s.substr(pos + delim.size());
            insert_rule[pairs] = to_insert[0];
            /* cout << pairs << " " << insert_rule[pairs] << endl; */
    }
    unordered_map<string, unsigned long> uninserted_pairs;

    unordered_map<char, unsigned long> occurences;
    occurences[polytemplate[0]]++;
    for (int i = 0; i < polytemplate.size() - 1; i++) {
        string window = {polytemplate[i], polytemplate[i+1]};
        uninserted_pairs[window]++;
        occurences[polytemplate[i+1]]++;
    }

    for (int i = 0; i < 40; i++) {
        unordered_map<string, unsigned long> uninserted_pairs_tmp;
        for (auto it: uninserted_pairs) {
            string pair1 = {it.first[0], insert_rule[it.first]};
            string pair2 = {insert_rule[it.first], it.first[1]};

            occurences[insert_rule[it.first]]+=it.second;

            uninserted_pairs_tmp[pair1]+=it.second;
            uninserted_pairs_tmp[pair2]+=it.second;
            uninserted_pairs[it.first]-=it.second;


        }
        for (auto it2: uninserted_pairs_tmp) {
            uninserted_pairs[it2.first]+=it2.second;
        }
    }


    unsigned long max_occ = 0;
    unsigned long min_occ = ULONG_MAX;

    for (auto it: occurences) {
        if (max_occ < it.second) {
            max_occ = it.second;
        }
        if (min_occ > it.second) {
            min_occ = it.second;
        }
    }

    cout << max_occ - min_occ << endl;
}
