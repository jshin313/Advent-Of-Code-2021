#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    freopen("input1.txt", "r", stdin);

    string s;
    cin >> s;

    vector<int> fishes;

    // Assumes single digit numbers separated by comma
    for (auto c: s) {
        if (c != ',') {
            fishes.push_back(c - '0');
        }
    }


    constexpr int DAYS = 18;

    for (int day = 0; day < DAYS; day++) {
        int n = fishes.size();
        for (int i = 0; i < n; i++) {
            if (fishes[i] == 0) {
                fishes.push_back(8);
                fishes[i] = 6;
            } else {
                fishes[i]--;
            }
        }

        cout << day << ": ";
        sort(fishes.begin(), fishes.end(), greater<int>());
        for (auto fish: fishes) {
            cout << fish << " ";
        }
        cout << endl; 
    }

    cout << fishes.size() << endl;

}
