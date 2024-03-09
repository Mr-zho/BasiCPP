#include <iostream>
using namespace std;

#define BUFFER_SIZE 100000000



void test01()
{
    /* 
    1. 异常的语法 
    try
    {

    }
    catch(...)
    {

    }
    2. 如果程序出现异常, 出异常之后的代码就不会执行了。

    */
    cout << "111" << endl;
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        try
        {   
            int * num = new int[1000000000];
            cout << "22222" << endl;
        }
        catch (...)      /* ... 代表捕捉任意异常 */
        {
            cout << "内存不够" << endl;
            break;
        }
        /* 4. 如果异常不被处理, 程序就终止了. */
    }
    cout << "333333333" << endl;
}


/* 
    主动抛异常 
    语法:
        throw (int)123 : 整形
        throw (stirng)"123" : 字符串
*/
int myDivide(int val1, int val2)
{
    if (val2 == 0)
    {
        #if 0
        throw "除数不能为0";
        #else
        throw 666;
        #endif
    }
    return val1 / val2;
}


/* 异常声明: 
    case 1: 可能会抛出任何异常 */
int func1()
{
    return 0;
}

int func3() noexcept(false)     /* 可能会抛出异常. */
{
    return 0;
}




/* 异常声明: 
    case 2: 不抛出任何异常 */

/* 
    @brief:         XXX
    @argument1:
    @argument2:
    @return:
*/
int func2() throw()
{
    return 0;
}

int func4() noexcept        /* 保证不抛出以上 */
{
    return 0;
}

int func4() noexcept(true)        /* 保证不抛出以上 */
{
    return 0;
}



#if 0
/* 异常声明: 
    case 3: 只可能抛出int double类型的异常 */
int func3() throw(int, double)
{
    return 0;
}
#endif

/* 异常声明的目的: 为了团队开发 */


/* 1. 捕捉异常 */
int main()
{
    // test01();

    try
    {
        /* 主动抛异常 */
        myDivide(100, 0);
    }
    catch(const char * str)      /* 使用捕捉所有异常 */
    {
        cout << "此函数主动抛出异常:" << str << endl;
    }
    catch(int code)
    {
        cout << "此函数主动抛出异常:" << code << endl;
    }

    cout << "hello world" << endl;
    return 0;
}