#include <iostream>
using namespace std;

int main() {
    char teks[100];
    cout << "Masukkan teks (Kapital A-Z): ";
    cin >> teks;
    cout << teks[0];
    for (int i = 1; teks[i] != '\0'; i++) {
        int convert = teks[i] - 65;
        int shift = teks[i-1] - 65;

        char result = 'A' + (convert + shift) % 26 ;
        cout << result;
    }
    return 0;
}
