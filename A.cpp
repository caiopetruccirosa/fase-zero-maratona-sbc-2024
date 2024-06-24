#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007
#define INF (1ll << 60)

using namespace std;

int main() {_
    vector<bool> songs(4, false);
    int a, b, c;
    cin >> a >> b >> c;
    songs[a] = songs[b] = songs[c] = true;
    for (int i = 1; i <= 3; i++) {
        if (!songs[i]) {
            cout << i << endl;
            break;
        }
    }
}