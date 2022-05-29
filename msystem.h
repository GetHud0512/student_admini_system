#pragma once

#include "include.h"

//系统类,负责提供程序与硬件的接口
class msystem
{
private://私有成员-------------------------------------------------------------------------------------------------------

    std::fstream file_i;                            //文件类
    std::ofstream file_o;                           //文件类
    std::vector<std::string> content;               //文件内容,每一个元素存储的是该文件类的每一一行的元素

    bool bad;                                       //类的状态

public://公有成员--------------------------------------------------------------------------------------------------------

    msystem();                                      //构造函数
    msystem(msystem& arg);                          //复制构造函数,这种情况理论上不可能,输出错误信息
    ~msystem();                                     //析构函数
    
    bool            is_bad();                       //返回类的状态
    bool            erase(std::string str);         //删除文件内容中指定字符串函数,成功删除返回true,无指定元素删除失败,返回false
    int             find(std::string str)const;     //寻找文件内容中指定元素函数,返回找到的第一个元素的下标,没有找到就返回-1
    unsigned int    size()const;                    //获取文件内容元素的行数(文件内容容器每行文件字符串作为一个元素)函数,返回文件内容的元素个数
    void            save();                         //保存修改后的文件内容函数
    void            Output(const char* str)const;   //输出字符串函数,参数:输出的字符串
    std::string     Input()const;                   //输入字符串函数,返回输入的字符串
    std::string     GetTime()const;                 //获取时间函数,返回表示当前时间的字符串
 
    void        operator <<(std::string str);       //重载<<运算符,参数:输入到文件尾部的字符串
    std::string operator [](unsigned int i);        //重载[]运算符,参数:访问文件内容的下标,返回表示文件内容对应下标的字符串
    
protected://保护成员-----------------------------------------------------------------------------------------------------
};
