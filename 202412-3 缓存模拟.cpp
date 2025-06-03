#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define int long long  // 使用长整型防止溢出

using namespace std;

const int MAX_ELEM = 3e5;  // 系统支持的最大元素数量
const int MAX_GROUP = 7e4; // 系统支持的最大分组数量

// 全局数据结构
int group_ver[MAX_GROUP];  // 记录每个组的当前版本号(时间戳)
int group_size[MAX_GROUP]; // 记录每个组当前存储的元素数量

// 操作记录结构体
struct Operation {
    int type; // 操作类型：0表示加载，1表示写回
    int id;   // 操作的元素ID
};
vector<Operation> ans; // 存储所有操作记录

// 缓存节点结构体，用于优先队列
struct CacheNode {
    int id;  // 元素ID
    int ver; // 元素版本号
    // 重载运算符，使优先队列按版本号从小到大排序(最早的版本在队首)
    bool operator<(const CacheNode& o) const { return o.ver < ver; }
};
priority_queue<CacheNode> group_pq[MAX_GROUP]; // 每个组的缓存队列

// 全局映射表
unordered_map<int, int> elem_ver;   // 记录每个元素的当前版本号
unordered_map<int, bool> modified;  // 记录元素是否被修改过

int main() {
    int n, m, q; // n:每组容量 m:组数 q:操作数量
    cin >> n >> m >> q;

    for (int i = 0; i < q; ++i) {
        int op, y; // op:操作类型(0/1) y:元素ID
        cin >> op >> y;

        // 缓存命中：元素已存在
        if (elem_ver[y]) {
            int g = (y / n) % m; // 计算元素所属的组号

            // 更新元素版本号(时间戳)
            group_ver[g]++;
            group_pq[g].push({ y, group_ver[g] });
            elem_ver[y] = group_ver[g];

            // 如果是写操作，标记为已修改
            if (op == 1) modified[y] = true;
        }
        // 缓存未命中：元素不存在
        else {
            int g = (y / n) % m; // 计算元素所属的组号

            // 组已满，需要淘汰旧元素
            if (group_size[g] == n) {
                while (!group_pq[g].empty()) {
                    CacheNode t = group_pq[g].top(); // 获取最早的元素
                    group_pq[g].pop();

                    // 跳过版本号不匹配的记录(已被更新)
                    if (elem_ver[t.id] != t.ver) continue;

                    // 如果被淘汰的元素被修改过，需要写回
                    if (modified[t.id]) {
                        ans.push_back({ 1, t.id }); // 记录写回操作
                        modified[t.id] = false;
                    }

                    // 插入新元素
                    group_ver[g]++;
                    elem_ver[y] = group_ver[g];
                    if (op == 1) modified[y] = true; // 如果是写操作，标记为已修改
                    group_pq[g].push({ y, group_ver[g] });
                    ans.push_back({ 0, y }); // 记录加载操作

                    elem_ver[t.id] = 0; // 淘汰旧元素
                    break;
                }
            }
            // 组未满，直接插入
            else {
                group_ver[g]++;
                elem_ver[y] = group_ver[g];
                group_size[g]++;
                group_pq[g].push({ y, group_ver[g] });
                if (op == 1) modified[y] = true; // 如果是写操作，标记为已修改
                ans.push_back({ 0, y }); // 记录加载操作
            }
        }
    }

    // 输出所有操作记录
    for (auto& op : ans) {
        cout << op.type << " " << op.id << "\n";
    }
    return 0;
}