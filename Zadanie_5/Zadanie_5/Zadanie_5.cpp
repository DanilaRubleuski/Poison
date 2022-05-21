#include <iostream>

using namespace std;

int colorAmounts[6][21];

int main()
{
    char c;
    char colors[6] = { 'b', 'r', 'v', 'y', 'w', 'b' };
    const char* fullcolor[6] = { "blue", "red", "violet", "yellow", "white", "black" };

    while (cin.get(c)) {
        if (c == ':') break; //finding first relevant line
    }
    int lastnum = 0;
    while (cin.get(c)) {
        if (c == '\n') {
            while (cin.get(c)) {
                if (c == ':') break; //finding first relevant line
            }
        }
        if (isdigit(c)) {
            lastnum = c - '0';
            cin.get(c);
            while (isdigit(c)) {
                lastnum = (lastnum * 10) + (c - '0');
                cin.get(c);

            }
        }
        for (int i = 0; i < 6; i++) {
            if (c == fullcolor[i][0])
            {
                cin.get(c);
                if (fullcolor[i][1] == c)
                {
                    cin.get(c);
                }
                else break;

                if (fullcolor[i][2] == c)
                {
                    colorAmounts[i][lastnum]++;
                    break;
                }
                else if (c == 'a') {
                    colorAmounts[5][lastnum]++;
                    break;
                }
            }

            else {
                continue;
            }


        }




    }
    int summer[6];
    bool allequal = true;

    int found = -1;

    for (int i = 0; i < 6; i++) {
        summer[i] = 0;
        for (int j = 1; j <= 20; j++)
        {
            summer[i] += colorAmounts[i][j];
        }
        if (summer[i]) found = i;
    }
    for (int i = 0; i < 6; i++) {
        if (!summer[i]) {
            continue;
        }
        for (int kk = i + 1; kk < 6; kk++) {
            if (!summer[kk]) {
                continue;
            }
            for (int j = 1; j <= 20; j++) {
                if (colorAmounts[i][j] != colorAmounts[kk][j]) {
                    allequal = false;
                    break;
                }

            }
            if (!allequal)break;
        }
        if (!allequal)break;
    }

    if (allequal) {
        cout << "The values of cards of all colors are identical:" << endl;

        for (int j = 1; j <= 20; j++) {

            while (colorAmounts[found][j]) {
                cout << j << " ";
                colorAmounts[found][j]--;
            }
        }

    }
    else {
        cout << "The values of cards of all colors are not identical:" << endl;
        for (int i = 0; i < 6; i++) {
            if (summer[i] > 0) {
                cout << fullcolor[i] << " cards values: ";
            }
            else continue;
            for (int j = 1; j <= 20; j++)
            {

                while (colorAmounts[i][j])
                {
                    cout << j << " ";
                    colorAmounts[i][j]--;
                }
            }
            cout << endl;
        }
    }


    return 0;
}