/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/terminal/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TERMINAL_TESTS_TERMINALOUTPUTTESTS_H_
#define _ISHIKO_CPP_TERMINAL_TESTS_TERMINALOUTPUTTESTS_H_

#include <Ishiko/TestFramework/Core.hpp>

class TerminalOutputTests : public Ishiko::TestSequence
{
public:
    TerminalOutputTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructionTest1(Ishiko::Test& test);
    static void WriteTest1(Ishiko::FileComparisonTest& test);
    static void WriteTest2(Ishiko::FileComparisonTest& test);
    static void WriteTest3(Ishiko::FileComparisonTest& test);
    static void WriteTest4(Ishiko::FileComparisonTest& test);
};

#endif
