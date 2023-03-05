#include <gtest/gtest.h>

//GoogleTest framework in the common case requires RUN_ALL_TESTS macro in main
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}