// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "TerminalOutputTests.h"
#include "Ishiko/Terminal/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        Ishiko::TestHarness::CommandLineSpecification command_line_spec;
        Ishiko::Configuration configuration = command_line_spec.createDefaultConfiguration();
        configuration.set("context.output", "../../output");
        configuration.set("context.reference", "../../reference");
        Ishiko::CommandLineParser::parse(command_line_spec, argc, argv, configuration);

        TestHarness the_test_harness("IshikoTerminal Library Tests", configuration);

        TestSequence& the_tests = the_test_harness.tests();
        the_tests.append<TerminalOutputTests>();

        return the_test_harness.run();
    }
    catch (const std::exception& e)
    {
        return Ishiko::TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return Ishiko::TestApplicationReturnCode::exception;
    }
}
