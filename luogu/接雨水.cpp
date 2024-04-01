#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;
#define x first
#define y second

int main() {
    int n, d; cin >> n >> d;
    vector<PII> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin() + 1, a.end());
    deque<int> lq, hq;

    int L = 1, res = 2e9;
    for(int i = 1; i <= n; i++) {
        while(lq.size() && a[lq.back()].y > a[i].y)
            lq.pop_back();
        while(hq.size() && a[hq.back()].y < a[i].y)
            hq.pop_back();
        lq.push_back(i), hq.push_back(i);

        //L定时R增则差增
        //所以满足D时，缩L更RES
        //滑动即可
        while(L <= i && a[hq.front()].y - a[lq.front()].y >= d) {
            res = min(res, a[i].x - a[L].x);
            L++;
            while(lq.size() && lq.front() < L)
                lq.pop_front();
            while(hq.size() && hq.front() < L)
                hq.pop_front();
        }
        
    }
    if (res < 2e9)
        printf("%d\n", res);
    else
        puts("-1");
    return 0;





}