#include <gtest/gtest.h>
#include <iostream>
TEST(MyClassTest, BasicTest)
{
    EXPECT_EQ(42, 1) << "This is a test message";
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}