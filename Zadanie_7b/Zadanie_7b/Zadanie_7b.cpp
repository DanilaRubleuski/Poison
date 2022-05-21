#include <iostream>

#define MAXLINESIZE 1000
#define MAXLINES 20 // calculated from max amount of lines from number of players and number of colors based on the parameters given
#define COLORAMOUNT 6
using namespace std;


int totalnumber;
int sumnumber[100];
char colorindex[100];
int firstnum;
int numcounter;

int main()
{
    char c;
    char table[MAXLINES + 2][MAXLINESIZE]; //moved by two to avoid index error
    int a = 0;
    int b = 0;
    int currline = 0;
    int activeplayer, playernum, et;
    char colors[COLORAMOUNT + 1] = { 'e', 'u', 'd', 'o', 'l', 'i', 'a' };
    const char* fullcolor[COLORAMOUNT + 1] = { "green", "blue", "red", "violet", "yellow", "white", "black" };
    char firstcolor = 0;
    int pileLine;
    while (cin.get(c)) {
        if (isdigit(c)) {
            int tempnum = c - '0';
            table[a][b] = c;
            b++;
            cin.get(c);

            while (isdigit(c)) {
                tempnum *= 10 + c - '0';
                table[a][b] = c;
                b++;
                cin.get(c);


            }
            if (currline == 0) {
                activeplayer = tempnum;
            }
            else if (currline == 1) {
                playernum = tempnum;
            }
            else if (currline == 2) {
                et = tempnum;
            }
            else if (currline == 1 + 2 * activeplayer) {
                while (c == ' ') {
                    table[a][b] = c;
                    b++;
                    cin.get(c);


                }
                if (c != 'p') {
                    table[a][b] = c;
                    b++;
                    cin.get(c);
                    table[a][b] = c;
                    b++;
                    cin.get(c);

                }

                for (int i = 0; i < COLORAMOUNT + 1; i++) {
                    if (colors[i] == c && firstcolor == 0) {
                        totalnumber = tempnum;
                        firstnum = tempnum;
                        sumnumber[numcounter] = tempnum;
                        colorindex[numcounter] = c;
                        numcounter++;
                        firstcolor = c;
                        break;
                    }
                }
            }
            else if (currline > 2 * playernum + 2) {
                while (c == ' ') {
                    table[a][b] = c;
                    b++;
                    cin.get(c);


                }
                if (c != 'p') {
                    table[a][b] = c;
                    b++;
                    cin.get(c);
                    table[a][b] = c;
                    b++;
                    cin.get(c);


                }
                for (int i = 0; i < COLORAMOUNT + 1; i++) {
                    if (firstcolor == c || (pileLine == a && c == 'e')) {
                        totalnumber += tempnum;
                        sumnumber[numcounter] = tempnum;
                        colorindex[numcounter] = c;
                        numcounter++;
                        pileLine = a;
                        break;
                    }
                }
            }
            // table[a][b] = tempnum;
            // b++;
        }
        table[a][b] = c;
        b++;
        if (c == '\n') {
            currline++;
            a++;
            b = 0;
        }

    }
    table[a][b] = cin.eof();


    bool explosion = false;
    bool canremove = false;
    int actualColor;
    for (int i = 0; i < COLORAMOUNT + 1; i++) {
        if (fullcolor[i][2] == firstcolor) {
            actualColor = i;
            break;
        }
    }
    if (totalnumber > et) {
        explosion = true;
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j < MAXLINESIZE; j++) {
            if (table[i][j] == cin.eof()) return 0;
            if (i == 0) {
                if (isdigit(table[i][j])) {
                    table[i][j]++;
                    if (table[i][j] > playernum + '0') {
                        table[i][j] = '1';
                    }
                }
            }
            else if (i == 1 + 2 * activeplayer) {
                if (table[i][j] == ':') {
                    canremove = true;
                }
                if (canremove && isdigit(table[i][j])) {
                    while (isdigit(table[i][j])) {
                        j++;
                    }
                    while (table[i][j] == ' ') {
                        j++;
                    }
                    while (table[i][j] != ' ') {
                        j++;
                    }
                    j++;
                    canremove = false;
                }
            }
            else if ((i == 2 + 2 * activeplayer) && explosion) {
                while (table[i][j] != '\n') {
                    cout << table[i][j];
                    j++;
                }
                int tempcount = 1;
                cout << " ";
                while (sumnumber[tempcount]) {
                    if (colorindex[tempcount] == firstcolor)
                        cout << sumnumber[tempcount] << " " << fullcolor[actualColor] << " ";
                    else
                        cout << sumnumber[tempcount] << " " << "green" << " ";
                    tempcount++;
                }
                cout << sumnumber[0] << " " << fullcolor[actualColor];

            }
            else if (i == pileLine && explosion) {
                cout << pileLine - 2 * playernum - 2 << " pile cards:" << endl;
                break;
            }
            else if (i == pileLine) {
                while (table[i][j] != '\n') {
                    cout << table[i][j];
                    j++;
                }
                cout << sumnumber[0] << " " << fullcolor[actualColor];
            }
            cout << table[i][j];
            if (table[i][j] == '\n') break;
        }
    }


    return 0;
}