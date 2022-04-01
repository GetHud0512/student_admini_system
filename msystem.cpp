#pragma once

#include "include.h"

#define CHECK(TYPE) if(bad){std::cout << "[system(check):program logic error]"; return TYPE;}

msystem::msystem()
{   
    file_i.open("C:\\Users\\Default\\Documents\\datas.txt",std::fstream::in);

    if(!file_i.is_open())
    {
        file_i.close();
        std::cout << "Data file open failed." << std::endl;
        std::cout << "Trying to craet a new data file." << std::endl;

        file_o.open("C:\\Users\\Default\\Documents\\datas.txt");
        if(file_o.is_open())
        {
            std::cout << "New data file creat successfully." << std::endl;
            file_o.close();
            file_i.open("C:\\Users\\Default\\Documents\\datas.txt",std::fstream::in);
        }
        else
        {
            std::cout << "New data file creat failed." << std::endl;
            file_o.close();
            bad = true;
            return;
        }
    }

    bad = false;
    std::cout << "Data file open successfully." << std::endl;

    std::string line;//文件一行的字符

    while(getline(file_i,line))
    {
        content.push_back(line);
    }
    file_o.open("C:\\Users\\Default\\Documents\\datas.txt");

    return;
}

msystem::msystem(msystem& arg)
{
    CHECK();

    std::cout << "[system:program logic error]" << std::endl;
}

msystem::~msystem()
{
    CHECK();

    file_o.close();
    file_o.open("C:\\Users\\Default\\Documents\\datas.txt",std::ios::trunc);
    
    if(!file_o.is_open())
    {
        bad = true;
        std::cout << "E:Unable to save data into data file." << std::endl;
        return;
    }

    for(int i = 0; i < content.size(); i++)
    {
        file_o << content[i] << std::endl;
    }

    file_i.close();
    file_o.close();

    return;
}

bool msystem::is_bad()
{
    return bad;
}

void msystem::save()
{
    file_o.close();
    file_o.open("C:\\Users\\Default\\Documents\\datas.txt",std::ios::trunc);
    
    if(!file_o.is_open())
    {
        bad = true;
        std::cout << "E:Unable to save data into data file." << std::endl;
        return;
    }
    
    for(int i = 0; i < size(); i++)
    {
        file_o << content[i] << std::endl;
    }
}

bool msystem::erase(std::string str)
{
    if(find(str) < 0)
    {
        std::cout << "E:Unable to erase the element:the element was not found." << std::endl;

        return false;
    }
    content.erase(content.begin() + find(str));
    return true;
}

int msystem::find(std::string str)const
{
    for(int i = 0; i < size(); i++)
    {
        if(content[i] == str)
        {
            return i;
        }
    }

    return -1;
}

unsigned int msystem::size()const
{
    CHECK(0);

    return content.size();
}

void msystem::Output(const char* str)const
{
    CHECK();

    std::cout << str << std::endl;

    return;
}

std::string msystem::Input()const
{
    CHECK("[program logic error]");

    std::string str;
    getline(std::cin, str);
    return str;
}

std::string msystem::GetTime()const 
{
    CHECK("[program logic error]");
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

std::string msystem::operator[](unsigned int i)
{
    CHECK("[program logic error]");

    return content[i];
}

void msystem::operator<<(std::string str)
{
    CHECK();
    if(std::count(content.begin(),content.end(),str))
    {
        std::cout << "E:Unable to add the element into data:existing element." << std::endl;

        return;
    }
    content.push_back(str);

    return;
}