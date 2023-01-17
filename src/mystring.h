#pragma once
#include <cstdlib>
#include <iostream>
using std::ostream;
using std::istream;
 
class Abstr {
  public:
    virtual void *my_memchr(void) = 0;
    virtual int my_memcmp(void) = 0;
    virtual  void *my_memcpy(void) = 0;
    virtual void *my_memmove(void) = 0;
    virtual char *my_strcat(void) = 0;
    virtual char *my_strncat(void) = 0;
    virtual char *my_strchr(void) = 0;
    virtual int my_strcmp(void) = 0;
    virtual int my_strncmp(void) = 0;
    virtual char *my_strcpy(void) = 0;
    virtual char *my_strncpy(void) = 0;
    virtual size_t my_strcspn(void) = 0;
    virtual size_t my_strlen(void) = 0;
    virtual char *my_strrchr(void) = 0;
    virtual const char *my_strpbrk(void) = 0;
    virtual size_t my_strspn(void) = 0;
    virtual const char *my_strstr(void) = 0;
    virtual char *my_strtok(void) = 0;
  };
 
class myString_h: public Abstr{
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
        size_t my_strspn(const char *str1, const char *str2);
        const char *my_strstr(const char *haystack, const char *needle);
        char *my_strtok(char *str, const char *delim);
};
 
class String{
    private:
        char* str;     
        int len;                 
        static int num_strings;  
        static const int CINLIM = 80;  
    public:
        String(); 
        String(const char * s);              
        String(const String &);  
        ~String();                
        int length() { return len; }
 
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int);
        const char & operator[](int) const;
        void stringlow();
        void stringup();
        static int HowMany();
 
        friend bool operator<(const String &, const String &);
        friend bool operator==(const String &, const String &);
        friend bool operator!=(const String &, const String &);
        friend bool operator>(const String &, const String &);
        friend String operator+(const String&, const String&);
 
        friend ostream & operator<<(ostream & os, const String &st2);
        friend istream & operator>>(istream & is, String & st);
 
        void append(int, char);
        void append(const String &);
        void append(const String &, size_t, size_t);
};
