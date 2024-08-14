#include <iostream>
#include <cstring>
#include<windows.h>
using namespace std;

#define SIZE 102
#define STYLE '='
#define FLAG '>'

void showProgress()
{
    const char *str = "|/-\\";
    char bar[SIZE];
    memset(bar, '\0', sizeof(bar));
    int i = 0;
    while (i <= 100)
    {
        printf("[%-100s][%d%%][%c]\r", bar, i, str[i % 4]); // 格式控制
        fflush(stdout);                                     // 刷新
        bar[i++] = STYLE;                                   // 填充数据
        if (i != 100)
        {
            bar[i] = FLAG; // 如果不是最后一次则显示 >
        }
        _sleep(50);
    }
    cout<<endl;
}

int main()
{
    CONSOLE_CURSOR_INFO curinfo;
    curinfo.dwSize = 1;
    curinfo.bVisible = false;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle,&curinfo);
    showProgress();
    return 0;
}