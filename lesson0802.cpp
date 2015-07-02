#include <iostream>
#include <fstream>

using namespace std;

// struct Node
// {
// 	int pic;
// 	Node* next;
// };


int main()
{
	int data[100]= {0};
	ifstream fin("8-2.jpg", ios::binary);
	for(int i = 0; i< 100; i++)
	{
		fin.read((char*)&data[i] , 1);
	}
	fin.close();
	int sum;
	sum = data[12]^data[48]^data[79];
	printf("%x",sum);
	// cout << hex << sum << endl;
	return 0;
}
