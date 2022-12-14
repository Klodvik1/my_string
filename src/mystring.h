#include <cstdlib>

class String {
    public:
        void *my_memchr(const void *str, int c, size_t n);
        int my_memcmp(const void *str1, const void *str2, size_t n);
        void *my_memcpy(void *dest, const void *src, size_t n);
        void *my_memmove(void *dest, const void *src, size_t n);
        char *my_strcat(char *dest, const char *src);
        char *my_strncat(char *dest, const char *src, size_t n);
        char *my_strchr(const char *str, int c);
        int my_strcmp(const char *str1, const char *str2);
        int my_strncmp(const char *str1, const char *str2, size_t n);
        char *my_strcpy(char *dest, const char *src);
        char *my_strncpy(char *dest, const char *src, size_t n);
        size_t my_strcspn(const char *str1, const char *str2);
        size_t my_strlen(const char *str);
        char *my_strrchr(const char *str, int c);
        const char *my_strpbrk(const char *str1, const char *str2);
        size_t my_strspn(const char *str1, const char *str2);
        const char *my_strstr(const char *haystack, const char *needle);
        char *my_strtok(char *str, const char *delim);
};