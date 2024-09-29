#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int a[550][550];


int main() {
    int n, m, k; 
    cin >> n >> m >> k;
    int ex = (n / 2) + 1, ey = (m / 2 + 1);
    int res = 0;
    // if(n == 1){
    //     cout << k << endl;
    //     return 0;
    // }
    // int rl = m, rl1 = 1, rl2 = m, row = n, row1 = n, row2 = 1,
    //     cnt = max(n / 2, m / 2), 
        
    // while(row >= 3 || rl >= 3) {
    //     //第1行
    //     if(row2 < ex){
    //         for(int i = rl1; i <= rl2; i ++) 
    //             a[row2][i] = cnt;
    //         row2 ++;
    //     }
    //     if(row1 > ex) {
    //         for(int i = rl1; i <= rl2; i++)
    //             a[row1][i] = cnt;
    //         row1 --;
    //     }

    //     if(rl1 < ey)
    //         for(int i = row2; i <= row1;i++)
    //             a[i][rl1] = cnt;
    //     if(rl2 > ey){
    //         // cout << row2 << ' ' << row1 << endl;
    //         for(int i = row2; i <= row1; i++)
    //             a[i][rl2] = cnt ;
    //     }

    //     if(row >= 3)
    //         row -=2;
    //     cnt --;
    //     if(rl >= 3)
    //         rl -= 2, rl1++, rl2--;
    // }

    // for(int i = 1; i <= n;i ++) {
    //     for(int j = 1; j <= m;j ++)
    //         cout << a[i][j] << " \n"[j == m];
    // }
    // cout << time << endl;
    int time = max(n / 2, m / 2);
    for(int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;

        // int step = min(n - x, n - y);
        // cout << x << ' ' << y << endl;
        // cout << ex << ' ' << ey << endl;
        int dis = abs(ex - x) + abs(ey - y);
        // cout << dis << ' ' <<  max((time - a[x][y]), a[x][y]) << endl;

        //ax y能走多少距离 + time - a[x][y]
        if(time < dis)
            res ++;
        // cout << abs(ex - x) << ' ' << abs(ey - y) << ' '<< dis << endl;
    }
    cout << k - res << endl;
}