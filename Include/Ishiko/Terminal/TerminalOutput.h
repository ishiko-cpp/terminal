/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Terminal/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TERMINAL_TERMINALOUTPUT_H_
#define _ISHIKO_TERMINAL_TERMINALOUTPUT_H_

#include <Ishiko/Types/Color.h>
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

#include "linkoptions.h"

#endif
