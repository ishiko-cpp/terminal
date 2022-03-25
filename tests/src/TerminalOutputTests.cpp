/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/terminal/blob/master/LICENSE.txt
*/

#include "TerminalOutputTests.h"
#include "Ishiko/Terminal/TerminalOutput.h"
#include <Ishiko/Process/CurrentProcess.h>
#include <boost/filesystem/operations.hpp>

using namespace Ishiko;
using namespace Ishiko::Terminal;

TerminalOutputTests::TerminalOutputTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TerminalOutput tests", context)
{
    append<HeapAllocationErrorsTest>("Construction test 1", ConstructionTest1);
    append<FileComparisonTest>("write test 1", WriteTest1);
    append<FileComparisonTest>("write test 2", WriteTest2);
    append<FileComparisonTest>("write test 3", WriteTest3);
    append<FileComparisonTest>("write test 4", WriteTest4);
}

void TerminalOutputTests::ConstructionTest1(Test& test)
{
    TerminalOutput output(stdout);

    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() / "TerminalOutputTests_WriteTest1.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest1.txt");

    Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    output.write("text");

    Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest2(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() / "TerminalOutputTests_WriteTest2.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest2.txt");

    Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    std::string text = "text";
    output.write(text);

    Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest3(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() / "TerminalOutputTests_WriteTest3.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest3.txt");

    Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    output.write("text", Ishiko::Color::eRed);

    Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_PASS();
}

void TerminalOutputTests::WriteTest4(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.context().getTestOutputDirectory() / "TerminalOutputTests_WriteTest4.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest4.txt");

    Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    std::string text = "text";
    output.write(text, Ishiko::Color::eRed);

    Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHIKO_TEST_PASS();
}
