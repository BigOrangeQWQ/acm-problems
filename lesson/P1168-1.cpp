#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, c; 
    cin >> n >> c;

    priority_queue<int> big; //大顶堆维护小的
    priority_queue<int, vector<int>, greater<int>> small; 
    //小顶堆里面的最小值都要大于大顶堆
    big.push(c);
    cout << c << endl;

    for(int i = 2; i <= n;i ++) {
        cin >> c;
        (c > big.top()) ? small.push(c) : big.push(c); 
        //满足 ? 前面的条件则执行问号后面的语句，否则执行冒号后面的语句
        //通过对顶堆的大小维护中位数

        if(i % 2 == 1) {
            while(abs((int)big.size() - (int)small.size()) > 1) {
                if(big.size() > small.size()) {
                    small.push(big.top());
                    big.pop();
                }
                else {
                    big.push(small.top());
                    small.pop();
                }
            }
            
            if(big.size() > small.size())
                cout << big.top() << endl;
            else 
                cout << small.top() << endl;
        }

    }
}