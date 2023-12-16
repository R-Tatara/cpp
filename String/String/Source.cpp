#include <iostream>
using namespace std;

#define STR_SIZE 10

void Function1(char str[], size_t bufferSize) { //�A�h���X�n���i�l�n���̂Ƃ���const��t����j
//void Function1(char str[STR_SIZE], size_t bufferSize) { //����
//void Function1(char *str, size_t bufferSize) { //����
	strcpy_s(str, bufferSize, "Function1");
}

void Function2(string str) { //�l�n��
	str = "Function2";
}

void Function3(string *str) { //�|�C���^�n��
	*str = "Function3";
}

void Function4(string &str) { //�Q�Ɠn��
	str = "Function4";
}

int main() {
	char c1[STR_SIZE] = "hoge";
	string s1 = "hoge";

	//Standart output
	printf("%s (sizeof:%zd, strlen:%zd)\n", c1, sizeof(c1), strlen(c1));
	printf("%s (size:%zd)\n", s1.c_str(), s1.size());
	puts("");

	//Assignment
	strcpy_s(c1, sizeof(c1), "foo");
	printf("%s (sizeof:%zd, strlen:%zd)\n", c1, sizeof(c1), strlen(c1));
	s1 = "foo";
	printf("%s (size:%zd)\n", s1.c_str(), s1.size());
	puts("");

	//Function
	Function1(c1, STR_SIZE);
	printf("%s (sizeof:%zd, strlen:%zd)\n", c1, sizeof(c1), strlen(c1));
	puts("");

	Function2(s1); //�l�n��
	printf("%s (size:%zd)\n", s1.c_str(), s1.size());
	Function3(&s1); //�|�C���^�n��
	printf("%s (size:%zd)\n", s1.c_str(), s1.size());
	Function4(s1); //�Q�Ɠn��
	printf("%s (size:%zd)\n", s1.c_str(), s1.size());
	puts("");

	//Conversion between char and string
	char c2[STR_SIZE] = "ABC";
	string s2 = "DEF";
	string s0;

	s0 = c2; //From char to string
	printf("%s (size:%zd)\n", s0.c_str(), s0.size());

	strcpy_s(c2, sizeof(c2), s2.c_str()); //From string to char
	printf("%s (sizeof:%zd, strlen:%zd)\n", c2, sizeof(c2), strlen(c2));
	puts("");

	//Automatic sizing
	char c3[] = "123";
	const char *p3 = "123";

	printf("%s (sizeof:%zd, strlen:%zd)\n", c3, sizeof(c3), strlen(c3));
	printf("%s (sizeof:%zd, strlen:%zd)\n", p3, sizeof(p3), strlen(p3)); //sizeof(p3)�̓|�C���^�̃T�C�Y�ƂȂ邽�ߒ���
	puts("");

	getchar();
	return 0;
}