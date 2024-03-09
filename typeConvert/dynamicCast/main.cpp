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
    // Student *  = new Student();
    Person * p1 = new Student();
    p1->run();
    delete p1;
    #endif

    #if 0
    Student * stu1 = new Person();
    stu1->run();
    delete stu1;
    #endif

    Person * p1 = new Person();      // 自己指向自己 
    Person * p2 = new Student();     // 父类指针指向子类对象

    /* 错误示范 */
    // Student * stu1 = p1;
    // Student * stu2 = p2;

    // 解决
    #if 1
    Student * stu1 = (Student * )p1;
    stu1->run();
    /* 错误使用内存, 踩内存. */
    stu1->m_score = 666;
    /* 
        内存泄露:
            1.野指针
            2.malloc分配没有释放
            3.踩内存 (其中子类指针指向父类没有使用dynamic_cast 或许会踩内存[因为没有约束])
    */


    Student * stu2 = (Student * )p2;
    stu2->run();
    
    #else
    /* 运行时安全检测 */
    Student * stu1 = dynamic_cast<Student * >(p1);
    cout << "stu1:" << stu1 << endl;
    stu1->run();

    Student * stu2 = dynamic_cast<Student * >(p2);
    cout << "stu2:" << stu2 << endl;




    #endif

  



    return 0;
}

