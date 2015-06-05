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
	//首先t2.year - t1.year，然后得到的结果-t1的month和day，加上t2的month和day
	for(int i = t1.year; i < t2.year;i++){
		if(i % 4 == 0){
			days_year += 366;
		}
		else {
			days_year += 365;
		}
	}
	//首先计算了年中的日子，下面是要减去t1的月日

	tmp1 = calMonthAndDays(t1.year,t1.month, t1.day);
	//days = days_year - tmp;
	//接下来是要加上t2的日子，t2的月和日，其实跟t1是一样的
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
