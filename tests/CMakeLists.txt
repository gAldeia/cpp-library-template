include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE testsSrc "*.cpp")
message(STATUS "testsSrc: '${testsSrc}")
add_executable(tests ${testsSrc})

#Linking the libraries with gtest
target_link_libraries(tests 
    LibTemplateCMake::LibTemplateCMake
    LibTemplateCMake::LibTemplateCMakeHeaderOnly
    GTest::gtest_main
  )
  
# Google tests
include(GoogleTest)
gtest_discover_tests(tests)