#pragma once

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