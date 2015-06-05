#include <iostream>
#include <fstream>
using namespace std;

struct count
{
	int letterNum;
};

int main()
{
	int maxNum[5]={0};
	int max[5]={0};
	count ct[200] = {0};
	ifstream numChar("7-3news.txt");
	char letter;
	while(!numChar.eof()){
		numChar >> letter;
		ct[int(letter)].letterNum++;
	} //将所有的字母都统计进入该字母对应asc码编号的数组中
	//把所有的大写个数都加入到小写个数当中。
	for(int i = 65; i< 91; i++)
	{
		ct[i+32].letterNum += ct[i].letterNum;
	}
	//接下来对数组进行排序
	maxNum[0] = ct[97].letterNum;
	for(int i = 0; i <5; i++)
	{
		for(int j = 97; j<123; j++)
		{
			if(maxNum[i] < ct[j].letterNum){
				maxNum[i] = ct[j].letterNum;
				max[i] = j;
				ct[j].letterNum = -1;
			}
		}
	}
	for(int i = 0; i < 5; i++)
	{
		cout << char(max[i]) << " " << maxNum[i] << endl;
	}
	//cout << ct[97].letterNum << endl;
	numChar.close();
	return 0;
}