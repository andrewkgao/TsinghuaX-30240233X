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
	} //�����е���ĸ��ͳ�ƽ������ĸ��Ӧasc���ŵ�������
	//�����еĴ�д���������뵽Сд�������С�
	for(int i = 65; i< 91; i++)
	{
		ct[i+32].letterNum += ct[i].letterNum;
	}
	//�������������������
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