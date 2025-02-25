#include "my_str_utils.h"
#include "gtest/gtest.h"


TEST(MyStrUtils, MyStrcat) {
    char dst[100] = "Hello, ";
    char src[] = "world!";
    char* res = my_strcat(dst, src);
    ASSERT_STREQ(res, "Hello, world!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}