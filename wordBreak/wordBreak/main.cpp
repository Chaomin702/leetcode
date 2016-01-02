#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		queue<int> Q;
		unordered_set<int> visited;
		Q.push(0);
		while (!Q.empty()){
			int start = Q.front();
			Q.pop();
			if (visited.find(start) == visited.end()){
				visited.insert(start);
				for (int i = start; i < s.size(); i++){
					string str = s.substr(start, i - start + 1);
					if (wordDict.find(str) != wordDict.end()){
						Q.push(i+1);
						if (i + 1 == s.size()) return true;
					}
				}
			}
		}
		return false;
	}
	vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {

	}
};
int main(){
	unordered_set<string> s = { "aaaa", "aa" };
	Solution solution;
	cout << solution.wordBreak("aaaaaaa", s) << endl;
	return 0;
}