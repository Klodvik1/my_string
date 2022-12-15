#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>

class myString {
    public:
        void *my_memchr(const void *str, int c, size_t n);
        int my_memcmp(const void *str1, const void *str2, size_t n);
        void *my_memcpy(void *dest, const void *src, size_t n);
        void *my_memmove(void *dest, const void *src, size_t n);
        size_t my_strlen(const char *str);  // Длина строки
        char *my_strcat(char *dest, const char *src); // Добавление в строку 
        char *my_strncat(char *dest, const char *src, size_t n); // Добавление в строку n символов
        char *my_strchr(const char *str, int c); // Поиск первого вхождения символа 
        char *my_strrchr(const char *str, int c); // Поиск последнего вхождения символа
        size_t my_strcspn(const char *str1, const char *str2); //  Поиск любого символа из строки str2 и вывод его позиции
        const char *my_strstr(const char *haystack, const char *needle); //  Поиск первого вхождения строки
        int my_strcmp(const char *str1, const char *str2); // Сравнение строк  
        int my_strncmp(const char *str1, const char *str2, size_t n); // Сравнение строк по n символов
        char *my_strcpy(char *dest, const char *src); // Копирование в строку 
        char *my_strncpy(char *dest, const char *src, size_t n); // Копирование n символов строку в строку 
        char *my_strtok(char *str, const char *delim);  // Разделение строки на лексемы 
};

class path: public myString {
    protected:
        int number_string = 1;
        char* path_file = NULL;
        static inline int number_paths = 0;
    public:
        void input_path(char*);
        void output_path();
        void delete_path();
};

class work_string: public path {
    private:
        char str[10000];
    public:
        work_string(char* str) {
            input_path(str);
        }
        work_string() {
            input_path(NULL);
        }
        void output_file();
        void output_file(int);
        void input_string(int);
        void cat_string(int, int);
};