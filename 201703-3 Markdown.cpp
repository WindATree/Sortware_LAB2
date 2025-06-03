/*
首先我们学到了getline(cin, line) 这样可以很方便读取一行
其次是 string 类的函数,find,substr
最后是对于双指针的模拟更加熟练了
这道题最大的困难在于处理换行符,尤其是段落的</p>
首先我们决定在输出一行的字符串之后,不换行,
根据前一行类型决定是否换行,如果pre = 1 我们再换行
这样读取到了空行,我们就能接上</p>
cout 输出在缓冲区,我们是不能退回到上一行的
*/
#include <iostream>
#include <string>

using namespace std;

void emphasize(string str);
void herf(string str);

void herf(string str) {
	cout << "<a href=" << '\"';
	int pos = str.find('(');
	pos++;
	while (str[pos] != ')') {
		cout << str[pos];
		pos++;
	}
	cout << '\"' << '>';
	pos = str.find(']');
	for (int i = 1; i < pos; i++) {
		if (str[i] == '_') {
			int j = i + 1;	
			while (str[j] != '_') {
				j++;
			}
			emphasize(str.substr(i, j - i + 1));
			i = j;
		}
		else {
			cout << str[i];
		}
	}
	cout << "</a>";
}

void emphasize(string str) {
	cout << "<em>";
	int length = str.size();
	for (int i = 1; i < length - 1; i++) {
		if (str[i] == '[') {
			int j = i + 1;
			while (str[j] != ')') {
				j++;
			}
			herf(str.substr(i, j - i + 1));
			i = j;
		}
		else {
			cout << str[i];
		}
	}
	cout << "</em>";
}

void getText(string str) {
	// cout << "str:" << str;
	int length = str.size();
	for (int i = 0; i < length; i++) {
		if (str[i] == '_') {
			int j = i + 1;
			while (str[j] != '_') {
				j++;
			}
			emphasize(str.substr(i, j - i + 1));
			i = j;
		}
		else if (str[i] == '[') {
			int j = i + 1;
			while (str[j] != ')') {
				j++;
			}
			herf(str.substr(i, j - i + 1));
			i = j;
		}
		else {
			cout << str[i];
		}
	}
}

int main() {
	string line;
	// pre 表示前一行是什么区块类型
	// 0 表示空行,1 表示段落,2 表示标题,3表示列表
	int pre = 0;
	while (getline(cin, line)) {
		if (line.empty()) {
			if (pre == 1) {
				cout << "</p>" << endl;
			}
			else if (pre == 3) {
				cout << "</ul>" << endl;
			}
			pre = 0;
		}
		else if (line[0] == '#') {
			int count = 0;
			int pos = 0;
			while(line[pos] == '#') {
				count++;
				pos++;
			}
			if (count <= 6) {
				cout << "<h" << count << ">";
			}
			else {
				cout << "<h6>";
			}
			while (line[pos] == ' ') {
				pos++;
			}
			// cout << pos;
			getText(line.substr(pos));
			if (count <= 6) {
				cout << "</h" << count << ">" << endl;
			}
			else {
				cout << "</h6>" << endl;
			}
			pre = 2;
		}
		else if (line[0] == '*') {
			if (pre != 3) {
				cout << "<ul>" << endl;
			}
			int pos = 1;
			while (line[pos] == ' ') {
				pos++;
			}
			cout << "<li>";
			getText(line.substr(pos));
			cout << "</li>" << endl;
			pre = 3;
		}
		else {
			if (pre != 1) {
				cout << "<p>";
			}
			else if (pre == 1) {
				cout << endl;
			}
			getText(line.substr(0));
			pre = 1;
		}
	}
	if (pre == 1) {
		cout << "</p>";
	}
	else if (pre == 3) {
		cout << "</ul>";
	}

	return 0;
}