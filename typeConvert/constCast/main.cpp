#include <iostream>
using namespace std;


class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }
    
    void run()
    {
        cout << "run()" << endl;
    }
private:
    int m_age;
};

int main()
{
    const char * str = "hello world";
    
    
    /* 基本数据类型 */
#if 0
    /* C语言写法 没问题 */
    // char * buffer = (char *)str;
#else
    /* 将const属性 转换为非const属性 */
    char * buffer = const_cast<char *>(str);
#endif


    /* 复合数据类型 */
    const Person *p1 = new Person();
#if 0
    Person * p2 = (Person *)p1;
#else
    Person * p2 = const_cast<Person *>(p1);
#endif
    p2->run();
    


    printf("buffer:%s\n", buffer);

    return 0;
}