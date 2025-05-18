add_subdirectory(googletest EXCLUDE_FROM_ALL)

set(test_src
    main.cpp
)

add_executable(RecipesTest ${test_src})
message("${CMAKE_SOURCE_DIR}/test/googletest/googlemock/include")
message("${CMAKE_SOURCE_DIR}/test/googletest/googletest/include")
target_include_directories(RecipesTest
  PUBLIC
    ${CMAKE_SOURCE_DIR}/test/googletest/googlemock/include
    ${CMAKE_SOURCE_DIR}/test/googletest/googletest/include
)

target_link_libraries(RecipesTest gtest_main gmock_main)

add_test(NAME RecipesTest COMMAND RecipesTest)