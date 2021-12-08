#include <bits/stdc++.h>

using namespace std;

int number_of_bits_set(unsigned long b) {
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (b & (1 << i)) {
            count++;
        }
    }
    return count;
}

void get_mapping(const vector<string> &digit_s) {
    unordered_map<int, unsigned long> hmap;
    for (auto digit: digit_s) {
        unsigned long freq = 0;
        for (auto c: digit) {
            freq |= 1 << (6 - (c % 7));
        }

        switch (digit.size()) {
            // 1
            case 2:
                hmap[1] = freq;
                break;
            // 7
            case 3:
                hmap[7] = freq;
                break;
            // 4
            case 4:
                hmap[4] = freq;
                break;
            // 8
            case 7:
                hmap[8] = freq;
                break;

        }


    }

    for (auto digit: digit_s) {
        unsigned long freq = 0;
        for (auto c: digit) {
            /* cout << (int)(c % 7) << endl; */
            freq |= 1 << (6 - (c % 7));
        }

        bool found = false;
        for (int j = 0; j <= 9; j++) {
            if (j == 2  || j == 5 || j == 6 || j == 3 || j == 9) {
                continue;
            }
            if (hmap[j] == freq) {
                cout << j;
                found = true;
                break;
            }
        }
        // will be 2, 5, 6, 3, 9, or 0
        if (!found) {
            if (digit.size() == 6) {
                if (number_of_bits_set(freq & hmap[4]) == 4) {
                    cout << 9;
                } else if (number_of_bits_set(freq & hmap[1]) == 1) {
                    cout << 6;
                } else {
                    cout << 0;
                }
            } else if (number_of_bits_set(freq & hmap[7]) == 3) {
                    cout << 3;
            } else if (number_of_bits_set(freq & hmap[7]) == 2 && number_of_bits_set(freq & hmap[4]) == 3) {
                cout << 5;
            } else if (number_of_bits_set(freq & hmap[4]) == 2) {
                cout << 2;
            } else {
                cout << digit;
                /* cout << " | "; */
            }
        }
        cout << "";

    }
    cout << endl;
}

int main(int argc, char **argv)
{
    freopen("input2.txt", "r", stdin);

    vector<string> lines;
    string s;
    while (getline(cin, s)) {
        lines.push_back(s);
    }

    for (auto line: lines) {
        vector<string> digit_s;
        std::stringstream ss(line);
        bool output = false;
        for (string s; ss >> s;) {
            /* if (!s.compare("|")) { */
            /*     output = true; */
            /* } else if (output) { */
                /* cout << s << endl; */
            digit_s.push_back(s);
            /* } */
        }

        get_mapping(digit_s);
    }

}
