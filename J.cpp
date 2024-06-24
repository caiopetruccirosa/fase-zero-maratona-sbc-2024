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

int get_attacks(vector<string>& board, ll i, ll j, ll k, ll l, ll n, ll m){
    set<pair<ll, ll>> positions;

    k--;
    l--;

    positions.insert({i-k, j-l});
    positions.insert({i+k, j+l});
    positions.insert({i-k, j+l});
    positions.insert({i+k, j-l});
    
    positions.insert({i-l, j-k});
    positions.insert({i+l, j+k});
    positions.insert({i-l, j+k});
    positions.insert({i+l, j-k});

    int attacks = 0;
    for (auto pos : positions){
        if (pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m) 
            continue;
        if (board[pos.first][pos.second] == '*') 
            attacks++;
    }
    return attacks;
}

int main() {_
    ll n, m;
    cin >> n >> m;
    ll k, l;
    cin >> k >> l;

    vector<string> grid(n);
    for (ll i = 0; i < n; i++){
        cin >> grid[i];
    }

    pii pos;
    int max_attacks = -1;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            if (grid[i][j] == '.') {
                int attacks = get_attacks(grid, i, j, k, l, n, m);
                if (attacks > max_attacks){
                    max_attacks = attacks;
                    pos = {i, j};
                }
            }
        }
    }

    cout << pos.first+1 << " " << pos.second+1 << "\n";

    return 0;
}
