#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
int enroll_u1(int, char);
int enroll_u2(int, char);

int A_max, B_max, C_max;
string id;
int score;
char u1,u2;
int A_num =0, B_num=0, C_num=0;
int A_score, B_score, C_score;

int enroll_u1(int score, char u1)
{
	if(u1 == 'A')
	{
		if(A_max == A_num)
			return false;
		else{
			//A_max -= 1;
			A_num += 1;
			A_score = score;
			return true;
		}
	}
	else if(u1 == 'B')
	{
		if(B_max == B_num)
			return false;
		else{
		//B_max -= 1;
		B_num += 1;
		B_score = score;
		return true;}
	}
	else if(u1 == 'C')
	{
		if(C_max == C_num)
			return false;
		else{
		//C_max -= 1;
		C_num += 1;
		C_score = score;
		return true;}
	}
}

int enroll_u2(int score, char u2)
{
	if(u2 == 'A')
	{
		if(A_max == A_num)
			return false;
		else{
		// A_max -= 1;
		A_num += 1;
		A_score = score;
		return true;}
	}
	else if(u2 == 'B')
	{
		if(B_max == B_num)
			return false;
		else{
		// B_max -= 1;
		B_num += 1;
		B_score = score;
		return true;}
	}
	else if(u2 == 'C')
	{
		if(C_max == C_num)
			return false;
		else{
		// C_max -= 1;
		C_num += 1;
		C_score = score;
		return true;}
	}
}



int main()
{
	int count;

	ifstream fin("datain.txt");
	fin >> A_max >> B_max >> C_max;
	while(1)
	{
		
		
		fin >> id >> score >> u1 >> u2;
		if(fin.eof())
			break;
		if(enroll_u1(score, u1))
			cout << A_num << " " << B_num << " " << C_num << endl;
			// count++;
		else if(enroll_u2(score,u2))
			cout << A_num << " " << B_num << " " << C_num << endl;
			// count++;
	}
	fin.close();

	ofstream fout("dataout.txt");

	fout << A_num << " " << A_score << " " << B_num << " " << B_score << " " << C_num << " " << C_score << endl;

	fout.close();
	return 0;
}
