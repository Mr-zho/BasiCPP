#include <iostream>
using namespace std;
#include <string>

#define BUFFER_SIZE 100000000

/* 
    抽象类 : 
        1.  具有纯虚函数的类叫做抽象类。纯虚函数: 虚函数初始化为0. 
        2.  抽象类不能实例化对象
*/
class Exception
{
public:
    virtual string what() const = 0;
};

/* 出发异常类别 */
class DivideException : public Exception
{
public:
    string what() const
    {
        // cout << "不能除以0" << endl;
        return "不能除以0";
    }
};

class MemoryFlowException : public Exception
{
public:
    string what() const
    {
        // cout << "内存溢出" << endl;
        return "内存溢出";
    }
};

/* noexcept 同throw */
int divide(int val1, int val2) noexcept(false)
{
    if (val2 == 0)
    {
        throw DivideException();
    }
    
    return val1 / val2;
}


int simulateNewException() 
{
    for (int idx = 0; idx < 1000; idx++)
    {
        #if 0
        try
        {
            /* code */
            int * nums = new int[1000000000];
        }
        catch(const std::exception& e)
        {
            cout << "内存错误:" << e.what() << endl;
            break;
            // std::cerr << e.what() << '\n';
        }
        #else
        try
        {
            /* code */
            int * nums = new int[1000000000];
        }
        catch(const std::bad_alloc& e)
        {
            cout << "内存错误:" << e.what() << endl;
            break;
            // std::cerr << e.what() << '\n';
        }
        #endif
    }
    return 0;
}

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    virtual void run()
    {
        cout << "Person() run" << endl;
    }
public:
    int m_age;
};

class Student : public Person
{
public:
    Student()
    {
        cout << "Student()" << endl;
    }

    void run()
    {
        cout << "Student() run" << endl;
    }
public:
    int m_score;
};

int simulateDynamicCastException()
{   
    Person * p1 = new Person();     /* 自己指向自己*/
    Person * p2 = new Student();    /* 父类指针指向子类对象 */

    /* test */
    Person &p3 = *p1;
    try
    {
        /* dynamic_cast 安全检测不算异常 */
        Student *stu1 = dynamic_cast<Student *>(p1); 
        cout << "stu1:"  << stu1 << endl;  
    }
    catch(const std::bad_cast &e)
    {
        cout << "dynamic_cast1" << e.what() << endl;
    }

    try
    {
        Student * stu2 = dynamic_cast<Student *>(p2);    
    }
    catch(const std::exception &e)
    {
        cout << "dynamic_cast2" << e.what() << endl;
    }

    try
    {
        /* dynamic_cast 安全检测也是异常 */
        Student &stu3 = dynamic_cast<Student &>(p3); 
        // cout << "stu1:"  << stu3 << endl;  
    }
    catch(const std::bad_cast &e)
    {   
        cout << "dynamic_cast3:" << e.what() << endl;
    }
    return 0;
}

int main()
{    
    #if 0
    try
    {
        /* code */
        int val1 = 100;
        int val2 = 0;
        int res = divide(val1, val2);
        cout << "res:" << res << endl;
    }
    catch(const Exception& e)
    {
        cout << e.what() << endl;
    }
    #endif


    simulateNewException();

    simulateDynamicCastException();



    
    

    cout << "hello world" << endl;
    return 0;
}