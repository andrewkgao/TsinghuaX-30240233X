#include <iostream>
using namespace std;

struct timeBetween
{
	int year, month, day;	
};
int calMonthAndDays(int,int, int); 

int calDays(timeBetween t1, timeBetween t2){
	int days = 0;
	int days_year=0;
	int tmp1=0;
	int tmp2 = 0;
	//����t2.year - t1.year��Ȼ��õ��Ľ��-t1��month��day������t2��month��day
	for(int i = t1.year; i < t2.year;i++){
		if(i % 4 == 0){
			days_year += 366;
		}
		else {
			days_year += 365;
		}
	}
	//���ȼ��������е����ӣ�������Ҫ��ȥt1������

	tmp1 = calMonthAndDays(t1.year,t1.month, t1.day);
	//days = days_year - tmp;
	//��������Ҫ����t2�����ӣ�t2���º��գ���ʵ��t1��һ����
	tmp2 = calMonthAndDays(t2.year,t2.month, t2.day);
	days = days_year - tmp1 + tmp2;
	return days;
}

int calMonthAndDays(int y,int m, int d){
	int tmp = 0;
	for(int i = 1;i < m; i++){
		if(i == 2){
			if(y % 4 == 0){
				tmp += 29;
				continue;
			}
			else{
				tmp +=28;
				continue;
			}
		}
		if(i <= 7){
			if(i%2 == 0){
				tmp += 30;
				continue;
			}
			else{
				tmp += 31;
				continue;
			}
		}
		if(i >= 8){
			if(i%2 == 0){
				tmp += 31;
				continue;
			}
			else{
				tmp += 30;
				continue;
			}
		}
	}
	tmp += d;
	//cout << tmp << endl;
	return tmp;
}

int main()
{
	char tmp;
	int day1,day2;
	timeBetween t1;
	timeBetween t2;
	cin >> t1.year >> tmp >> t1.month >> tmp >> t1.day;
	cin >> t2.year >> tmp >> t2.month >> tmp >> t2.day;
	cout << calDays(t1, t2) << endl;
	
	return 0;
}
