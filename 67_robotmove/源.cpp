#include <iostream>

using namespace std;

int getSum(int row, int col) {
	int sum = 0;
	while (row) {
		sum += row % 10;
		row /= 10;
	}
	while (col)
	{
		sum += col % 10;
		col /= 10;
	}
	return sum;
}
bool check(int rows, int cols, bool* visited, int row, int col, int threshold) {
	if (row < rows&&row >= 0 && col >= 0 && col < cols&&getSum(row,col) <= threshold && !visited[row*cols + col])
		return true;
	else
		return false;
}
int movingCountCore(int rows,int cols,bool* visited,int row,int col,int threshold) {
	int count = 0;
	if (check(rows, cols, visited, row, col, threshold)) {
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(rows, cols, visited, row + 1, col, threshold)
			+ movingCountCore(rows, cols, visited, row, col + 1, threshold)
			+ movingCountCore(rows, cols, visited, row - 1, col, threshold)
			+ movingCountCore(rows, cols, visited, row, col - 1, threshold);
	}
	return count;
}
int movingCount(int threshold, int rows, int cols)
{
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int count = movingCountCore(rows, cols, visited, 0, 0, threshold);
	delete visited;
	return count;
}
int main() {

}