/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/terminal/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TERMINAL_TESTS_TERMINALOUTPUTTESTS_H_
#define _ISHIKO_TERMINAL_TESTS_TERMINALOUTPUTTESTS_H_

#include <Ishiko/Tests/Core.h>

class TerminalOutputTests : public Ishiko::Tests::TestSequence
{
public:
    TerminalOutputTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructionTest1(Ishiko::Tests::Test& test);
    static void WriteTest1(Ishiko::Tests::FileComparisonTest& test);
    static void WriteTest2(Ishiko::Tests::FileComparisonTest& test);
    static void WriteTest3(Ishiko::Tests::FileComparisonTest& test);
    static void WriteTest4(Ishiko::Tests::FileComparisonTest& test);
};

#endif
