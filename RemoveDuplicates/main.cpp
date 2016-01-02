#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int i = 0, j = 0;
		int num = 0;
		while (++j < nums.size()){
			if (nums[i] != nums[j]){
				num = 0;
				nums[++i] = nums[j];
			}
			else
			{
				num++;
				if (num == 1){ 
					nums[++i] = nums[j]; 
				}
			}
		}
		return ++i;
	}
	void print(vector<int>& v){
		for (vector<int>::const_iterator it = v.begin();
			it != v.end(); ++it){
			cout << (*it) << " ";
		}
	}
};

int main(){
	vector<int> v = { 1, 2, 2, 3, 3, 3, 4, 5 };
	Solution S;
	cout << S.removeDuplicates(v) << endl;
	S.print(v);
	return 0;
}