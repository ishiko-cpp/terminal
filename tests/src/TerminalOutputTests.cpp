/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/terminal/blob/master/LICENSE.txt
*/

#include "TerminalOutputTests.h"
#include "Ishiko/Terminal/TerminalOutput.h"
#include <Ishiko/Process.hpp>

using namespace Ishiko;
using namespace Ishiko::Terminal;

TerminalOutputTests::TerminalOutputTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TerminalOutput tests", context)
{
    append<HeapAllocationErrorsTest>("Construction test 1", ConstructionTest1);
    append<HeapAllocationErrorsTest>("write test 1", WriteTest1);
    append<HeapAllocationErrorsTest>("write test 2", WriteTest2);
    append<HeapAllocationErrorsTest>("write test 3", WriteTest3);
    append<HeapAllocationErrorsTest>("write test 4", WriteTest4);
}

void TerminalOutputTests::ConstructionTest1(Test& test)
{
    TerminalOutput output(stdout);

    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest1(Test& test)
{
    const char* basename{"TerminalOutputTests_WriteTest1.txt"};
    
    CurrentProcess::RedirectStandardOutputToFile(test.context().getOutputPath(basename).string());

    TerminalOutput output(stdout);
    output.write("text");

    CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(basename);
    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest2(Test& test)
{
    const char* basename{"TerminalOutputTests_WriteTest2.txt"};
    
    CurrentProcess::RedirectStandardOutputToFile(test.context().getOutputPath(basename).string());

    TerminalOutput output(stdout);
    std::string text = "text";
    output.write(text);

    CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(basename);
    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest3(Test& test)
{
    const char* basename{"TerminalOutputTests_WriteTest3.txt"};

    CurrentProcess::RedirectStandardOutputToFile(test.context().getOutputPath(basename).string());

    TerminalOutput output(stdout);
    output.write("text", Ishiko::Color::eRed);

    CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(basename);
    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest4(Test& test)
{
    const char* basename{"TerminalOutputTests_WriteTest4.txt"};
    
    CurrentProcess::RedirectStandardOutputToFile(test.context().getOutputPath(basename).string());

    TerminalOutput output(stdout);
    std::string text = "text";
    output.write(text, Color::eRed);

    CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(basename);
    ISHIKO_TEST_PASS();
}
