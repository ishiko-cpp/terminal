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

TerminalOutput::TerminalOutput(FILE* file)
    : m_file(file)
{
}

void TerminalOutput::write(const char* text)
{
    fprintf(m_file, text);
}

void TerminalOutput::write(const std::string& text)
{
    fprintf(m_file, text.c_str());
}

void TerminalOutput::write(const char* text, const Color& color)
{
    if (TerminalSupportsColor())
    {
        fprintf(m_file, "\x1B[38;2;%s;%s;%sm%s\x1B[0m", std::to_string(color.red).c_str(),
            std::to_string(color.green).c_str(), std::to_string(color.blue).c_str(), text);
    }
    else
    {
        fprintf(m_file, text);
    }
}

void TerminalOutput::write(const std::string& text, const Color& color)
{
    write(text.c_str(), color);
}

}
}
