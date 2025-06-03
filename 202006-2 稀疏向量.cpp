/*  这道题挺不容易，虽然想到双指针做法并不难
    第一个麻烦点是，我需要什么样的数据结构来存储 {index,value}这种数据?
    以前从来没用过pair，直到本题我才对pair有所熟悉。
    同时，类型转换也是个坑,以后要谨记，如果int做乘法，很可能会越界
    并且如果大量测试点没问题，突然出现了一个和答案差异很大的结果，应该想想是否溢出了
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<pair<int,int>>u;
    vector<pair<int,int>>v;
    int index,value;
    for(int i=0;i<a;i++){
        cin>>index>>value;
        u.push_back({index,value});
    }
    for(int i=0;i<b;i++){
        cin>>index>>value;
        v.push_back({index,value});
    }
    long long ans=0;
    int i=0,j=0;
    while(i<a&&j<b){
        int index1 = u[i].first;
        int index2 = v[j].first;
        if(index1==index2){
            ans += (long long)u[i++].second*v[j++].second;
        }
        else if(index1<index2){
            i++;
        }else{
            j++;
        }
    }
    cout<<ans;
    return 0;
}