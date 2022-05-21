#include <iostream>

using namespace std;

int playerArr[6];
int pile[6];
int pileColor[6];
int isSame[6];
int main()
{
    char c;
    char colors[6] = { 'b', 'r', 'v', 'y', 'w', 'b' };
    const char* fullcolor[6] = { "blue", "red", "violet", "yellow", "white", "black" };
    int activePlayer;
    int eT;
    int currline = 0;
    int playNum;
    int number;
    char prevchar[6];


    while (cin.get(c)) {
        if (isdigit(c)) {
            number = c - '0';
            cin.get(c);
            while (isdigit(c)) {
                number *= 10 + (c - '0');
                cin.get(c);
            }
            if (currline == 0) {
                activePlayer = number;
            }
            else if (currline == 1) {
                playNum = number;
            }
            else if (currline == 2) {
                eT = number;
            }
            else if (currline > 2 && currline <= (2 + 2 * playNum)) {
                playerArr[(currline - 1) / 2 - 1]++;
            }
            else {

                while (cin.get(c)) {
                    if (c != ' ') break;

                }
                for (int i = 0; i < 6; i++) {
                    if (colors[i] == c) {
                        cin.get(c);
                        cin.get(c);
                        if (c == fullcolor[i][2]) {
                            if (pileColor[(currline - (3 + 2 * playNum))] == 1) {
                                if (prevchar[(currline - (3 + 2 * playNum))] != c) {
                                    isSame[(currline - (3 + 2 * playNum))] = 1;
                                }
                            }

                            pileColor[(currline - (3 + 2 * playNum))] = 1;
                            prevchar[(currline - (3 + 2 * playNum))] = c;

                        }
                        else if (c == 'a') {
                            if (pileColor[(currline - (3 + 2 * playNum))] == 1) {
                                if (prevchar[(currline - (3 + 2 * playNum))] != c) {
                                    isSame[(currline - (3 + 2 * playNum))] = 1;
                                }
                            }
                            pileColor[(currline - (3 + 2 * playNum))] = 1;
                            prevchar[(currline - (3 + 2 * playNum))] = c;

                        }

                        break;

                    }
                }
                pile[(currline - (3 + 2 * playNum))] += number;
            }
        }

        if (c == '\n') {
            currline++;
            if (currline >= 3) {
                while (cin.get(c)) {
                    if (c == ':')break;
                }
            }

        }


    }
 
    bool one = true;
    bool two = true;
    bool three = true;
    for (int i = 1; i < 6; i++) {
        if (playerArr[i] != 0) {
            if (playerArr[i] != playerArr[i - 1]) {
                if (activePlayer == i + 1 || activePlayer == i) {
                    if (playerArr[i] - playerArr[i - 1] <= 1 && playerArr[i] - playerArr[i - 1] >= -1) {
                        continue;
                    }
                }
                cout << "The number of players cards on hand is wrong" << endl;
                one = false;
                break;
            }
        }

    }
    for (int i = 0; i < 6; i++) {
        if (isSame[i] == 1) {
            cout << "Two different colors were found on the " << i + 1 << " pile" << endl;
            two = false;
        }

    }
    for (int i = 0; i < 6; i++) {
        if (pile[i] > eT) {
            cout << "Pile number " << i + 1 << " should explode earlier" << endl;
            three = false;
        }

    }
    if ((one && two && three)) {
        cout << "Current state of the game is ok";
    }
    return 0;
}