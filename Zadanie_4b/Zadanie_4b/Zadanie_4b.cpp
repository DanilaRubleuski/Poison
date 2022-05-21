#include <iostream>

using namespace std;

int colorAmounts[6];

int main()
{
    char c;
    char colors[6] = { 'b', 'r', 'v', 'y', 'w', 'b' };
    const char* fullcolor[6] = { "blue", "red", "violet", "yellow", "white", "black" };

    while (cin.get(c)) {

        for (int i = 0; i < 6; i++) {
            if (c == fullcolor[i][0])
            {
                cin.get(c);
                cin.get(c);
                if (fullcolor[i][2] == c)
                {
                    colorAmounts[i]++;
                    break;
                }
                else if (c == 'a') {
                    colorAmounts[5]++;
                    break;
                }
            }

            else {
                continue;
            }


        }

    }
    int sameColorVal = 0;
    bool notAllSame = false;
    for (int i = 0; i < 6; i++) {
        if (colorAmounts[i] != 0) {
            if (sameColorVal != 0) {
                if (colorAmounts[i] != sameColorVal) {
                    notAllSame = true;
                    break;
                }

            }
            else sameColorVal = colorAmounts[i];
        }
    }
    if (!notAllSame) {
        cout << "The number cards of all colors is equal: " << sameColorVal;
    }
    else {
        cout << "At least two colors with a different number of cards were found: " << endl;
        for (int i = 0; i < 6; i++) {
            if (colorAmounts[i] != 0) {
                cout << fullcolor[i] << " cards are " << colorAmounts[i] << endl;
            }
        }

    }

    return 0;
}