#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int lo = bin_search_l(nums, 0, nums.size(),target);
		int hi = bin_search_r(nums, 0, nums.size(), target);
		vector<int> B;
		if (lo == nums.size()||nums[lo] !=target) lo = -1;
		if (nums[hi] != target) hi = -1;
		B.push_back(lo);
		B.push_back(hi);
		return B;
	}
	int bin_search_r(vector<int> &A, int lo, int hi, int v){
		while (lo < hi){
			int mi = (lo + hi) / 2;
			if (A[mi] > v){
				hi = mi;
			}
			else{
				lo = mi + 1;
			}
		}
		return --lo;

	}
	int bin_search_l(vector<int> &A, int lo, int hi, int v){
		while (lo < hi){
			int mi = (lo + hi) / 2 ;
			if (A[mi] < v){
				lo = mi + 1;
			}
			else{
				hi = mi;
			}
		}
		return hi;
	}
};
int main(void){
	Solution S;
	vector<int> A = { 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> B;
	B = S.searchRange(A, 210);
	cout << B[0] << " " << B[1] << endl;
	return 0;
}