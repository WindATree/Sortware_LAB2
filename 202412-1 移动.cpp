#include <iostream>
using namespace std;

bool isOutOfBounds(int n, int x, int y) {
    return x < 1 || x > n || y < 1 || y > n;
}

void processCommands(int n, int x, int y, const string& commands) {
    for (char cmd : commands) {
        int newX = x, newY = y;
        switch (cmd) {
        case 'f': newY++; break;
        case 'b': newY--; break;
        case 'l': newX--; break;
        case 'r': newX++; break;
        default: break; 
        }
        if (!isOutOfBounds(n, newX, newY)) {
            x = newX;
            y = newY;
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        string commands;
        cin >> x >> y >> commands;
        processCommands(n, x, y, commands);
    }
    return 0;
}