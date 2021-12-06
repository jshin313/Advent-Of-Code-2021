#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    string s;
    cin >> s;

    vector<int> fishes;

    // Assumes single digit numbers separated by comma
    for (auto c: s) {
        if (c != ',') {
            fishes.push_back(c - '0');
        }
    }


    constexpr int DAYS = 256;

    unordered_map<int, long long> hmap;

    for (int i = 0; i <= 8; i++) {
        hmap[i]= 0;
    }
    
    for (auto fish: fishes) {
        if (hmap.find(fish) == hmap.end()) {
            hmap[fish] = 0;
        } else {
            hmap[fish]++;
        }
    }

    long long fish_count = fishes.size();
    for (int day = 0; day < DAYS; day++) {
        long long new_fish_count = hmap[0];
        fish_count += new_fish_count;

        for (int i = 0; i < 8; i++) {
            hmap[i] = hmap[i + 1];
        }

        hmap[8] = new_fish_count;
        hmap[6] += new_fish_count;

        /* cout << day << ": "; */
        /* for (auto it: hmap) { */
        /*     for (int i = 0; i < it.second; i++) { */
        /*         cout << it.first << " "; */
        /*     } */
        /* } */
        /* cout << endl; */ 
    }
    cout << fish_count << endl;


}
