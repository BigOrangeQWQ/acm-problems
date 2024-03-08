#include <iostream>

using namespace std;

const int N = 5e5 + 10;
int num[N], tmp[N];
long long ans;

void merge_sort(int num[], int l, int r) {
    if(l >= r) return ;

    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1 , r);
    
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(num[i] <= num[j]) tmp[k ++] = num[i ++];
        else tmp[k ++] = num[j ++], ans += mid - i + 1;
    }

    while(i <= mid) tmp[k ++] = num[i ++];
    while(j <= r) tmp[k ++] = num[j ++];

    // for(int i = 1; i <= n ;)
    for (i = l, j = 0; i <= r; i ++, j ++ ) num[i] = tmp[j];
}

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n;i ++) {
        cin >> num[i];
    }
    merge_sort(num, 1, n);
    cout << ans << endl;
}