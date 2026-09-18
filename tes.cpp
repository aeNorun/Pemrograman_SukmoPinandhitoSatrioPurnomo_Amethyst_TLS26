#include <iostream>
using namespace std;
 
int main() {
    int N, K;
    cin >> N >> K;
 
    const int MAXN = 1000005;
    static int nextArr[MAXN]; // representasi linked list melingkar
 
    // bangun lingkaran: astronot i -> astronot i+1, astronot N -> astronot 1
    for (int i = 1; i <= N; i++) {
        nextArr[i] = (i % N) + 1;
    }
 
    int current  = 1;   // astronot tempat hitungan dimulai
    int prev     = N;   // astronot sebelum "current" dalam lingkaran
    int remaining = N;
 
    cout << "Urutan astronot yang dieliminasi: ";
 
    while (remaining > 1) {
        // maju sebanyak (K-1) langkah dari current untuk mencari
        // astronot yang mendapat hitungan ke-K
        for (int i = 1; i < K; i++) {
            prev = current;
            current = nextArr[current];
        }
 
        int eliminated = current;
        cout << eliminated;
        remaining--;
        if (remaining > 0) cout << ", ";
 
        // keluarkan "eliminated" dari lingkaran
        int newCurrent = nextArr[current];
        nextArr[prev] = newCurrent;
 
        // perbarui nilai K sesuai aturan
        if (eliminated % 2 == 0) {
            K += 2; // genap -> K bertambah 2
        } else {
            K -= 1; // ganjil -> K berkurang 1
        }
        if (K < 2) K = 2; // K tidak boleh kurang dari 2
 
        // hitungan berikutnya dimulai dari astronot setelah yang dieliminasi
        current = newCurrent;
    }
 
    cout << endl;
    cout << "Astronot terakhir yang bertahan: " << current << endl;
 
    return 0;
}