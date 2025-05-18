#include "gtest/gtest.h"
#include <cstring>

namespace {

struct Person
{
    int age;
    char name[20];
};

} // namespace

TEST(MemoryOperationTest, sizeof)
{
    int arr[10];
    EXPECT_EQ(sizeof(arr), 40); // sizeof返回对象内存所占的byte位数;
    EXPECT_EQ(sizeof(Person), 24);
}

TEST(MemoryOperationTest, strlen)
{
    const char *ptr = "Hello";
    EXPECT_EQ(sizeof(ptr), sizeof(nullptr));
    EXPECT_EQ(strlen(ptr), 5); // strlen返回指针所之字符串的长度
}

/*memcpy两片内存逐字节进行拷贝,主要注意事项
1. 内存大小一致,避免溢出
2. 注意类型安全,大小一样也能执行,但需注意其行为是否符合预期
3. 仅POD类型的结构体时可以用此复制,建议仅网络传输时考虑用
 */
TEST(MemoryOperationTest, CopyMemory)
{
    char src[] = "Hello, World!";
    char dest[20];
    EXPECT_EQ(sizeof(src), 14);
    EXPECT_EQ(strlen(src), 13); // strlenbuto不统计0;
    EXPECT_EQ(sizeof(dest), 20);
    EXPECT_NE(strlen(dest), 20); // strlen只用于字符串(以0结尾的)
    memcpy(dest, src, sizeof(src));
    EXPECT_STREQ(src, dest);
    EXPECT_EQ(memcmp(src, dest, sizeof(src)), 0);

    // 测试零字节复制
    char src1[] = "No copy";
    char dest1[10] = "original";

    memcpy(dest1, src1, 0);
    EXPECT_STREQ(dest1, "original");

    // 测试相同地址
    int data = 42;
    memcpy(&data, &data, sizeof(data));
    EXPECT_EQ(data, 42);
}

TEST(MemoryOperationTest, DeathCopy)
{
    char buffer[10];

    // 测试空指针（预期崩溃）
    EXPECT_DEATH(memcpy(nullptr, buffer, 5), ".*");
    EXPECT_DEATH(memcpy(buffer, nullptr, 5), ".*");
    EXPECT_DEATH(memcpy(nullptr, nullptr, 5), ".*") << "Some platforms may not crash";

    // 测试内存重叠（某些平台可能不崩溃）
    char str[] = "ABCDEF";
    EXPECT_DEATH(memcpy(str + 1, str, 4), ".*") << "Some platforms may not crash";
}