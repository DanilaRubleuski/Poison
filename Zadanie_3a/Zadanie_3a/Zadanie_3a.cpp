#include <iostream>

using namespace std;

int main()
{
    char c;
    while (cin.get(c)) {
        if (c == '\n') break;

    }
    int n;
    while (cin.get(c)) {
        if (isdigit(c)) n = c - '0';
        if (c == '\n') break;
    }


    for (int currplayer = 1; currplayer <= n; currplayer++) {
        int amount = 0;
        while (cin.get(c)) {
            if (isdigit(c)) {
                while (cin.get(c))if (!isdigit(c)) break;
                amount++;
            }
            if (c == '\n') break;
        }
        cout << currplayer << " player has " << amount - 1 << " cards on hand" << endl;

        amount = 0;
        while (cin.get(c)) {
            if (isdigit(c)) {
                while (cin.get(c))if (!isdigit(c)) break;
                amount++;
            }
            if (c == '\n') break;
        }
        cout << currplayer << " player has " << amount - 1 << " cards in front of him" << endl;
    }


    return 0;
}