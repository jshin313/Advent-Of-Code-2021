
#include <bits/stdc++.h>

using namespace std;

constexpr int GUESS = 500;
constexpr int STEP = 500;

int y(int v_y_0, int t) {
    int v_y = v_y_0;
    int y_coord = 0;
    for (int i = 0; i < t; i++) {
        y_coord += v_y;
        v_y--;
    }

    return y_coord;
}

int x(int v_x_0, int t) {
    int v_x = v_x_0;
    int x_coord = 0;
    for (int i = 0; i < t; i++) {
        x_coord += v_x;
        if (v_x > 0) {
            v_x--;
        } else {
            v_x++;
        }
    }

    return x_coord;
}

int find_max_y(int v_x_0, int v_y_0) {
    int max_y = 0;
    for (int step = 0; step < STEP; step++) {
        int y_coord = y(v_y_0, step);
        if (y_coord < max_y) {
            break;
        } else {
            max_y = y_coord;
        }
    }

    return max_y;
}

int main(void) {

    int x_1 = 207, x_2 = 263;
    int y_1 = -115, y_2 = -63;
    /* int x_1 = 20, x_2 = 30; */
    /* int y_1 = -10, y_2 = -5; */

    int max_y = 0;

    for (int v_y_0 = 0; v_y_0 < GUESS; v_y_0++) {
        for (int v_x_0 = 0; v_x_0 < GUESS; v_x_0++) {
            for (int step = 0; step < STEP; step++) {
                if (y(v_y_0, step) >= y_1 && y(v_y_0, step) <= y_2 
                        && x(v_x_0, step) >= x_1 && x(v_x_0, step) <= x_2)  {
                    cout << v_x_0 << ", " << v_y_0 << endl;

                    max_y = max(max_y, find_max_y(v_x_0, v_y_0));
                    cout << max_y << endl;
                }
            }
        }
    }

    cout << max_y << endl;
}
