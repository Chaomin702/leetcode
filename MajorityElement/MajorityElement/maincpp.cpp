#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};
int main()
{

	return 0;
}