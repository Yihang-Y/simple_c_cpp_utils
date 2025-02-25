#include "my_str_utils.h"
#include "gtest/gtest.h"
#include <cstring>

TEST(MyStrUtils, MyStrcat) {
    char dst[100] = "Hello, ";
    char src[] = "world!";
    char* res = my_strcat(dst, src);
    ASSERT_STREQ(res, "Hello, world!");
}

TEST(MyStrUtils, MyStrcmp1) {
    const char* str1 = "Hello, world!";
    const char* str2 = "Hello, world!";
    int res = my_strcmp(str1, str2);
    ASSERT_EQ(res, 0);
}

TEST(MyStrUtils, MyStrcmp2) {
    const char* str1 = "Hello, world!";
    const char* str2 = "Hello, world";
    int res = my_strcmp(str1, str2);
    ASSERT_EQ(res, 33);
}

TEST(MyStrUtils, MyStrcmp3) {
    const char* str1 = "Hello, world";
    const char* str2 = "Hello, world!";
    int res = my_strcmp(str1, str2);
    ASSERT_EQ(res, -33);
}

TEST(MyStrUtils, MyStrcpy) {
    char dst[100] = "Hello, ";
    char src[] = "world!";
    char* res = my_strcpy(dst, src);
    ASSERT_STREQ(res, "world!");
}


TEST(MyStrUtils, MyStrcpy2) {
    char dst[100] = "Hello, world!";
    char* res = my_strcpy(dst, dst);
    ASSERT_STREQ(res, "Hello, world!");
}

// Test when dst >= src and dst < src + size
TEST(MyStrUtils, MyStrcpy3) {
    char dst[100] = "Hello, world!";
    char* res = my_strcpy(dst + 7, dst);
    ASSERT_STREQ(res, strcpy(dst + 7, dst));
}

TEST(MyStrUtils, MyStrSplit) {
    char str[] = "Hello, world! ";
    char** res = my_strsplit(str, ' ');
    ASSERT_STREQ(res[0], "Hello,");
    ASSERT_STREQ(res[1], "world!");
    ASSERT_STREQ(res[2], "");
    ASSERT_EQ(res[3], nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}