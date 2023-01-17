#include "mystring.h"
 
void *myString_h::my_memchr(const void *str, int c, size_t n) {
  char *ptr = (char *)str;
  void *res = NULL;
 
  for (size_t i = 0; (i < n) && ptr; i++) {
    if (*ptr == (char)c) {
      res = ptr;
      break;
    }
 
    ptr++;
  }
 
  return res;
}
 
int myString_h::my_memcmp(const void *str1, const void *str2, size_t n = -1) {
  char *ptr1 = (char *)str1;
  char *ptr2 = (char *)str2;
  int cmp = 0;
 
  if (n) {
    while (*(char *)ptr1 == *(char *)ptr2 && --n) {
      ptr1 = (char *)ptr1 + 1;
      ptr2 = (char *)ptr2 + 1;
    }
    cmp = (*((unsigned char *)ptr1) - *((unsigned char *)ptr2));
  } else {
    while (*(char *)ptr1 == *(char *)ptr2) {
      ptr1 = (char *)ptr1 + 1;
      ptr2 = (char *)ptr2 + 1;
    }
    cmp = (*((unsigned char *)ptr1) - *((unsigned char *)ptr2));
  }
 
  return cmp;
}
 
void *myString_h::my_memcpy(void *dest, const void *src, size_t n) {
  char *cdest = (char *)dest;
  const char *csrc = (char *)src;
 
  for (size_t i = 0; i < n; ++i) {
    *cdest++ = *csrc++;
  }
 
  return dest;
}
 
void *myString_h::my_memmove(void *dest, const void *src, size_t n) {
  void *ret = dest;
 
  if (dest <= src || (char *)dest >= ((char *)src + n)) {
    while (n--) {
      *(char *)dest = *(char *)src;
      dest = (char *)dest + 1;
      src = (char *)src + 1;
    }
  } else {
    dest = (char *)dest + n - 1;
    src = (char *)src + n - 1;
    while (n--) {
      *(char *)dest = *(char *)src;
      dest = (char *)dest - 1;
      src = (char *)src - 1;
    }
  }
 
  return ret;
}
 
char *myString_h::my_strcat(char *dest, const char *src) {
  char *ptr = dest;
 
  while (*dest != '\0') {
    dest++;
  }
 
  while (*src != '\0') {
    *dest++ = *src++;
  }
 
  *dest = '\0';
 
  return ptr;
}
 
char *myString_h::my_strncat(char *dest, const char *src, size_t n) {
  char *ptr = dest;
 
  while (*dest != '\0') {
    dest++;
  }
 
  while (n > 0) {
    *dest++ = *src++;
    n--;
  }
 
  *dest = '\0';
 
  return ptr;
}
 
char *myString_h::my_strchr(const char *str, int c) {
  char *ptr = (char *)str;
 
  for (; (*ptr != (unsigned char)c) && (*ptr != '\0'); ptr++) {
  }
  if (*ptr == '\0') {
    ptr = NULL;
  }
 
  return ptr;
}
 
int myString_h::my_strcmp(const char *str1, const char *str2) {
  int res = 0;
 
  if (str1 && str2) {
    int i = 0;
 
    while (str1[i] && str1[i] == str2[i]) {
      i++;
    }
 
    res = str1[i] - str2[i];
  }
 
  return res;
}
 
int myString_h::my_strncmp(const char *str1, const char *str2, size_t n) {
  int res = 0;
 
  if (str1 && str2 && n > 0) {
    for (size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        res = str1[i] - str2[i];
        break;
      }
    }
  }
 
  return res;
}
 
char *myString_h::my_strcpy(char *dest, const char *src) {
  char *ptr = dest;
 
  while (*src != '\0') {
    *dest++ = *src++;
  }
 
  *dest = '\0';
 
  return ptr;
}
 
char *myString_h::my_strncpy(char *dest, const char *src, size_t n) {
  char *ptr = dest;
 
  while (*src && n-- && (dest != NULL)) {
    *dest++ = *src++;
  }
 
  *dest = '\0';
 
  return ptr;
}
 
size_t myString_h::my_strcspn(const char *str1, const char *str2) {
  size_t result = 0;
  bool flag = false;
 
  for (; *str1; result++, str1++) {
    for (const char *dest = str2; *dest; dest++) {
      if (*str1 == *dest) {
        flag = true;
        break;
      }
    }
    if (flag == true) {
      break;
    }
  }
 
  return result;
}
 
size_t myString_h::my_strlen(const char *str) {
  size_t count = 0;
  if (str != NULL) {
    while (*str != '\0') {
      str++;
      count++;
    }
  } else {
    count = -1;
  }
 
  return count;
}
 
char *myString_h::my_strrchr(const char *str, int c) {
  char *ptr = (char *)str;
 
  for (; *ptr != '\0'; ptr++) {
  }
  size_t i;
  for (i = my_strlen(str) + 1; (*ptr != (unsigned char)c) && (i > 0);
       i--, ptr--) {
  }
  if (i == 0) {
    ptr = NULL;
  }
 
  return ptr;
}
 
