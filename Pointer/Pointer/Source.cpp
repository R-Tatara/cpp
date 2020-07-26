#include <iostream>
using namespace std;

#define SIZE 2

//変数
void function1(int arg) { //値渡し
    arg = 1;
}

void function2(int *arg) { //ポインタ渡し
    *arg = 1;
}

void function3(int &arg) { //参照渡し
    arg = 2;
}

//配列
void function4(int argarray[]) { //アドレス渡し（値渡しのときはconstを付ける）
//void function4(int argarray[SIZE]) { //同じ
//void function4(int *argarray) { //同じ
    argarray[0] = 1;
    //*(argarray) = 1; //同じ
    argarray[1] = 2;
    //*(argarray + 1) = 2; //同じ
}

//多次元配列
void function5(int argarray[SIZE][SIZE]) { //アドレス渡し
//void function5(int argarray[][SIZE]) { //同じ
//void function5(int (*argarray)[SIZE]) { //同じ
    argarray[1][1] = 1;
    //(*(argarray + 1))[1] = 1; //同じ
}

void function6(int argarray[SIZE][SIZE][SIZE]) { //アドレス渡し
//void function6(int argarray[][SIZE][SIZE]) { //同じ
//void function6(int (*argarray)[SIZE][SIZE]) { //同じ
    argarray[1][1][1] = 1;
    //(*(argarray + 1))[1][1] = 1; //同じ
}

//構造体
typedef struct {
    int val;
}structname;

void function7(structname argstruct) { //値渡し
    argstruct.val = 1;
}

void function8(structname *argstruct) { //アドレス渡し
    argstruct->val = 1;
}

void function9(structname argstruct[]) { //アドレス渡し（値渡しのときはconstを付ける）
//void function9(structname argstruct[SIZE]) { //同じ
//void function9(structname *argstruct) { //同じ
    argstruct[0].val = 3;
    argstruct[1].val = 3;
}

int main() {
    //変数
    int val = 0;
    function1(val);
    cout << val << endl; //0
    function2(&val);
    cout << val << endl; //1
    function3(val);
    cout << val << endl; //2

    //配列
    int array[SIZE] = {};
    function4(array);
    cout << array[0] << ", " << array[1] << endl; //1, 2

    //多次元配列
    int array2[SIZE][SIZE] = {};
    function5(array2);
    cout << array2[0][0] << ", " << array2[0][1] << ", " << array2[1][0] << ", " << array2[1][1] << endl; //0, 0, 0, 1

    int array3[SIZE][SIZE][SIZE] = {};
    function6(array3);
    cout << array3[1][1][1] << endl; //1

    //構造体
    structname hoge;
    structname *phoge = &hoge;
    hoge.val = 0;
    function7(hoge);
    cout << hoge.val << endl; //0
    function8(&hoge);
    //function8(phoge); //同じ
    cout << hoge.val << endl; //1

    //構造体配列
    structname huga[SIZE] = {2, 2};
    function9(huga);
    cout << huga[0].val << "," << huga[1].val << endl; //3, 3

    return 0;
}


