#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct user
{
	string user_name, user_status;
	int day, month, year, hour, min, sec;
};

int main()
{
	user u[150];
	string name;
	int count=0;
	string status;
	int days, months, years, hours, mins, secs;
	char tmp;

	ifstream fin("7-2log.txt");
	
	while(!fin.eof()){
		fin >> name >> status >> days >> tmp >> months >> tmp >> years >> hours >> tmp >> mins >> tmp >> secs;
		int found = 0;
		for(int i = 0;i<= count; i++){
			if(name == u[i].user_name){
				found = 1;
				break;
			}
		}
		if(found == 0){
			u[count].user_name = name; 
			count++;
		}
	}

	fin.close();
	cout << count << endl;
	return 0;
}
