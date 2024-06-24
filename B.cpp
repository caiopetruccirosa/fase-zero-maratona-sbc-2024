#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>
#define ll long long

using namespace std;

class UnionFind {
    private:
        int num_components;
        vector<int> component_size;
        vector<int> pi;
        vector<int> rank;

    public:
        UnionFind(int N) {
            this->num_components = N;
            this->component_size = vector<int>(N, 1);
            this->rank = vector<int>(N, 0);
            this->pi = vector<int>(N, 0);
            for (int i = 0; i < N; i++)
                this->pi[i] = i;
        }

        int Find(int x) {
            // find representative
            int root = x;
            while (root != this->pi[root]) {
                root = this->pi[root];
            }

            // path-compression
            int current = x;
            while (current != root) {
                int tmp = this->pi[current];
                this->pi[current] = root;
                current = tmp;
            }

            return root;
        }

        bool IsSameSet(int a, int b) {
            return this->Find(a) == this->Find(b);
        }

        void Union(int a, int b) {
            if (this->IsSameSet(a, b))
                return;

            this->num_components--;

            // union-by-rank
            int x = this->Find(a), y = this->Find(b);
            if (rank[x] > rank[y]) {
                this->pi[y] = x;
                this->component_size[x] += this->component_size[y];
            } else {
                this->pi[x] = y;
                this->component_size[y] += this->component_size[x];
                if (rank[x] == rank[y])
                    this->rank[y]++;
            }
        }

        int NumberOfComponents() {
            return this->num_components;
        }

        int ComponentSize(int x) {
            return this->component_size[this->Find(x)];
        }
};

int main() {_
    int n, m, k;
    cin >> n >> m >> k;

    vector<pipii> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    sort(edges.begin(), edges.end());

    UnionFind unionfind = UnionFind(n+1);

    for (pipii edge: edges) {
        unionfind.Union(edge.second.first, edge.second.second);
        if (unionfind.ComponentSize(1) >= k) {
            cout << edge.first << endl;
            return 0;
        }
    }
}