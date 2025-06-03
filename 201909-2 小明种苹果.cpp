/*  很简单的题，理清思路就不难
    注意 ios:sync_with_stdio(false)的写法，加快输入流
    vector<int>apple 如果不进行初始化，那么不能直接 apple[i] 这是不合法的行为
    如果想打擂来求最大最小值，最好不要用0，用climits库的INT_MIN
    本题注意以下数据样例：
    3 3
    80 0 0 0
    80 0 0 0
    80 0 0 0
    我的输出：240 0 0
    标准答案：240 1 0
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int t = 0,k = 0,p = INT_MIN;
    int origin = 0;
    int minus = 0;
    vector<int>apple(n);
    for(int i = 0; i < n; i++){
        cin>>origin;
        apple[i]= origin;
        for(int j = 0; j < m; j++){
            cin >> minus;
            if( minus < 0 ){
                apple[i] += minus;
            }else{
                continue;
            }
        }
        t +=apple[i];
        int temp = origin - apple[i];
        if(temp > p){
            k = i+1;
            p = temp;
        }
    }
    cout<<t<<" "<<k<<" "<<p;
    return 0;
}