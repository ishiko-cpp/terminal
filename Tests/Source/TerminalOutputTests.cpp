/*
    Copyright (c) 2020 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "TerminalOutputTests.h"
#include "Ishiko/Terminal/TerminalOutput.h"
#include <Ishiko/Process/CurrentProcess.h>
#include <boost/filesystem/operations.hpp>

using namespace Ishiko::Terminal;
using namespace Ishiko::Tests;

TerminalOutputTests::TerminalOutputTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TerminalOutput tests", environment)
{
    append<HeapAllocationErrorsTest>("Construction test 1", ConstructionTest1);
    append<FileComparisonTest>("write test 1", WriteTest1);
}

void TerminalOutputTests::ConstructionTest1(Test& test)
{
    TerminalOutput output;

    ISHTF_PASS();
}

void TerminalOutputTests::WriteTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "TerminalOutputTests_WriteTest1.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest1.txt");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output;
    output.write("text");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHTF_PASS();
}
