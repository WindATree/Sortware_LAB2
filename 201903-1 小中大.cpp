/*
    这题太逆天了。
    没见过这么恶心的题，也算是对类型转换有了一个了解。
    

*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int>numbers(n);
    int max = INT_MIN;
    int min = INT_MAX;
    int middle = n / 2;
    for(int i = 0; i < n; ++i) {
        cin >> numbers[i];
        if(numbers[i] > max) {
            max = numbers[i];
        }
        if(numbers[i] < min) {
            min = numbers[i];
        }
    }
    cout << max << " ";
    if( n % 2 == 0) {
        int sum = (numbers[middle] + numbers[middle-1]);
        if(sum % 2 == 0) {
            cout << sum / 2 <<" ";
        } else {
            cout << sum / 2 << ".5" << " ";
        }
    } else {
        int sum = numbers[middle];
        cout << sum << " ";
    }
    cout << min;
    return 0;
}