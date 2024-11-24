// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TERMINAL_TERMINALOUTPUT_HPP
#define GUARD_ISHIKO_CPP_TERMINAL_TERMINALOUTPUT_HPP

#include <Ishiko/Types.hpp>
#include <string>
#include <cstdio>

namespace Ishiko
{
    class TerminalOutput
    {
    public:
        TerminalOutput(FILE* file);

        void write(const char* text);
        void write(const std::string& text);
        void write(const char* text, const RGBAColor& color);
        void write(const std::string& text, const RGBAColor& color);

    private:
        FILE* m_file;
    };
}

#endif
