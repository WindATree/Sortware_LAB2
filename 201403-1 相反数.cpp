/*
    真的写题写太少了，我都忘了可以直接cin >> numbers[i]的
    另外，确实需要注意acm风格，免得忘了头文件，unordered_map和map不一样，前者哈希表，后者红黑树
    与此同时，哈希表判断是否找到一个元素，find方法返回的是一个迭代器，要判断是否到了迭代器末尾end()
    最后，本题如果数字出现不止一次，应该注意 0 要特殊判断，并且 ans += min(hashMap[-numbers[i]], count);
    哈希表也可以像pair一样，first访问键，second访问值
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin>> n;
    vector<int> numbers(n);
    unordered_map<int, int> hashMap(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
        hashMap[numbers[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(hashMap.find(-numbers[i]) != hashMap.end()) {
            ans++;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}