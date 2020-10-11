/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Terminal/blob/master/LICENSE.txt
*/

#include "TerminalOutput.h"
#ifdef WIN32
#include <Windows.h>
#endif
#include <iostream>

namespace Ishiko
{
namespace Terminal
{

namespace
{

bool TerminalSupportsColor()
{
#ifdef WIN32
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(outputHandle, &mode);
    return (mode & 0x4);
#else
    return true;
#endif
}

}

void TerminalOutput::write(const char* text)
{
    printf(text);
}

void TerminalOutput::write(const std::string& text)
{
    printf(text.c_str());
}

void TerminalOutput::write(const char* text, const Color& color)
{
    if (TerminalSupportsColor())
    {
        std::cout << (char)0x1B << "[38;2;" << (unsigned int)color.red << ";" << (unsigned int)color.green << ";" 
            << (unsigned int)color.blue << "m" << text << (char)0x1B << "[0m";
    }
    else
    {
        std::cout << text;
    }
}

void TerminalOutput::write(const std::string& text, const Color& color)
{
    write(text.c_str(), color);
}

}
}
