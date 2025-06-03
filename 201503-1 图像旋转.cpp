/*
    写题不能断，这道题很简单，但是自己总是没想清楚ans到底几行几列，一直出BUG
    同时，vector多维向量初始化要想清楚。
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>ans[i][j];
        }
    }

    for(int i = m - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            cout<<ans[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}