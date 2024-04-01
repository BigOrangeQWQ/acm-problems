#include <deque>
#include <iostream>
#include <vector>


using namespace std;

int n, k;

void solve_min(const vector<int> &a) {
    deque<int> p;
    
    for(int i = 1; i < k; i++) {
        while(p.size() && a[i] <= a[p.back()])
            p.pop_back();
        p.push_back(i);
    }

    for(int i = k; i <= n; i++) {
        while(p.size() && a[i] <= a[p.back()]) 
            p.pop_back();

        p.push_back(i);

        while(p.size() && i >= p.front() + k)
            p.pop_front();
        cout << a[p.front()] << ' ';
    }
}

void solve_max(const vector<int> &a) {
    deque<int> p;

    for(int i = 1; i < k ; i++) {
        while(p.size() && a[p.back()] <= a[i]) 
            p.pop_back();
        p.push_back(i);
    }

    for(int i = k; i <= n; i ++) {
        while(p.size() && a[p.back()] <= a[i]) 
            p.pop_back();
        p.push_back(i);
  
        while(p.size() && i >= p.front() + k)
            p.pop_front();
        cout << a[p.front()] << ' ';
    }
}


int main() {
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    solve_min(a);
    cout << endl;
    solve_max(a);

}
