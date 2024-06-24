#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>
#define ll long long

using namespace std;

int main() {_
    ll e; int v;
    cin >> e >> v;

    int hour = (19 + (e / v)) % 24;
    int min = ((e % v) * 60) / v;

    if (hour < 10) cout << 0;
    cout << hour << ':';
    
    if (min < 10) cout << 0;
    cout << min << '\n';
}