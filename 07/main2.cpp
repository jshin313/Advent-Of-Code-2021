#include <bits/stdc++.h>

using namespace std;

int get_cost(int i, const vector<int> & crab_pos) {
    int fuel = 0;
    for (auto pos: crab_pos) {
        int dist = abs(pos - i);
        int cost = dist*(dist + 1) / 2;
        fuel += cost;
    }

    /* cout << fuel << endl; */
    return fuel;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    string s;
    cin >> s;
    std::stringstream ss(s);

    vector<int> crab_pos;

    int max_pos = 0;
    int min_pos = INT_MAX;

    for (int i; ss >> i;) {
        max_pos = max(max_pos, i);
        min_pos = min(min_pos, i);

        crab_pos.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }


    int min_cost = INT_MAX;
    for (int i = min_pos; i <= max_pos; i++) {
        min_cost = min(get_cost(i, crab_pos), min_cost);
    }

    cout << min_cost << endl;
}
