#pragma once

#include "include.h"

//交互环境类
class shell
{
private://私有成员-------------------------------------------------------------------------------------------------------

    enum comde                              //命令识别码
    {
        WRG,                                //错误的命令
        SAVE,                               //保存数据命令
        LOGIN,                              //登录
        LOGOUT,                             //
        ADDUSER,                            //
        DELUSER,                            //
    };
    
    enum permion                            //权限级别
    {
        STU,                                //学生
        TCH,                                //教师
        ADM                                 //管理
    };

    std::string command;                    //存储输入的命令
    bool bad;                               //类的状态
    msystem* systm;                         //系统类的指针

    int tcomand(std::string commad)const;   //解析命令,将命令转换为命令识别码

public://公有成员--------------------------------------------------------------------------------------------------------

    shell(msystem& sys);                    //构造函数,参数:系统类的引用
    shell(shell& sh);                       //复制构造函数,这种情况理论上不可能出现,输出错误信息
    ~shell();                               //析构函数

    bool is_bad()const;                     //返回类的状态
    bool dcomand(std::string commad)const;  //执行命令函数,执行成功返回true,失败返回false

protected://保护成员-----------------------------------------------------------------------------------------------------
};
