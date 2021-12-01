#include <bits/stdc++.h>

using namespace std;

int num_depth_increase(vector<int> &depths)
{
    int prev_sum = depths[0] + depths[1] + depths[2];
    int count = 0;
    for (int i = 1; i < depths.size(); i++) {
        int curr_sum = depths[i] + depths[i+1] + depths[i+2];
        int diff = curr_sum - prev_sum;
        if (diff > 0) {
            count++;
        }
        prev_sum = curr_sum;
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
