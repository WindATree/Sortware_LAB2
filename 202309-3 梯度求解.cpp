/*
非常琐碎的一道题，有很多知识点
1e9 + 7 是一个double类型的数字，取模运算只能对整数而言，所以必须写成数字的形式，科学计数法行不通
复习了一下同余原理, (a % MOD + MOD) % MOD
了解了 stoi, stoll, to_string 的用法，更加复杂的字符串转换需要重载运算符 <<
复习了一下面向对象的基本知识，发现还是得看C++，尤其是 Node::f() 这种基础知识
再次复习了逆波兰表达式，尤其是栈弹出的时候，必须重命名为rhs和lhs，否则减法总是会出错
最后就是cin.ignore()，在getline之前调用，忽略输入带来的换行符
使用stringstream，传入一个字符串，可以用 >> 运算符自动按照空格 制表符分割，相当于split()操作
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

const long long mod_number = 1000000007;

long long mod(long long a) {
	return (a % mod_number + mod_number) % mod_number;
}

struct Node {
	long long value;
	long long derivative;
	Node(long long a, long long b) {
		value = mod(a);
		derivative = mod(b);
	}
};

static Node add(Node a, Node b) {
	return { a.value + b.value, a.derivative + b.derivative };
}

static Node sub(Node a, Node b) {
	return { a.value - b.value, a.derivative - b.derivative };
}

static Node mul(Node a, Node b) {
	return { a.value * b.value, a.derivative * b.value + a.value * b.derivative };
}

int index(string s) {
	return stoi(s.substr(1));
}

long long calculate(string expression, int target_var, vector<long long>values) {
	stringstream ss(expression);
	string token;
	stack<Node> s;
	while (ss >> token) {
		//cout << "token:" << token << endl;
		if (token[0] == 'x') {
			int x_index = index(token);
			int derivative = x_index == target_var ? 1 : 0;
			//cout << "values[x_index]:" << values[x_index] << " " << derivative << endl;
			s.emplace(values[x_index], derivative);
		}
		else if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
			//cout << "operator:" << token << endl;
			s.emplace(stoll(token), 0);
		}
		else {
			Node rhs = s.top();
			s.pop();
			Node lhs = s.top();
			s.pop();

			switch (token[0]) {
			case '+':
				s.push(add(lhs, rhs));
				//cout << s.top().derivative << endl;
				break;
			case '-':
				s.push(sub(lhs, rhs));
				//cout << s.top().derivative << endl;
				break;
			case '*':
				s.push(mul(lhs, rhs));
				//cout << s.top().derivative << endl;
				break;
			default:
				break;
			}
		}
	}
	return s.top().derivative;
}

int main() {
	int var_count, expr_count;
	cin >> var_count >> expr_count;
	cin.ignore();

	string expression;
	getline(cin, expression);

	while (expr_count--) {
		int target_var;
		vector<long long> values(var_count + 1);
		cin >> target_var;
		for (int i = 1; i <= var_count; i++) {
			cin >> values[i];
		}
		long long ans = calculate(expression, target_var, values);
		cout << ans << endl;
	}
	return 0;
}