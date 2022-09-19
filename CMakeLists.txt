project(Google_tests)
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(test.out test.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(test.out ${CMAKE_PROJECT_NAME}_lib)

target_link_libraries(test.out gtest gtest_main)