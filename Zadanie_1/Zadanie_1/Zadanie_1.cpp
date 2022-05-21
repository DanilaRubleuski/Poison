#include <iostream>
using namespace std;

int main()
{
    const char* colors[6] = { "blue", "red", "violet", "yellow", "white", "black" };

    int k, g, gv, o;
    

    cin >> k >> g >> gv >> o;
    int* oVal = new int[o];
    for (int i = 0; i < o; i++) {
        int temp;
        cin >> temp;
        oVal[i] = temp; // Initialization of card values other than green
    }

    for (int i = 0; i < g; i++) {
        cout << gv << " green ";
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < o; j++) {
            cout << oVal[j] << " " << colors[i] << " ";
        }
    }

    delete[]oVal;
    return 0;
}