#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (string::const_iterator it = s.begin();
			it != s.end(); ++it){
			res = res * 26 + charToNumber(*it);
		}
		return res;
	}
	int charToNumber(char c){
		return c - 64;
	}

};

int main(void)
{
	Solution S;
	const string s("AA");
	cout << S.titleToNumber(s) << endl;
	return 0;
}