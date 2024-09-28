#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF 100000000000000000
#define caonima 33
using namespace std;
const int N = 1e6 + 10;
int a[N], ans[N];
int n, m, k, hh, tt;
vector<int> qry[N], v;
deque<int> q;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i ++) {
		int x; cin >> x;
		if(x > k) ans[i] = -INF;
		else qry[x].push_back(i);
	}
	for(int i = 1; i <= n; i ++) {
		if(qry[i].size()) {
			deque<int> q;
			vector<int> v;
			v.push_back(0);
			for(int j = i; j <= n; j += i) v.push_back(j);
			v.push_back(n + 1);

			vector<int> f(v.size() + caonima, -INF);
			f[0] = 0;
			q.push_back(0);
			
			for(int j = 1; j < v.size(); j ++) {
				while(!q.empty() && v[j] - v[q.front()] > k) q.pop_front();
				f[j] = max(f[j], f[q.front()] + a[v[j]]);
				while(!q.empty() && f[j] >= f[q.back()]) q.pop_back();
				q.push_back(j);
			}
			for(auto t : qry[i]) ans[t] = f[v.size() - 1];
		}
	}
	for(int i = 1; i <= m; ++ i){
        if(ans[i] == -INF) cout << "Noob" << endl;
        else cout << ans[i] << endl;;
    } 
	return 0;
}