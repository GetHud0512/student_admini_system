#pragma once

#include "include.h"

#define CHECK(TYPE) if(bad){"[system(check):program logic error]"; return TYPE;}
#define FILE_PATH "C:\\Users\\Public\\Documents\\datas.txt"


msystem::msystem()
{   
    file_i.open(FILE_PATH,std::fstream::in);

    if(!file_i.is_open())
    {
        file_i.close();
        Output("Data file opened failed.");
        Output("Trying to craeted a new data file.");
        file_o.open(FILE_PATH);

        if(file_o.is_open())
        {
            Output("New data file created successfully.");
            file_o.close();
            file_i.open(FILE_PATH,std::fstream::in);
        }
        else
        {
            Output("New data file created failed.");
            file_o.close();

            this->bad = true;

            return;
        }
    }

    this->bad = false;

    Output("Data file opened successfully.");

    std::string line;//文件一行的字符

    while(getline(file_i,line))
    {
        content.push_back(line);
    }

    file_o.open(FILE_PATH);
    Output("\
Set up already, system launched successfully.\n\
#########################\n\
#########################\n\
###ooooooooooooooooooo###\n\
###ooooooooooooooooooo###\n\
###ooo.............ooo###\n\
###ooo.............ooo###\n\
###ooo....     ....ooo###\n\
###ooo....     ....ooo###\n\
###ooo             ooo###\n\
###ooo             ooo###\n\
###                   ###\n\
###                   ###\n\
Student Admini System ----by progsrc\n\
Version: v1.1.0 alpha\n\
Welcome to Student Admini System!\n"
    );

    return;
}


msystem::msystem (msystem& arg):bad(true)
{
    CHECK();

    arg.bad = true;

    std::cout << "[system:program logic error]" << std::endl;
}


msystem::~msystem()
{
    file_o.close();
    file_o.open(FILE_PATH,std::ios::trunc);
    
    if(!file_o.is_open())
    {
        bad = true;
        Output("E:Unable to save data into data file.");

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
    CHECK();

    file_o.close();
    file_o.open(FILE_PATH,std::ios::trunc);
    
    if(!file_o.is_open())
    {
        bad = true;
        Output("E:Unable to save data into data file.");

        return;
    }
    
    for(int i = 0; i < size(); i++)
    {
        file_o << content[i] << std::endl;
    }

    return;
}


bool msystem::erase(std::string str)
{
    if(find(str) < 0)
    {
        Output("E:Unable to erase the element:the element was not found.");

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

    std::cout << '[' << GetTime() << ']' << str << std::endl;

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
        Output("E:Unable to add the element into data:existing element.");

        return;
    }

    content.push_back(str);

    return;
}
