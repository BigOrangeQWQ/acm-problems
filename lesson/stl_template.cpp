#include <iostream>
#include <vector>
using namespace std;

// lower_bound/upper_bound
#include <algorithm>
void example_algorithm() {

vector<int> v = {1, 2, 4, 5, 8, 10, 20};
auto it1 = lower_bound(v.begin(), v.end(), 4); // 返回指向第一个不小于 给定值的元素的迭代器
auto it2 = upper_bound(v.begin(), v.end(), 4); // 返回指向第一个大于 给定值的元素的迭代器

}


// Map
#include <map>

void example_map() {

map<int, int> mp;
map<map<int,int>, int> mp2;

mp[20] = 10;
mp.insert({12, 39});

if(mp.find(2) == mp.end()) 
    cout << "Not Found" << endl;

auto it = mp.lower_bound(2);

for(auto v: mp) {
    
}
}

// Set
#include <set>

void example_set() {

set<int> s1;
set<map<int, int>> s2;

s1.insert(29);
s1.insert(29);
s1.insert(20);

for(auto v: s1) {
    cout << v << endl;
}

cout << (s1.find(29) != s1.end()) << endl;

}

// unordered_map/set 与 map/set 相似，储存的对象必须能被哈希(基础数据类型)，
// 没有 lower_bound/upper_bound，时间复杂度为 O1
// 但不要在清华场或CF场使用，他们会卡常的。

// deque/queue

#include <deque>
#include <queue>

void example_queue() {

queue<int> q2;

q2.push(2);
auto qv1 = q2.front();
auto qv2 = q2.back();
q2.pop();

//#include <deque>
deque<int> q1;
q1.push_back(1); // 往后面加元素
q1.push_front(1); //往前面加元素

auto v1 = q1.front(); //取到头的值
auto v2 = q1.back(); //取到末尾的值

q1.pop_back(); //删除尾部
q1.pop_front(); // 删除头部

}


#include <queue>
void example_priority_queue(){
    priority_queue<int> x;
    // 大顶堆，会把最大的元素放到堆顶上面，你可以用top()[log]去取到，pop()[log]可以删除
    // push()[log]会把你的元素自动排序，放到堆顶上面
    //
    priority_queue<int, vector<int>, greater<int>> x1; 
    // 小顶堆，会把最小的元素放到堆顶上面，你可以用top()[log]去取到，pop()[log]可以删除
    // push()[log]会把你的元素自动排序，放到堆顶上面
    //
    // x.push(); //add
    // x.size(); //size
    // x.pop(); //remove
    // x.top(); //get
}


// // 小技巧
// void trick() {
//     vector<int> p ={1, 2,3, 4,5,6,7}; //直接实例化
//     map<int,int> x = {
//         {1,2},
//         {2,3},
//         {3,4}
//     };
    
//     int siz = 10, value = 20;
//     vector<int> pp(siz, value); //初始化大小为10的数组，值全部为20
//     vector<vector<int>> ppp(siz, vector<int> (siz, value)); //二维数组
//     set<int> pppp(pp.begin(), pp.end());
//     pair<int,int> xx = {1, 2};

//     for(auto &v: pp) {
//         v = 1;
//     };

//     set<int> test;

//     sort(pp.begin(),pp.end(), greater<int>());
// }

#include <vector>

// vector<int> p[1000];
// vector<vector<int>> p(1000, vector<int>());

// bfs 
int dx[] = {0, -1, 1, 0, 0};
void trick () {
    // vector<int> p(siz, value); // value = 0
    const int n = 1000;
    // vector<vector<int>> p(n, vector<int>());
    // x[1] --> 31 
    
    // sort默认是升序排序, 1 2 3 4 7 100 
    // 如果我们要逆序排序，应该怎么写？
    // cmp, reverse, 
    // sort();
    // vector<int> x;
    // int a[10000];
    // sort(x.begin(), x.end(), greater<int>()); // 逆序排序
    // sort(a + 1, a + n - 1, greater<int>()); // 逆序排序
    // sort(x.begin(),x.end());
    // reverse(x.begin(),x.end());
    
    // set<int> x; // 去重操作，会去做一个vis数组?
    // vector<int> p;
    // auto tmp = set<int>(p.begin(),p.end());
    // p = vector<int>(tmp.begin(),tmp.end()); //把这个去重操作给做了
    
    set<int> x;
    // lower_bound(x.begin(), x.end(), v);//set的lowerbound有自己的函数，O(n)
    // x.lower_bound(v); //log(x.size())
    // 可以去用set维护一个区间? 
    // 对于一个区间来说，它就是里面有没有元素(?)
    int l, r;
    // x.upper_bound(l) == x.lower_bound(r);// x维护的是[l + 1, r - 1]这个区间 二分
    // set<int> p[20]; 善用set可以免去写很多数据结构的题目

    // 给定(由小写字母和数字组成)字符串 S(1e6) 和 n(1e5) 个名字(|name|<20)
    // 问子序列能否构成一个合法的需求串（名字+合法月份日期 kevin0229）
    // kevi55nd04025 S
    // kevin
    // 造 40 个set['a'-'z'] [0,9]
    // set<int> xx[36];
    // auto t = xx['k' - 'a'].upper_bound(0);
    // xx['e' - 'a'].upper_bound(*t)
    // .....一直二分下去
    // (20logn+365logn)*n
    // lower_bound 
    auto p = vector<int>();
    // *max_element(p.begin(), p.end());
    // *min_element(p.begin(), p.end());
    // p.begin(),p.end()
    // __builtin_popcount() 统计某个数的二进制1的数量
    // __gcd() __lg() 
    
    // 浏览器插件，优化你的刷题体验的东西
}   