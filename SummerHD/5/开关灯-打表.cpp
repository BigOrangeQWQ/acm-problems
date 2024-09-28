#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst first 
#define snd second 

using namespace std;

map<string, int> mp;

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	string str = "";
	for(int i = 0; i < n; i ++) {
		str += '0';
	}
	int ans = 0;
	queue<string> q;
	q.push(str);
	while(!q.empty()) {
		string ss = q.front();
		q.pop();
		for(int i = 0; i < n; i ++) {
			string s = ss;
			s[i] = (s[i] == '0' ? '1' : '0');
			if(i - 1 >= 0) s[i - 1] = (s[i - 1] == '0' ? '1' : '0');
			if(i + 1 < n) s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
			if(!mp[s]) {
				// cout << "shit" << endl;
				q.push(s);
				ans ++;
				mp[s] = 1;
			}
		}
	}

	// for(auto t : mp) {
		// cout << t.first << ' ' << t.second << endl;
// 		
	// }
	cout << ans << endl;
	return 0;
}