#include <bits/stdc++.h>

using namespace std;

int num_depth_increase(vector<int> &depths)
{
    int prev_depth = depths[0];
    int count = 0;
    for (int i = 1; i < depths.size(); i++) {
        int diff = depths[i] - prev_depth;
        if (diff > 0) {
            count++;
        }
        prev_depth = depths[i];
    }
    return count;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    vector<int> input;
    int x;
    while (cin >> x) {
        input.push_back(x);
    }

    /* for (auto c: input) { */
    /*     cout << c << endl; */
    /* } */
    cout << num_depth_increase(input) << endl;

}
