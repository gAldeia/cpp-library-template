#include <LibHeaderOnlyTemplateCMake/LibHeaderOnlyTemplateCMake.h>

#include <gtest/gtest.h>

#include <cstdlib>
#include <cmath>
#include <iostream>

TEST(LibHeaderOnlyTemplateCMakeTests, DummyTest){
    std::cout << "Dummy in LibHeaderOnlyTemplateCMake test is working fine." << std::endl;

    const auto expected = 7-3;
    const auto actual   = 4;

    ASSERT_EQ(expected, actual);
}


TEST(LibHeaderOnlyTemplateCMakeTests, SumClassTest){
    std::cout << "Running test on the header-only library!" << std::endl;

    double tol = 1e-10;
    double op1 = 15.0;
    double op2 = 10.0;

    const auto actual = LibTemplateCMake::sum(op1, op2) - (op1 + op2);

    // we can stream messages to assertion macros in gtests
    ASSERT_FALSE(fabs(actual) > tol) << "[ERR] LibTemplateCMake::sum(" << op1 << "," << op2
                                    << ") is equal to " << actual
                                    << " instead of the expected " << op1 + op2 << std::endl;
}


TEST(LibHeaderOnlyTemplateCMakeTests, DiffClassTest){
    std::cout << "Running test on the header-only library!" << std::endl;

    double tol = 1e-10;
    double op1 = 15.0;
    double op2 = 10.0;

    const auto actual = LibTemplateCMake::sub(op1, op2) - (op1 - op2);

    // we can stream messages to assertion macros in gtests
    ASSERT_FALSE(fabs(actual) > tol) << "[ERR] LibTemplateCMake::sub(" << op1 << "," << op2
                                    << ") is equal to " << actual
                                    << " instead of the expected " << op1 - op2 << std::endl;
}