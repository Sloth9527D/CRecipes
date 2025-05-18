set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(include)

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(ut)

set(test_src main.cpp)
add_executable(RecipesTest ${test_src})
target_link_libraries(RecipesTest ut_feature gtest_main gmock_main)
add_test(NAME RecipesTest COMMAND RecipesTest)