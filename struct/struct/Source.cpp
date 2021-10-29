#include <stdio.h>

typedef struct {
	int member;
	char str[16];
}structname;

void function(structname arg1, structname* arg2);

int main() {
	structname A = { 1, "hoge1" };
	structname B;
	structname tmp;
	structname* C = &tmp;
	structname D[2];
	
	function(A, &A);
	B.member = 2;
	sprintf_s(B.str, sizeof(B.str), "hoge2");
	C->member = 3;
	sprintf_s(C->str, sizeof(C->str), "hoge3");
	D[0].member = 4;
	sprintf_s(D[0].str, sizeof(D[0].str), "hoge4");
	
	printf("A : %d %s\n", A.member, A.str);
	printf("B : %d %s\n", B.member, B.str);
	printf("C : %d %s\n", C->member, C->str); //C->member = (*C).member
	printf("D : %d %s\n", D[0].member, D[0].str);
	return 0;
}

void function(structname arg1, structname* arg2) {
	arg1.member = 0; //’l“n‚µ
	sprintf_s(arg2->str, sizeof(arg2->str), "hoge0"); //QÆ“n‚µ
	return;
}
