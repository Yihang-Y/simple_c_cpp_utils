#pragma once
#include <cassert>
#include <cstring>

/**
 * @brief cancatenate two strings.
 * 
 * @param dst 
 * @param src 
 * @return char* 
 */
char* my_strcat(char* dst, char* src) {
    char* res = dst;
    // NOTE: dst++ will return the value of dst before incrementing, while ++dst will return the value of dst after incrementing.
    // dst++ (old value), ++dst (new value)
    while (*dst != '\0') dst++;
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return res;
}

/**
 * @brief compare two strings and return 0 if they are equal, a negative value if str1 is less than str2, and a positive value if str1 is greater than str2.
 * 
 * @param str1 
 * @param str2 
 * @return int 
 */
int my_strcmp(const char* str1, const char* str2) {
    while(*str1 != '\0' && *str2 != '\0' ){
        if( *str1 == *str2 ){
            str1++; 
            str2++;
        }else{
            return *str1 - *str2;
        }
    }
    return *str1 - *str2;
}

/**
 * @brief 
 * 
 * @param dst 
 * @param src 
 * @return char* 
 */
char* my_strcpy(char* dst, char* src) {
    assert((dst != NULL && src != NULL));
    char* res = dst;
    int size = strlen(src) + 1;

    if(dst >= src && dst < src + size) {
        char* d = dst + size;
        char* s = src + size;
        while(size--) {
            *d = *s;
            d--;
            s--;
        }
    }else {
        while(size--){
            *dst++ = *src++;
        }
    }
    return res;
}


char** my_strsplit(const char* src, char delim) {
    assert(src != NULL);
    size_t num_words = 1;
    size_t ptrsSize = 0;
    size_t sLen = strlen(src);
    char** data = NULL;
    char** ptrs = NULL;
    char* _s = NULL;

    // 计算分割的子字符串个数
    for (size_t i = 0; src[i] != '\0'; ++i) {
        if (src[i] == delim) {
            num_words++;
        }
    }

    ptrsSize = sizeof(char*) * (num_words + 1);

    // 分配足够的内存：指针数组 + 复制的字符串数据
    data = (char**)malloc(ptrsSize + sLen + 1);
    if (!data) {
        return NULL; // 内存分配失败
    }

    ptrs = data;
    _s = strcpy(((char*)data) + ptrsSize, src);
    *ptrs = _s; // 第一个字符串

    // 替换 `delim` 为 `\0` 并保存分割字符串的指针
    if (num_words > 1) {
        while (*_s) {
            if (*_s == delim) {
                *_s = '\0';
                *++ptrs = _s + 1;
            }
            ++_s;
        }
    }
    *++ptrs = NULL; // 结束符

    return data;
}