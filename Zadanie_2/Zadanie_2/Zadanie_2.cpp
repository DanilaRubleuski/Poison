#include <iostream>

using namespace std;

int main()
{
    const char* colors[6] = { "blue", "red", "violet", "yellow", "white", "black" };

    int n, k, g, gv, o;


    cin >> n >> k >> g >> gv >> o;
    int* oVal = new int[o];
    for (int i = 0; i < o; i++) {
        int temp;
        cin >> temp;
        oVal[i] = temp; // Initialization of card values other than green
    }

    cout << "active player = 1" << endl;
    cout << "players number = " << n << endl;
    for (int currplayer = 1; currplayer <= n; currplayer++) {
        cout << currplayer << " player hand cards: ";
        for (int i = currplayer - 1; i < g; i += n) {
            cout << gv << " green ";
        }
        int helper = (currplayer - (g % n)) - 1;
        if (helper < 0) helper = n + helper;
        for (int i = 0; i < k; i++) {
            for (int j = helper; j < o; j += n) {
                helper += n;
                cout << oVal[j] << " " << colors[i] << " ";
            }
            helper -= o;
            while (helper > o) {
                i++;
                helper -= o;
            }
        }
        cout << endl << currplayer << " player deck cards:" << endl;
    }
    for (int i = 1; i <= k; i++) {
        cout << i << " pile cards:" << endl;

    }


    delete[]oVal;
    return 0;
}