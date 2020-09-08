#include <iostream>

using namespace std;

int num;

int main() {
    while (cin >> num) {
        cout << (num & (num - 1) ? "NO" : "YES") << endl;
    }
    return 0;
}