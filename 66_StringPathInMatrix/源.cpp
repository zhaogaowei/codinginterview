#include <iostream>

using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, bool *visited, char* str,int &pathLength) {
	if (str[pathLength] == '\0')
		return true;
	bool hasPath = false;
	if (!visited[row*cols+col] && matrix[row*cols+col]==str[pathLength]) {
		visited[row*cols + col] = true;
		pathLength++;
		hasPath = hasPathCore(matrix, rows, cols, row + 1, col, visited, str, pathLength)
			|| hasPathCore(matrix, rows, cols, row, col + 1, visited, str, pathLength)
			|| hasPathCore(matrix, rows, cols, row - 1, col, visited, str, pathLength)
			|| hasPathCore(matrix, rows, cols, row, col - 1, visited, str, pathLength);
		if (!hasPath)
		{
			visited[row*cols + col] = false;
			pathLength--;
		}
	}
	return hasPath;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (!matrix || rows <= 0 || cols <= 0 || !str)
		return false;
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int pathLength = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (hasPathCore(matrix,rows,cols,i,j,visited,str,pathLength))
				return true;
		}
	}
	delete visited;
	return false;
}
int main() {
	char matrix[12] = { 'a','b','c','e',
		's','f','c','s',
		'a','d','e','e' };
	cout << hasPath(matrix, 3, 4, "bcced") << endl;
	return 0;
}