#include "mystring.h"

void* myString::my_memchr(const void *str, int c, size_t n) {
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

int myString::my_memcmp(const void *str1, const void *str2, size_t n) {
  char *ptr1 = (char *)str1;
  char *ptr2 = (char *)str2;
  int cmp = 0;

  if (n) {
    while (*(char *)ptr1 == *(char *)ptr2 && --n) {
      ptr1 = (char *)ptr1 + 1;
      ptr2 = (char *)ptr2 + 1;
    }
    cmp = (*((unsigned char *)ptr1) - *((unsigned char *)ptr2));
  }

  return cmp;
}

void* myString::my_memcpy(void *dest, const void *src, size_t n) {
  char *cdest = (char *)dest;
  const char *csrc = (char *)src;

  for (size_t i = 0; i < n; ++i) {
    *cdest++ = *csrc++;
  }

  return dest;
}

void* myString::my_memmove(void *dest, const void *src, size_t n) {
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

char* myString::my_strcat(char *dest, const char *src) {
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

char* myString::my_strncat(char *dest, const char *src, size_t n) {
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

char* myString::my_strchr(const char *str, int c) {
  char *ptr = (char *)str;

  for (; (*ptr != (unsigned char)c) && (*ptr != '\0'); ptr++) {
  }
  if (*ptr == '\0') {
    ptr = NULL;
  }

  return ptr;
}

int myString::my_strcmp(const char *str1, const char *str2) {
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

int myString::my_strncmp(const char *str1, const char *str2, size_t n) {
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

char* myString::my_strcpy(char *dest, const char *src) {
  char *ptr = dest;

  while (*src != '\0') {
    *dest++ = *src++;
  }

  *dest = '\0';

  return ptr;
}

char* myString::my_strncpy(char *dest, const char *src, size_t n) {
  char *ptr = dest;

  while (*src && n-- && (dest != NULL)) {
    *dest++ = *src++;
  }

  *dest = '\0';

  return ptr;
}

size_t myString::my_strcspn(const char *str1, const char *str2) {
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

size_t myString::my_strlen(const char *str) {
  size_t count = 0;

  while (*str != '\0') {
    str++;
    count++;
  }

  return count;
}

const char* myString::my_strpbrk(const char *str1, const char *str2) {
  char *ptr = NULL;

  for (const char *i = str1; *i; i++) {
    for (const char *j = str2; *j; j++) {
      if (*i == *j) {
        ptr = (char *)i;
        break;
      }
    }

    if (ptr != NULL) {
      break;
    }
  }

  return ptr;
}

char* myString::my_strrchr(const char *str, int c) {
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

size_t myString::my_strspn(const char *str1, const char *str2) {
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

const char* myString::my_strstr(const char *haystack, const char *needle) {
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

char* myString::my_strtok(char *str, const char *delim) {
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

void path::input_path(char* str){
    if (str == NULL){
        std::cout << "ERROR::Try to input the path to the file" << std::endl;;
    } else if (str[0] == '\n'){
      std::cout << "ERROR::Try to input the path to the file" << std::endl;;
    } else {
      std::ifstream file(str);
      if (!file.is_open()){
        std::cout << "ERROR::There is no such file" << std::endl;;
      } else {
        if (path_file != NULL){
          delete_path();
          number_paths--;
        }
        number_paths++;
        path_file = new char[my_strlen(str)+1];
        my_strcpy(path_file, str);
        file.close();
      }
    }
    std::cout << number_paths;
}

void path::output_path(){
  if(path_file != NULL){
    std::cout << path_file << std::endl;
  } else {
    std::cout << "ERROR::Input the path" << std::endl;
  }
}

void path::delete_path(){
  if(path_file != NULL){
    delete(path_file);
    path_file = NULL;
  } else {
    std::cout << "ERROR::The patch has already been deleted or you didn't input it" << std::endl;
  }
}