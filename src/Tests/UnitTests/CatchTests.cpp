/*
 * prjsv 2015, 2016
 * 2014
 * Marco Antognini
 */

// Define the entry point for tests with Catch frameworks.

#include <Application.hpp>

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


int main(int argc, char const** argv)
{
    INIT_DEFAULT_APP(argc, argv);
    return Catch::Session().run();
}
