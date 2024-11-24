/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/terminal/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TERMINAL_TERMINALOUTPUT_H_
#define _ISHIKO_CPP_TERMINAL_TERMINALOUTPUT_H_

#include <Ishiko/Types.hpp>
#include <string>
#include <cstdio>

namespace Ishiko
{
namespace Terminal
{

class TerminalOutput
{
public:
    TerminalOutput(FILE* file);

    void write(const char* text);
    void write(const std::string& text);
    void write(const char* text, const Color& color);
    void write(const std::string& text, const Color& color);

private:
    FILE* m_file;
};

}
}

#endif
