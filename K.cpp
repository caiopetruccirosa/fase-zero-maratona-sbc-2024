#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define INF 1000000007

using namespace std;

ll expo(ll x, ll y, ll mod) {
    if (y == 0) return 1;
    if (y == 1) return x;

    ll t = expo(x, y/2, mod) % mod;
    if (y % 2 == 0) 
        return (t*t) % mod;
    return (((t*t) % mod)*x) % mod;
}

bool is_prime(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (ll i = 3; i*i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {_
    ll t, k; cin >> t >> k;

    ll n = 0;
    for (ll i = 2; i <= t; i++) {
        if (is_prime(i)) {
            n++;
        }
    }

    ll p = k;
    ll q = n - k;

    ll g = gcd(p, q);
    p /= g;
    q /= g;

    cout << (p * expo(q, 998244351, 998244353)) % 998244353 << endl;

    return 0;
}