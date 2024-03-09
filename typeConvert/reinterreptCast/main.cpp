#include <iostream>
using namespace std;


/* 
    多态三要素:
        1. 父类指针指向子类对象
        2. 子类重写父类方法(override)。 (方法得是虚函数)
        3. 子类 public继承 父类
*/

class Person
{
public:
    /* 构造函数 */
    Person() 
    {
        cout << "Person()" << endl;
    }

    /* 析构函数 */
    virtual ~Person() 
    {
        cout << "~Person()" << endl;
    }

    virtual void run()
    {
        cout << "Person::run()" << endl;
    }
private:
    int m_age;
};

class Student : public Person
{
public:
    /* 构造函数 */
    Student() 
    {
        // m_score = new int;
        cout << "Student()" << endl;
    }

    /* 析构函数 */
    ~Student() 
    {
        // delete m_score;
        cout << "~Student()" << endl;
    }

    void run()
    {
        cout << "Student::run()" << endl;
    }

    void study()
    {
        cout << "Student::study()" << endl;
    }
public:
    int m_score;
};

int main()
{
    #if 0
    /* 1. reinterpret_cast 没有安全检测 */
    Person * p1 = new Person();      // 自己指向自己 
    Person * p2 = new Student();     // 父类指针指向子类对象

    Student * stu1 = reinterpret_cast<Student * >(p1);
    cout << "stu1:" << stu1 << endl;

    Student * stu2 = reinterpret_cast<Student * >(p2);
    cout << "stu2:" << stu2 << endl;
    #endif

    #if 1
    /* 
        p = 100
        p = 0X64;    
    */
    int * p = reinterpret_cast<int*>(100);
    /* p = 0X64 */
    cout << "p:" << p << endl;

    int num = reinterpret_cast<long>(p);
    cout << "num:" << num << endl;





    #endif
    
    return 0;
}

