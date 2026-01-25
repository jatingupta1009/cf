#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000; // adjust according to constraints

int block;
vector<int> freq(MAXA + 1);
int distinctCount = 0;

struct Query {
    int l, r, idx;
};

bool cmp(Query &a, Query &b) {
    if (a.l / block != b.l / block)
        return a.l / block < b.l / block;
    return a.r < b.r; // or use zigzag optimization
}

void add(int x) {
    if (freq[x] == 0) distinctCount++;
    freq[x]++;
}

void remove(int x) {
    freq[x]--;
    if (freq[x] == 0) distinctCount--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int q; 
    cin >> q;
    vector<Query> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; // make 0-indexed
        queries[i].r--;
        queries[i].idx = i;
    }

    block = sqrt(n);

    sort(queries.begin(), queries.end(), cmp);

    vector<int> ans(q);

    int curL = 0, curR = -1;

    for (auto &qu : queries) {
        int L = qu.l;
        int R = qu.r;

        while (curL > L) add(a[--curL]);
        while (curR < R) add(a[++curR]);
        while (curL < L) remove(a[curL++]);
        while (curR > R) remove(a[curR--]);

        ans[qu.idx] = distinctCount;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}
