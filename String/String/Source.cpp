#include <string>
#include <string.h>
#include <iostream>
using namespace std;

#define STR_SIZE 10

int main()
{
	char c1[STR_SIZE] = "hoge";
	char c2[STR_SIZE] = "fuga";
	string s1 = "foo";
	string s2 = "bar";
	string s3;

	strcat_s(c1, sizeof(c1), c2); //Concatenate c2 after c1
	cout << c1 << ", " << c2 << endl;
	strcpy_s(c1, sizeof(c1), c2); //Copy c2 to c1
	cout << c1 << ", " << c2 << endl;
	cout << strlen(c1) << endl;

	s3 = s1 + s2;
	cout << s3 << endl;
	cout << s3[0] << endl;
	cout << s3.size() << endl;

	getchar();
	return 0;
}