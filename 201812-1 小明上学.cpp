/*
    很水的一道模拟题，可惜一开始被Switch语句搞晕了
    我们需要每次计算完结果之后就返回，所以每个都要加上break
    如果不加那么就是Switch循环，totalTime被不断赋值，并没有起到加法作用
*/
#include<iostream>
using namespace std;

int r,y,g;
int ans = 0;

int calculateTime(int flag){
    int count_down;
    cin>>count_down;
    int totalTime = 0;
    switch(flag){
        case 0:
            totalTime=count_down;
            break;
        case 1:
            totalTime=count_down;
            break;
        case 2:
            totalTime=count_down+r;
            break;
        case 3:
            totalTime=0;
            break;
        default:
            break;
    }
    return totalTime;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>r>>y>>g;   
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int flag;
        cin>>flag;
        ans+=calculateTime(flag);
    }

    cout<<ans;
    return 0;
}