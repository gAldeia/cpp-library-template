#include <LibTemplateCMake/LibTemplateCMake.h>

#include <gtest/gtest.h>

#include <cstdlib>
#include <cmath>
#include <iostream>

TEST(LibTemplateCMakeTests, DummyTest){
    std::cout << "Dummy test in LibTemplateCMake is working fine." << std::endl;

    const auto expected = 7+3;
    const auto actual   = 10;

    ASSERT_EQ(expected, actual);
}

TEST(LibTemplateCMakeTests, SumClassTest){
    std::cout << "Running test on the exported library!" << std::endl;

    LibTemplateCMake::summationClass sumClass;

    double tol = 1e-10;
    double op1 = 15.0;
    double op2 = 10.0;

    const auto actual = sumClass.doSomething(op1, op2) - (op1 + op2);

    // we can stream messages to assertion macros in gtests
    ASSERT_FALSE(fabs(actual) > tol) << "[ERR] sumClass.doSomething(" << op1 << "," << op2
                                    << ") is equal to " << actual
                                    << " instead of the expected " << op1 + op2 << std::endl;
}


TEST(LibTemplateCMakeTests, DiffClassTest){
    std::cout << "Running test on the exported library!" << std::endl;

    LibTemplateCMake::differenceClass diffClass;

    double tol = 1e-10;
    double op1 = 15.0;
    double op2 = 10.0;

    const auto actual = diffClass.doSomething(op1, op2) - (op1 - op2);

    // we can stream messages to assertion macros in gtests
    ASSERT_FALSE(fabs(actual) > tol) << "[ERR] diffClass.doSomething(" << op1 << "," << op2
                                    << ") is equal to " << actual
                                    << " instead of the expected " << op1 - op2 << std::endl;
}