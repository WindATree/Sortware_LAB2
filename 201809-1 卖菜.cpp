/*
    本题还是有一点点坑的，因为第二天所有的数据看的都是昨天
    如果第二天立刻更新原始数组的话，那么之后的人看到的就不是昨天数据了
    所以输入的数据和输出的得分开，不能一起改变
    不过，用ans数组确实没必要，可以用一个变量x就够了
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i =0;i<n;i++){
        int temp;
        cin>>temp;
        prices[i] = temp;
    }
    vector<int>ans(n);
    ans[0] = (prices[0]+prices[1])/2;
    cout<<ans[0]<<" ";
    for(int i = 1;i<n-1;i++){
        ans[i] = (prices[i-1]+prices[i]+prices[i+1])/3;
        cout<<ans[i]<<" ";
    }
    ans[n-1] = (prices[n-2]+prices[n-1])/2;
    cout<<ans[n-1]<<" "<<endl;
    return 0;
}