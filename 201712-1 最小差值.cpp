/*
    本题没什么好说的，借着本题，总结一下sort函数的用法
    要用标准库algorithm,可以对数组和容器进行排序
    // 容器
    sort(arr.begin(),arr.end())
    // 数组
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); 
    sort(arr, arr + n);
    // 容器任意范围
    sort(vec.begin() + m, vec.begin() + n);
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = INT_MAX;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i]; 
    }
    sort(numbers.begin(),numbers.end());
    for(int i = 0; i < n - 1; i++) {
        ans = min(ans,abs(numbers[i+1] - numbers[i]));
    }
    cout << ans;
    return 0;
}