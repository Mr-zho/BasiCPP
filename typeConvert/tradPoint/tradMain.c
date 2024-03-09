#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10



// int printInfo(const char *str)
// {
//     *(str + 3) = 'A';
// }


int main()
{
    #if 0
    /* void * 强转 */
    char * ptr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    free(ptr);
    #elif 0
    /* 类型强转 */
    struct sockaddr_in localAddress;
    bind(sockfd, (const struct sockaddr *)&localAddress, XXX);
    #elif 0
    /* 常量 */
    const int num = 100;

    #if 0
    /* 直接修改 改不了. */
    num = 666;
    #else
    int * pNum = &num;
    *pNum = 666;
    printf("num:%d\n", num);
    #endif
    #elif 0
    char buffer[BUFFER_SIZE] = "hello";

    printInfo(buffer);

    printf("buffer:%s\n", buffer);
    #else
    const char * str = "hello world";
    char * buffer = str;
    printf("buffer:%s\n", buffer);
    #endif
    return 0;
}