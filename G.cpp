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

int solve(vector<int> &dp, vector<ll> &distance_to_start, vector<ll> &tobacco_per_stop, int i, int n, ll tobacco, int stops) {
    if (dp[i] != -1) {
        dp[i] = min(stops, dp[i]);
        return dp[i];
    } else if (i == n-1) {
        dp[i] = stops;
        return dp[i];
    }

    ll tobacco_needed = distance_to_start[i+1]-distance_to_start[i];
    if (tobacco-tobacco_needed < 0 && tobacco_per_stop[i]-tobacco_needed < 0) {
        return -1;
    } else if (tobacco-tobacco_needed >= 0 && tobacco_per_stop[i]-tobacco_needed < 0) {
        dp[i] = solve(
            dp, 
            distance_to_start, 
            tobacco_per_stop, 
            i+1, 
            n, 
            tobacco-tobacco_needed, 
            stops
        );
    } else if (tobacco-tobacco_needed < 0 && tobacco_per_stop[i]-tobacco_needed >= 0) {
        dp[i] = solve(
            dp, 
            distance_to_start, 
            tobacco_per_stop, 
            i+1, 
            n, 
            tobacco_per_stop[i]-tobacco_needed, 
            stops+1
        );
    } else {
        int a = solve(
            dp, 
            distance_to_start, 
            tobacco_per_stop, 
            i+1, 
            n, 
            tobacco-tobacco_needed, 
            stops
        );
        int b = solve(
            dp, 
            distance_to_start, 
            tobacco_per_stop, 
            i+1, 
            n, 
            tobacco_per_stop[i]-tobacco_needed, 
            stops+1
        );
        if (a != -1 && b != -1)
            dp[i] = min(a, b);
        else
            dp[i] = max(a, b);
    }
    return dp[i];
}

int main() {_
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> dp(n, -1);

    solve(dp, a, b, 0, n, k, 0);

    cout << dp[0] << endl;

    return 0;
}