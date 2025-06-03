/*
写这题最大的后悔就是没板子 只能自己去硬想 但是又记不住那么多过程
以后一定写博客了 在iPad上记录还是感觉怪怪的
以及最近题写少了，都不记得 ios::sync_with_stdio(false) 和 cin.tie(0) 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int u,v,w;
    edge(int a, int b, int c) {
        u = a;
        v = b;
        w = c;
    }
};

int father[100005];
vector<edge> edges;

void init(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int find(int x) {
    if(x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}

bool unionSet(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) {
        return false;
    }
    else{
        father[fx] = fy;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n,m;
    cin >> n >> m;;
    init(n);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a,b,c);
    }
    sort(edges.begin(),edges.end(),
        [] (edge a, edge b) {
            return a.w < b.w;
        }
    );

    int ans = 0;
    for(const auto edge : edges) {
        if(unionSet(edge.u, edge.v)) {
            ans = max(ans, edge.w);
        }
        if(find(1) == find(n)) {
            break;
        }
    }
    cout << ans;
    return 0;
}