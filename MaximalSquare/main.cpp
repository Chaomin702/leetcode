#include <iostream>
#include <vector>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int maxNum = 0;
        int h = matrix.size(),w = matrix[0].size();
        for(int y=0;y<h;++y){
        	for(int x =0;x<w;++x){
        		if(matrix[y][x]=='0')	
        			continue;
        		int n = 1;
        		while(subSquare(matrix,x,y,n))
        			++n;
        		if(n>maxNum)
        			maxNum = n;
        	}
        }
        return maxNum*maxNum;
    }
    bool subSquare(const vector<vector<char>>& matrix,int x,int y,int t){
    	int h = matrix.size(),w = matrix[0].size();
    	if(x+t>=w || y+t>=h) return false;
    	for(int i=x;i<=x+t;++i){
    		if(matrix[y+t][i]=='0')
    			return false;
    	}
    	for(int i=y;i<y+t;++i){
    		if(matrix[i][x+t]=='0')
    			return false;
    	}
    	return true;
    }
};