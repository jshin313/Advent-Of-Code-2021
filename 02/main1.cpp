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
    while (cin >> s >> x) {
        cout << s << " " << x << endl;
        if (!s.compare("forward")) {
            hor+=x;
        } else if (!s.compare("down")) {
            depth+=x;
        } else if (!s.compare("up")) {
            depth-=x;
        }

    }
    cout <<"Depth: "  << depth << endl;
    cout <<"Horizontal: "  << hor << endl;
    cout << depth * hor << endl;

}
