#include <iostream>
using namespace std;
#include <string>

/* 
函数重载:
    1.  参数数量
    2.  参数类型
    3.  参数顺序 
*/
void func(int val)
{
    cout << "func(int val)" << endl;
}   

void func(int * pVal)
{
    cout << "func(int * pVal)" << endl;
}

int main()
{
    #if 0
    /* auto 的使用 */
    int a = 100;
    auto num = 666;
    cout << "num:" << num << endl;

    auto str = "hello world";
    cout << "str:" << str << endl;
    /* 建议: 少用。会增加同组开发人员的阅读难度 */

    auto * pNum = &a;
    cout << "*pNum:" << *pNum << endl;
    #endif

    
    #if 0
    /* decltype 可以获取变量的类型 */
    int num = 666;
    decltype(num) value = 777;

    string str = "hello 254";
    decltype(str) ptr = "hello jsetc";
    cout << "ptr:" << ptr << endl;
    
    /* 结合auto... */
    auto val = "hello nihao";
    decltype(val) buf = "long zhu";
    cout << "buf:" << buf << endl;
    #endif


    #if 0
    func(0);

    /* 二义性 */
    func(NULL); 
    func(nullptr);
    #endif


    #if 0
    int array1[5] = {11, 22, 33, 44, 55};
    cout << sizeof(array1) / sizeof(array1[0]) << endl;

    int array2[] = {11, 22, 33, 44, 55};
    cout << sizeof(array2) / sizeof(array2[0]) << endl;

    int array3[]{11, 22, 33, 44, 55};
    cout << sizeof(array3) / sizeof(array3[0]) << endl;

    /* 遍历 */
    for (int idx = 0; idx < sizeof(array2) / sizeof(array2[0]); idx++)
    {
        cout << array2[idx] << endl;
    }

    for (int item : array3)
    {
        // 不对, item已经是内部的元素
        // cout << array3[item] << endl;
        cout << item << endl;
    }

    int * num = nullptr;

    cout << *num << num;
    #endif
    return 0;
}