#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

const int N = 2e5 + 10;

int dx[] = {1, 0, -1, 0};

int dy[] = {0, 1, 0, -1};
int n;

char hd[5][N];
bool cnt[5][N];

void solve() {
    cin >> n;
    for (int j = 1; j <= 2; j++)
        for (int i = 1; i <= n; i++)
        cin >> hd[j][i];
    for (int j = 0; j <= 4; j++)
        for (int i = 0; i <= n; i++)
        cnt[j][i] = false;

    queue<pair<int, int>> q;
    q.push({1, 1});
    while (q.size()) {
        auto p = q.front();
        q.pop();
        auto xx = p.x, yy = p.y;

        if (cnt[yy][xx] || yy > 2 || yy < 1 || xx > n || xx < 0)
            continue;

        cnt[yy][xx] = true;
        for (int i = 0; i < 4; i++) {
        int flag;
        if (xx + dx[i] <= n && xx + dx[i] > 0 && yy + dy[i] <= 2 && yy + dy[i] > 0 &&
            hd[yy + dy[i]][xx + dx[i]] == '<')
            flag = -1;
        if (xx + dx[i] <= n && xx + dx[i] > 0 && yy + dy[i] <= 2 && yy + dy[i] > 0 && 
            hd[yy + dy[i]][xx + dx[i]] == '>')
            flag = 1;
        // cout << yy << ' ' << xx << ' ' << dx[i] << ' ' << xx + dx[i] + flag << ' '
        //     << flag << ' ' << endl;
        q.push({xx + dx[i] + flag, yy + dy[i]});
        }
    }

    if (cnt[2][n])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
    int T;
    cin >> T;
    // int T = 1;
    while (T-- > 0) {
        solve();
    }
}