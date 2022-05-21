#include <iostream>

using namespace std;

int main()
{
    char c;

    int lastnum = 0;
    int greenamount = 0;
    int greenval = -1;
    while (cin.get(c)) {
        if (isdigit(c)) {
            lastnum = (c - '0');
            while (cin.get(c)) {
                if (!isdigit(c)) {
                    break;
                }
                else {
                    lastnum *= 10 + (c - '0');
                }
            }


        }
        if (c == 'g') {
            if (greenval == -1) {
                greenval = lastnum;
            }
            else if (greenval != lastnum) {
                cout << "Different green cards values occurred";
                return 0;
            }
            greenamount++;
        }

    }
    if (greenamount > 0) {
        cout << "Found " << greenamount << " green cards, all with " << greenval << " value";
    }
    else {
        cout << "Green cards does not exist";
    }

    return 0;
}