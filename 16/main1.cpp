
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

int get_literal(const vector<int>& transmission, int &bit_pos) {
    bool last_group = false;
    int literal = 0;
    while (!last_group) {
        last_group = transmission[bit_pos] == 0;
        int tmp_literal = bin_to_int(transmission, bit_pos+1, bit_pos+5);
        literal <<= 4;
        literal += tmp_literal;
        bit_pos+=5;
    }

    return literal;
}

int parse_transmission(const vector<int>& transmission, int &bit_pos, int end) {
    int ver_nums = 0;

    int pack_ver = bin_to_int(transmission, bit_pos, bit_pos + 3);
    int pack_type = bin_to_int(transmission, bit_pos + 3, bit_pos + 6);
    cout << "Packet Version: " << pack_ver << endl;
    cout << "Packet Type: " << pack_type << endl;

    ver_nums += pack_ver;

    bit_pos += 6;

    if (pack_type == 4) {
        int literal_val = get_literal(transmission, bit_pos);
        cout << "Literal val: " << literal_val << endl;
        return ver_nums;
    }

    int length_type_id = transmission[bit_pos];
    bit_pos++;
    int num_sub_packets = 0;
    int total_len = 0;

    switch (length_type_id) {
        case 0: 
            {
                total_len = bin_to_int(transmission, bit_pos, bit_pos+15);
                cout << "Length of sub packet: "  << total_len << endl;
                bit_pos+=15;
                end = bit_pos + total_len;
                while (bit_pos < end && bit_pos < transmission.size()) {
                    ver_nums += parse_transmission(transmission, bit_pos, end);
                }
                break;
            }
        case 1:
            {
                num_sub_packets = bin_to_int(transmission, bit_pos, bit_pos+11);
                bit_pos+=11;
                cout << "Number of sub packets: "  << num_sub_packets << endl;

                for (int i = 0; i < num_sub_packets; i++) {
                    ver_nums += parse_transmission(transmission, bit_pos, end);
                    /* cout << "Bit pos: " << bit_pos << endl; */
                }

                break;
            }
        default:
            // throw exception
            break;
    }
    


    return ver_nums;
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
