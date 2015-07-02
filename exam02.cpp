#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;


 void FillMatrix(int (*mat)[100], int size, int num, int offset) // size剩下的矩阵大小，num剩下矩阵的开始数字，offset剩下矩阵的开始位置
 {
 
 	if(size == 0)
 		return;
 	if(size == 1)
 	{
 		mat[offset][offset] = num;
 		return;
 	}
 	for(int i = 0; i < size-1; i++)
 	{
 		mat[offset + i][offset] = num - i;
 		mat[offset +size -1][offset +i] = num - (size -1) - i;
 		mat[offset +size -1 -i][offset + size -1] = num - 2 * (size-1) - i;
 		mat[offset][offset +size-1 -i] = num - 3 * (size-1) - i;
  	}

 	FillMatrix(mat, size -2, num - 4*(size-1), offset+1);
}


 int main()
 {
	int max;
	cin >> max;
 	int mat[max][100];
 	int size = max;
 	int num = max*max;
 	int offset = 0;
 	FillMatrix(mat, size, num, offset);
 	for(int i = 0; i < max; i++)
 	{
 		for(int j = 0; j < max; j++)
 		{
 			if(mat[i][j] >= 10)
	 			cout << mat[i][j] << " ";
	 		else
	 			cout << " " << mat[i][j] << " ";
 		}
 		cout << endl;
 	}
 	return 0;
 }
