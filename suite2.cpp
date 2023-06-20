#include "suite2.hpp"

Suite2::Suite2(): Suites{"Suite2"}
{
    // Store tests from Test2 in Suites::test_container.
    std::cout<<"Adding Suite2 tests.\n";
    for(auto& test: tests.store_tests)
    {
        tests_container.emplace_back(std::make_shared<Tests>(test->name, test->test));
    }
}
