/*
算是自己想的，无比丑陋的代码，一点点改出来的，还好有输入样例，不然我都不知道考试怎么写的出来。


*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define int long long

// 无参数
vector<int> arg1(26);
// 有参数
vector<int> arg2(26);
// 实际每次的输入参数
vector<string> arg3;

bool isStringDigits(const string& str) {
	for (char ch : str) {
		if (!isdigit(ch)) {
			return false; // 如果有一个字符不是数字字符，返回 false
		}
	}
	return true; // 所有字符都是数字字符
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string option;
	cin >> option;
	for (int i = 0; i < option.size();) {
		if (i + 1 < option.size() && option[i + 1] == ':') {
			arg2[option[i] - 'a']++;
			i += 2;
		}
		else {
			arg1[option[i] - 'a']++;
			i++;
		}
	}
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		arg3.clear();
		string s;
		// 这里要用 getline 读一行,不能用 cin 
		getline(cin, s);
		stringstream ss(s);
		string token;
		cout << "Case " << i + 1 << ": ";
		while (ss >> token) {
			arg3.push_back(token);
		}
		vector<bool>ans(26);
		vector<string>values(26);
		for (int i = 1; i < arg3.size();) {
			const string& arg = arg3[i];
			if (arg[0] != '-' || arg.size() > 2 || arg[1] < 'a' || arg[1]>'z') {
				break;
			}
			int index = arg[1] - 'a';
			// 如果匹配上了无参数的
			if (arg1[index] != 0) {
				ans[index] = true;
				i++;
			}
			// 如果匹配上了有参数的
			else if (arg2[index] != 0) {
				if (i + 1 < arg3.size()) {
					values[index] = arg3[i + 1];
					ans[index] = true;
					i += 2;
				}
				// 没有实际参数
				else {
					break;
				}
			}
            // 如果出现了不是规定的选项
			else {
				break;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (ans[i] == true) {
				cout << "-" << (char)('a'+i) << " ";
				if (arg2[i] != 0) {
					cout << values[i] << " ";
				}
			}
			
		}
		cout << endl;
		ans.clear();
		values.clear();
	}
	return 0;
}