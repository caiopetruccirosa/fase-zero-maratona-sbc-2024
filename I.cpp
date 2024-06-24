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

int main() {_
    ll n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    vector<vector<bool>> has_count(m+1, vector<bool>(m+1, false));

    vector<int> prefix_sum(n*m + m, 0);
    for (int i = 1; i <= n*m + m; i++)
        prefix_sum[i] = prefix_sum[i-1] + (str[(i-1) % (n*m)] - '0');
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            int count = prefix_sum[(j+1)*m + i] - prefix_sum[j*m + i];

            if (has_count[i][count]) {
                cout << "N" << endl;
                cout << count << '\n';
                cout << j*m + i -1 << '\n';
                cout << (j+1)*m + i -1 << '\n';
                return 0;
            }

            has_count[i][count] = true;
        }
    }

    cout << "S" << endl;
    return 0;
}