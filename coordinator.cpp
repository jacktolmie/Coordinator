#include "coordinator.hpp"

Coordinator::Coordinator()
{
   {
        /* A group of Tests and Suites. */
        Test_List suites_tests;

        std::cout<<"Starting to fill tree.\n";
        Coordinator::fill_tree(root->name, suites_tests.main_suite.suites_container, root->suite);
        Coordinator::fill_tree(suites_tests.main_suite.tests_container, root);
    }

std::cout<<"Ending fill_tree\n";
    //    Coordinator::print_tree(root_node);
}
