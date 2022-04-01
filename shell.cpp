#pragma once

#include"include.h"

#define CHECK(TYPE) if(bad){std::cout << "[shell(check):program logic error]"; return TYPE;}

shell::shell(msystem& sys)
{
    systm = &sys;

    if(systm->is_bad())
    {
        bad = true;

        return;
    }

    bad = false;

    return;
}

shell::shell(shell& sh)
{
    std::cout << "[shell:program logic error]" << std::endl;

    return;
}

shell::~shell()
{
    CHECK();

    return;
}

bool shell::dcomand(std::string commad)const
{

    return false;
}

int shell::tcomand(std::string commad)const
{
    if(commad == "save")
        return comde::SAVE;
    else
        return comde::NONE;
}