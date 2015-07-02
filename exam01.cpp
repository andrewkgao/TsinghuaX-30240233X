#include <iostream>
using namespace std;

int main()
{
	int y;
	int a;
	int b;
	int c;
	cin >> y;
	for(a=1; a<=9; a++)
	{
		for(b=0;b<=9; b++)
		{
			for(c=0;c<=9;c++)
			{
				if(((a*10+b)*c+a) ==y)
					{
						cout << a << " " << b << " " << c << endl;
					}
			}
		}
	}
	return 0;
}
