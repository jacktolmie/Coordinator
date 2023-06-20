#include "suite1.hpp"

Suite1::Suite1():Suites{"Suite1"}
{
    // Store tests from Test1 in Suites::test_container.
    std::cout<<"Adding Suite1 tests.\n";
    suites_container.emplace_back(std::make_shared<Suites>(suite2));
    suites_container.emplace_back(std::make_shared<Suites>(suite2));
    for(auto& test: tests.store_tests)
    {
        tests_container.emplace_back(std::make_shared<Tests>(test->name, test->test));
    }
}
