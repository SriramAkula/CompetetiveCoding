#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

vector<int> tree[MAXN];

void bfs(int source, vector<int>& dist, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    dist[source] = 0;
    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : tree[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    while (q--) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (int i = 0; i < k; ++i) {
            cin >> nodes[i];
        }

        if (k < 2) {
            cout << 0 << endl;
            continue;
        }

        long long total = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> dist(n + 1, -1);
            bfs(nodes[i], dist, n);

            for (int j = i + 1; j < k; ++j) {
                total += 2LL * dist[nodes[j]];
            }
        }

        cout << total % MOD << endl;
    }

    return 0;
}
