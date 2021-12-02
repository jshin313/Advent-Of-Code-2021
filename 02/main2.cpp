#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);
    vector<int> input;
    string s;
    int x;
    int depth = 0;
    int hor = 0;
    int aim = 0;
    while (cin >> s >> x) {
        cout << s << " " << x << endl;
        if (!s.compare("forward")) {
            hor+=x;
            depth += aim * x;
        } else if (!s.compare("down")) {
            aim+=x;
        } else if (!s.compare("up")) {
            aim-=x;
        }

    }

    cout <<"Depth: "  << depth << endl;
    cout <<"Horizontal: "  << hor << endl;
    cout << depth * hor << endl;

}
