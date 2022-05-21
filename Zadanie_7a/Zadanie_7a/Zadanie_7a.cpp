#include <iostream>

using namespace std;
#define COLORAMOUNT 6
#define CARDAMOUNT 20
#define MAXLINESIZE 1000
int main()
{
    char c;
    char colors[COLORAMOUNT] = { 'b', 'r', 'v', 'y', 'w', 'b' };
    const char* fullcolor[COLORAMOUNT] = { "blue", "red", "violet", "yellow", "white", "black" };

    char table[CARDAMOUNT + 2][MAXLINESIZE];
    int a = 0;
    int b = 0;
    int actplay = -100;
    int saveNum;
    char saveColor[COLORAMOUNT + 1];
    int playnum;
    int indexact = 0;
    while (cin.get(c)) {
        if (a == actplay * 2 + 1 && c == ':') {
            table[a][b] = c;
            b++;
            cin.get(c);
            cin.get(c);
            saveNum = c - '0';
            cin.get(c);
            while (isdigit(c)) {
                saveNum *= 10 + (c - '0');
                cin.get(c);
            }
            int counter = 0;
            cin.get(c);
            while (c != ' ') {
                saveColor[counter] = c;
                counter++;
                cin.get(c);
            }
            saveColor[counter] = '\n';

        }
        table[a][b] = c;
        if (a == 0 && isdigit(c)) {
            table[a][b]++;
            actplay = c - '0';
            indexact = b;
        }
        else if (a == 1 && isdigit(c)) {
            playnum = c - '0';
            if (actplay + 1 > playnum) {
                table[0][indexact] = '1';
            }
        }

        if (c == '\n') {
            a++;
            b = 0;
        }
        else b++;

    }
    table[a][b] = cin.eof();


    for (int i = 0; i < 3 + 2 * playnum; i++) {
        for (int j = 0; j < MAXLINESIZE; j++) {
            cout << table[i][j];
            if (table[i][j] == '\n') break;
        }
    }
    bool notAdded = true;
    bool found = false;
    for (int i = 3 + 2 * playnum; i <= a; i++) {
        found = false;
        bool checknum = false;
        for (int j = 0; j < MAXLINESIZE; j++) {
            if (table[i][j] == ':') checknum = true;
            if (saveColor[0] == 'g' && notAdded) {
                found = true;
                notAdded = false;
            }
            else if (checknum && notAdded) {
                if (table[i][j] == ' ') {
                    if (table[i][j + 3] == saveColor[2]) {
                        found = true;
                        notAdded = false;
                    }
                }
            }
            if (table[i][j] == cin.eof()) break;
            if (table[i][j] == '\n' && found) {
                found = false;

                cout << " " << saveNum << " ";
                int counter = 0;
                while (saveColor[counter] != '\n') {
                    cout << saveColor[counter];
                    counter++;
                }

            }
            cout << table[i][j];
            if (table[i][j] == '\n')break;

        }
    }
    if (found) {
        cout << " " << saveNum << " ";
        int counter = 0;
        while (saveColor[counter] != '\n') {
            cout << saveColor[counter];
            counter++;
        }
    }
    return 0;
}