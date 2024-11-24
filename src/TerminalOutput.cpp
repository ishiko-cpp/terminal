/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/terminal/blob/main/LICENSE.txt
*/

#include "TerminalOutput.hpp"
#ifdef WIN32
#include <Windows.h>
#include <io.h>
#endif
#include <iostream>

namespace Ishiko
{
namespace Terminal
{

namespace
{

bool TerminalSupportsColor(FILE* file)
{
#ifdef WIN32
    HANDLE outputHandle = (HANDLE)_get_osfhandle(_fileno(file));
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
    if (TerminalSupportsColor(m_file))
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
