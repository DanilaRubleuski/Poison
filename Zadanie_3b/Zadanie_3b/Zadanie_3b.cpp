#include <iostream>

using namespace std;

int main()
{
    char c;
    while (cin.get(c)) {
        if (c == '\n') break;

    }
    int n = 0;
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
    int currpile = 1;
    int lines = 0;
    while (cin.get(c)) {
        if (isdigit(c)) {
            while (cin.get(c))if (!isdigit(c)) break;
            lines++;
        }
        if (c == '\n') {
            cout << "there are " << lines - 1 << " cards on " << currpile << " pile" << endl;
            currpile++;
            lines = 0;
        }
    }
    cout << "there are " << lines - 1 << " cards on " << currpile << " pile" << endl;

    return 0;
}