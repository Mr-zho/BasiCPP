#include <iostream>
using namespace std;
#include <iomanip>
/* 头文件 */
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 64
#if 0
class FStream
{
    Open()
    {
        FILE * fopen()
        m_fd = open()
    }

private:
    FILE * fp;
    int m_fd;
};
#endif

int main()
{
    #if 0
    /* 设置域宽 */
    int num = 100;
    printf("num:%d\n", num);
    printf("num:%12d\n", num);
    printf("num:%-12d666\n", num);

    cout << "num:"<< setw(12) << 777 << endl;

    printf("num:123456789123\n");
    #endif
    
    
    const char * name = "./test.txt";
    #if 0
    /* case 1: 使用构造函数的方式打开文件 */
    ofstream ofs(name);
    #else
    /* case 2: open成员函数 打开文件 
        mode默认是: ios::out | ios::trunc
        ios::app:是以追加的方式写文件
    */
    ifstream ifs;
    ifs.open(name);
    #endif

    /* 判断文件是否打开成功 */
    if (!ifs.is_open())
    {
        cout << "open error" << endl;
        exit(-1);
    }

    /* 读文件到缓冲区 */
    char buffer[BUFFER_SIZE] = { 0 };

#if 0  
    /* 流输入 */
    ifs >> buffer;
#elif 0

    /* 读一行 */
    while (ifs.getline(buffer, sizeof(buffer)))
    {
        cout << "buffer:" << buffer << endl;
        sleep(1);
    }
#elif 1
    ifs.read(buffer, sizeof(buffer) - 1);
    cout << "buffer:" << buffer << endl;
#endif

    
    // ifs.getline(buffer, sizeof(buffer));
    // cout << "buffer:" << buffer << endl;

    // ifs.getline(buffer, sizeof(buffer));
    // cout << "buffer:" << buffer << endl;


    /* 关闭文件 */
    ifs.close();

    return 0;
}