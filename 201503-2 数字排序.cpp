/*
惨痛的教训：能过就行了，想什么代码优美呢，闲的无聊是吗？想美化先过了再说！
比较器返回true，那么左边的元素排在右边元素的前面！！这是比较器的核心规则。
operator()必须是成员函数，所以重载需要放在结构体里。
然而sort函数的第三个参数，需要一个实例化对象
priority_queue是模版类，它的第三个参数是比较函数类型，而不是比较函数实例
priority_queue构造函数内部会自己创建一个比较器实例
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int value;
    int count;
    Node(int v, int c) : value(v), count(c) {}
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        if (a.count != b.count) {
            return a.count > b.count; 
        }
        return a.value < b.value;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> numbers(1005,0);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers[a]++;
    }
    vector<Node> nodes;
    for (int i = 0; i <= 1000; ++i) {
        if (numbers[i] > 0) {
            nodes.emplace_back(i, numbers[i]);
        }
    }
    Compare comp;
    sort(nodes.begin(), nodes.end(),comp);
    for (const auto& node : nodes) {
        cout << node.value << " " << node.count << endl;
    }
    return 0;
}