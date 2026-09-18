#include <iostream>
using namespace std;
 
int main() {
    int N, K;
    cin >> N >> K;
 
    const int MAXN = 1000005;
    static int nextArr[MAXN]; 
 
    for (int i = 1; i <= N; i++) {
        nextArr[i] = (i % N) + 1;
    }
 
    int current  = 1;
    int prev     = N;
    int remaining = N;
 
    cout << "Urutan astronot yang dieliminasi: ";
 
    while (remaining > 1) {
        for (int i = 1; i < K; i++) {
            prev = current;
            current = nextArr[current];
        }
 
        int eliminated = current;
        cout << eliminated;
        remaining--;
        if (remaining > 0) cout << ", ";
 
        int newCurrent = nextArr[current];
        nextArr[prev] = newCurrent;
 
        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }
        if (K < 2) K = 2;
 
        current = newCurrent;
    }
 
    cout << endl;
    cout << "Astronot terakhir yang bertahan: " << current << endl;
 
    return 0;
}