size_t myString_h::my_strspn(const char *str1, const char *str2) {
  size_t i;
  bool flag = false;
 
  for (i = 0; str1[i] != '\0'; i++) {
    for (size_t j = 0; str2[j] != str1[i]; j++) {
      if (str2[j] == '\0') {
        flag = true;
        break;
      }
    }
    if (flag == true) {
      break;
    }
  }
 
  return i;
}
 
const char *myString_h::my_strstr(const char *haystack, const char *needle) {
  char *hst = (char *)haystack;
  char *ndl = (char *)needle;
  char *res = NULL;
 
  if (*ndl == '\0') {
    res = hst;
  }
 
  for (size_t i = 0; i < my_strlen(hst); i++) {
    if (hst[i] == *ndl) {
      char *tmp = &hst[i];
      int tmp_res = my_strncmp(tmp, ndl, my_strlen(ndl));
      if (tmp_res == 0) {
        res = &hst[i];
        break;
      }
    }
  }
 
  return res;
}
 
char *myString_h::my_strtok(char *str, const char *delim) {
  static char *s = NULL;
  char *ret = NULL;
 
  if (str != NULL) {
    s = str;
  }
 
  if (s != NULL && my_strlen(s)) {
    const size_t dlen = my_strlen(delim);
    while (*s && my_memchr(delim, *s, dlen) != NULL) {
      ++s;
    }
    if (*s) {
      ret = s;
      while (*s) {
        if (my_memchr(delim, *s, dlen) != NULL) {
          break;
        } else {
          ++s;
        }
      }
      if (*s) {
        s[0] = 0;
        ++s;
      }
    }
  }
 
  return ret;
}
 
//
 
int String::num_strings = 0;
myString_h *strin;
 
int String::HowMany() { return num_strings; }
 
String::String() : String("") {}
 
String::String(const char *s) : len(strin->my_strlen(s)) {
  str = new char[len + 1];
  strin->my_strcpy(str, s);
  num_strings++;
}
 
String::String(const String &st) : len(st.len) {
  num_strings++;
  str = new char[len + 1];
  strin->my_strcpy(str, st.str);
}
 
String::~String() {
  --num_strings;
  delete[] str;
}
 
String &String::operator=(const String &st) {
  if (this == &st) return *this;
  delete[] str;
  len = st.len;
  str = new char[len + 1];
  strin->my_strcpy(str, st.str);
  return *this;
}
 
String &String::operator=(const char *s) {
  delete[] str;
  len = strin->my_strlen(s);
  str = new char[len + 1];
  strin->my_strcpy(str, s);
  return *this;
}
 
void String::stringlow() {
  for (int j = 0; j < len; ++j) str[j] = (char)tolower(str[j]);
}
 
void String::stringup() {
  for (int j = 0; j < len; ++j) str[j] = (char)toupper(str[j]);
}
 
char &String::operator[](int i) { return str[i]; }
 
const char &String::operator[](int i) const { return str[i]; }
 
bool operator<(const String &st1, const String &st2) {
  return (strin->my_memcmp(st1.str, st2.str) < 0);
}
 
bool operator==(const String &st1, const String &st2) {
  return (strin->my_memcmp(st1.str, st2.str) == 0);
}
 
bool operator!=(const String &st1, const String &st2) {
  return (strin->my_memcmp(st1.str, st2.str) != 0);
}
 
bool operator>(const String &st1, const String &st2) { return st2 < st1; }
 
ostream &operator<<(ostream &os, const String &st) {
  os << st.str;
  return os;
}
 
String operator+(const String &st1, const String &st2) {
  String _temp;
  delete[] _temp.str;
  _temp.len = st1.len + st2.len;
  _temp.str = new char[_temp.len + 1];
 
  strin->my_strcpy(_temp.str, st1.str);
  strin->my_strcpy(_temp.str + st1.len, st2.str);
 
  return _temp;
}
 
istream &operator>>(istream &is, String &st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is) st = temp;
  while (is && is.get() != '\n') continue;
  return is;
}
 
void String::append(int n, char c) {
  String temp(str);
  delete[] str;
  len += n;
  str = new char[len + 1];
  strin->my_strcpy(str, temp.str);
  char ch[] = "T";
  ch[0] = c;
  while (n != 0) {
    strin->my_strcat(str, ch);
    n--;
  }
}
 
void String::append(const String &str1) {
  String temp(str);
  delete[] str;
  len += str1.len;
  str = new char[len + 1];
  strin->my_strcpy(str, temp.str);
  strin->my_strcat(str, str1.str);
}
 
void String::append(const String &str1, size_t pos, size_t cout) {
  if ((str1.len - (pos + cout)) > 0) {
    String temp(str);
    delete[] str;
    len += str1.len - (pos + cout);
    str = new char[len + 1];
    strin->my_strcpy(str, temp.str);
    char *temp1 = str1.str;
    while (pos != 0) {
      temp1++;
      pos--;
    }
    strin->my_strncat(str, temp1, cout);
  }
}
