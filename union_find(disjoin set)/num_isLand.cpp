#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <ctime>
#include <map>
using namespace std;

#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>

int row;
int col;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<char>>grid;
vector<vector<int>>position;
bool isValid(int i,int j){
	if (i < 0 || i >= row){
		return false;
	}
	if (j < 0 || j >= col){
		return false;
	}
	return true;
}

void genModel(){
	srand((unsigned int)time(NULL));
	row = rand() % 10 + 1;
	col = rand() % 10 + 1;
	grid.resize(row,vector<char>(col));
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			int gen = rand() % 2;
			if (gen == 0){
				grid[i][j] = '0';
			}
			else {
				grid[i][j] = '1';
			}
		}
	}
}

void addIsland(int i,int j){
	if (!isValid(i,j))  return;
	grid[i][j] = '1';
}	
	
void dfs(vvb& seen,int i,int j){
	if (!isValid(i,j) || seen[i][j] == true){
		return;
	}
	seen[i][j] = true;
	if (grid[i][j] == '0'){
		return;
	}
	int temp_x;
	int temp_y;
	for (int k = 0; k < 4; k++){
		temp_x = i + dx[k];
		temp_y = j + dy[k];
		dfs(seen,temp_x,temp_y);
	}
}
	
int numIslands() {
	row = grid.size();
	col = grid[0].size();
	vector <vector<bool>> seen(row,vector<bool>(col,false));
	
	int count = 0;
	int x;
	int y;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (grid[i][j] == '1' && seen[i][j] == false){
				count++;
				dfs(seen,i,j);
			} 
			
		}
	}
	return count;
}

void genPosition(){ 
	srand(time(NULL));
	int row_size = rand() % (row * col - 1);
	position.resize(row_size,vector<int>(2));
	map <pair<int,int>,bool> mp{};
	int gen_x;
	int gen_y;
	for (int i = 0; i < row_size; i++){
		do{
			gen_x = rand() % row;
			gen_y = rand() % col;
		}while(mp[{gen_x,gen_y}] == true);
		position[i][0] = gen_x;
		position[i][1] = gen_y;
		mp[{gen_x,gen_y}] = true;
		// grid[gen_x][gen_y] = '1';
	}
}

int findPath(int* &path,int i,int j){
	int diff = 1;
	for (int dir = 0; dir < 4; dir++){
		int target = i * col + j;
		int curr = (i + dx[dir]) * col + (j + dy[dir]);
		if (i >= - dx[dir] && i < row - dx[dir] && j >= - dy[dir] && j < col - dy[dir] && path[curr] != -1){
			
			while (path[target] != target){
				target = path[target];
			}
			while (path[curr] != curr){
				curr = path[curr];
			}
			if (target != curr){
				path[curr] = target;
				diff --;
			}
		}		
	}
	return diff;
}

vector <int> numIslands2(vector<vector<int>>&position){
	vector<int> res;
	
	if (row == 0 || col == 0 || !position.size()){
		return res;
	}
	
	int* path = new int[row * col];
	for (int i = 0; i < row * col - 1; i++){
		path[i] = -1;
	}
	
	int size = 0;
	int dem = 0;
	for(auto& pos : position){
		int i = pos[0];
		int j = pos[1];
		path[i * col + j] = i * col + j;
		size += findPath(path,i,j);
		res.push_back(size);
		grid[i][j] = '1';
	}
	delete []path;
	return res;
}

void printLand(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
}

void resetGrid(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			grid[i][j] = '0';
		}
	}
}

void algorithm(){
	genModel();
	resetGrid();
	genPosition();
	vector <int> res = numIslands2(position);
	cout << res[res.size() - 1] << endl;
	printLand();
}

int main(){
	// genModel();
	// int num = numIslands();
	// printLand();
	// cout << num << endl;
	algorithm();
	
	return 0;
}