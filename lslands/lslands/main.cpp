//#include "GraphMatrix.h"
#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
typedef enum{UNDISCOVERED,DISCOVERED,VISITED,WALL}Status;
typedef enum{ UNKNOWN, EAST, SOUTH, WEST, NORTH, NOWAY }ESWN;
struct Cell{
	Status status;
	ESWN incoming, outcomming;
	Cell() :status(UNDISCOVERED), incoming(EAST), outcomming(UNKNOWN){}
};
ESWN nextESWN(ESWN eswn){ return ESWN(eswn + 1); }
class Solution {
public:
	typedef std::pair<int, int> pos;
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		int n = 0;
		vector<char>::size_type h_max = grid.front().size();
		vector<vector<char> >::size_type v_max = grid.size();
		vector< vector< Cell> > cell_bak(v_max+2, vector<Cell>(h_max+2, Cell()));
		for (vector<Cell>::iterator it = cell_bak.front().begin();
			it != cell_bak.front().end(); ++it){
			(*it).status = WALL; 
		}
		for (vector<Cell>::iterator it = cell_bak.back().begin();
			it != cell_bak.back().end(); ++it){
			(*it).status = WALL;
		}
		for (vector<vector<Cell> >::iterator it = cell_bak.begin();
			it != cell_bak.end(); ++it){
			(*it).front().status = WALL;
		}
		for (vector<vector<Cell> >::iterator it = cell_bak.begin();
			it != cell_bak.end(); ++it){
			(*it).back().status = WALL;
		}
		cell = cell_bak;
		for (int i = 1; i < width() - 1; ++i){
			for (int j = 1; j < length() - 1; ++j){
				pos v(i, j);
				if( (UNDISCOVERED == cell[v.first][v.second].status) && (grid[v.first-1][v.second-1]=='1')){
					BFS(v, grid);
					n++;
				}
			}
		}
		
		return n;
	}
	void BFS(pos v, const vector<vector<char> > &grid){
		queue<pos> Q;
		cell[v.first][v.second].status = DISCOVERED;
		Q.push(v);
		while (!Q.empty()){
			v = Q.front(); Q.pop();
			while (NOWAY > (cell[v.first][v.second].outcomming = nextESWN(cell[v.first][v.second].outcomming))){
				pos u = neighbor(v);
				if ((UNDISCOVERED == cell[u.first][u.second].status) && (grid[u.first - 1][u.second - 1] == '1')){
					cell[u.first][u.second].status = DISCOVERED;
					Q.push(u);
				}
			}
			cell[v.first][v.second].status = VISITED;
		}
	}
	pos neighbor(const pos& v){
		switch (cell[v.first][v.second].outcomming){
		case EAST: return pos(v.first + 1, v.second); break;
		case SOUTH: return pos(v.first, v.second + 1); break;
		case WEST: return pos(v.first - 1, v.second); break;
		case NORTH: return pos(v.first, v.second - 1); break;
		}
	}
	vector<Cell>::size_type width()const{
		if (!cell.empty()) return cell.size();
		else return 0;
	}
	vector< vector<Cell> >::size_type length()const{
		if (!cell.empty()) return cell.front().size();
		else return 0;
	}
	void print(){
		for (vector<vector<Cell> >::const_iterator it = cell.begin();
			it != cell.end(); ++it){
			for (vector<Cell>::const_iterator iit = (*it).begin();
				iit != (*it).end(); ++iit){
				if ((*iit).status == VISITED)
					std::cout << '*'<< ' ';
				else if ((*iit).status == WALL)
					std::cout << '0' << ' ';
				else
					std::cout << '#' << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << "--------------------------" << std::endl;
	}
private:
	vector< vector< Cell> > cell;
};
int main(void){
	Solution S;
	vector<vector<char> > grid(1, vector<char>(1, '1'));
	std::cout << S.numIslands(grid) << std::endl;;

	return 0;
}