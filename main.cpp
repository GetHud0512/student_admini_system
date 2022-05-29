#define _SCL_SECURE_NO_WARNINGS
#include "include.h"
#include "msystem.h"
#include "shell.h"
#include "user.h"

int main()
{
    msystem omsystem;   //程序系统对象

    while (true)
    {
        omsystem.Output("");

        system("pause");
    }

    system("pause");

    return 0;
}
