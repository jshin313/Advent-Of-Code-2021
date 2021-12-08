#include <bits/stdc++.h>

using namespace std;

int get_count(vector<string> &digit_s) {
    int count = 0;
    for (auto digit: digit_s) {
        unordered_map<char, int> hmap;
        for (auto c: digit) {
            if (hmap.count(c) != 0) {
                hmap[c]++;
            } else {
                hmap[c] = 1;
            }
        }


        if (digit.size() == 2 || digit.size() == 3 || digit.size() == 4 || digit.size() == 7) {
            count++;
        }
    }

    return count;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    vector<string> lines;
    string s;
    while (getline(cin, s)) {
        lines.push_back(s);
    }

    int count = 0;

    for (auto line: lines) {
        vector<string> digit_s;
        std::stringstream ss(line);
        bool output = false;
        for (string s; ss >> s;) {
            if (!s.compare("|")) {
                output = true;
            } else if (output) {
                /* cout << s << endl; */
                digit_s.push_back(s);
            }
        }

        count += get_count(digit_s);
    }

    cout << count << endl;

}
