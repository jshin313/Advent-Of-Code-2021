
#include <bits/stdc++.h>

using namespace std;

int nibble_to_int(char nibble) {
    if (nibble >= '0' && nibble <= '9') {
        return nibble - '0';
    }
    if (nibble >= 'A' && nibble <= 'F') {
        return nibble - 'A' + 10;
    }

    // throw exception
}

int bin_to_int(const vector<int>& v, int bit_pos, int end) {
    int return_value = 0;
    for (int i = bit_pos; i < end; i++) {
        return_value *= 2;
        return_value += v[i];
    }
    return return_value;
}

unsigned long get_literal(const vector<int>& transmission, int &bit_pos) {
    bool last_group = false;
    unsigned long literal = 0;
    while (!last_group) {
        last_group = transmission[bit_pos] == 0;
        int tmp_literal = bin_to_int(transmission, bit_pos+1, bit_pos+5);
        literal <<= 4;
        literal += tmp_literal;
        bit_pos+=5;
    }

    return literal;
}

unsigned long parse_transmission(const vector<int>& transmission, int &bit_pos, int end) {
    unsigned long return_val = 0;

    int pack_ver = bin_to_int(transmission, bit_pos, bit_pos + 3);
    int pack_type = bin_to_int(transmission, bit_pos + 3, bit_pos + 6);
    cout << "Packet Version: " << pack_ver << endl;
    cout << "Packet Type: " << pack_type << endl;

    bit_pos += 6;

    std::function<unsigned long(unsigned long, unsigned long)> op;

    int num_sub_packets = 0;

    switch (pack_type) {
        case 0:
            {
                op = std::plus<>();
                break;
            }
        case 1:
            {
                op = std::multiplies<>();
                return_val = 1;
                break;
            }
        case 2:
            {
                op = [] (unsigned long a, unsigned long b) { return min(a, b); };
                return_val = ULONG_MAX;
                break;
            }
        case 3:
            {
                op = [] (unsigned long a, unsigned long b) { return max(a, b); };
                break;
            }
        case 4: 
            {
                unsigned long literal_val = get_literal(transmission, bit_pos);
                cout << "Literal val: " << literal_val << endl;
                return literal_val;
            }
        case 5:
            {
                op = [] (unsigned long a, unsigned long b) { return a > b; };
                num_sub_packets = 2;
                break;
            }
        case 6:
            {
                op = [] (unsigned long a, unsigned long b) { return a < b; };
                num_sub_packets = 2;
                break;
            }
        case 7:
            {
                op = [] (unsigned long a, unsigned long b) { return a == b; };
                num_sub_packets = 2;
                break;
            }
    }

    int length_type_id = transmission[bit_pos];
    bit_pos++;
    int total_len = 0;


    switch (length_type_id) {
        case 0: 
            {
                total_len = bin_to_int(transmission, bit_pos, bit_pos+15);
                cout << "Length of sub packet: "  << total_len << endl;
                bit_pos+=15;
                end = bit_pos + total_len;

                if (num_sub_packets == 2) {
                    unsigned long lit1 = parse_transmission(transmission, bit_pos, end);
                    unsigned long lit2 = parse_transmission(transmission, bit_pos, end);
                    return op(lit1, lit2);
                }

                while (bit_pos < end) {
                    return_val = op(return_val, parse_transmission(transmission, bit_pos, end));
                }
                break;
            }
        case 1:
            {
                num_sub_packets = bin_to_int(transmission, bit_pos, bit_pos+11);
                bit_pos+=11;
                cout << "Number of sub packets: "  << num_sub_packets << endl;

                if (num_sub_packets == 2) {
                    unsigned long lit1 = parse_transmission(transmission, bit_pos, end);
                    unsigned long lit2 = parse_transmission(transmission, bit_pos, end);
                    return op(lit1, lit2);
                }

                for (int i = 0; i < num_sub_packets; i++) {
                    return_val = op(return_val, parse_transmission(transmission, bit_pos, end));
                }

                break;
            }
        default:
            // throw exception
            break;
    }
    


    return return_val;
}

int main(void) {
    freopen("input2.txt", "r", stdin);

    string s;
    getline(cin, s);

    vector<int> transmission(s.size() * 4, 0);
    int bit = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int nibble = nibble_to_int(s[i]);
        int mask = 0b1000;
        while (mask != 0) {
            transmission[bit] = (bool)(nibble & mask);
            bit++;
            mask >>= 1;
        }
    }

    for (auto bit: transmission) {
        cout << bit << " ";
    }
    cout << endl;

    int bit_pos = 0;
    cout << parse_transmission(transmission, bit_pos, transmission.size()) << endl;
}
