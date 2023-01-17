#include <iostream>
#include "mystring.h"
 
int main() {
    String buffer[10] = {"Hello ", "Bye ", "Welcom ", "wOrLd "};
    String str2(buffer[2]);
    String str3;
    str3 = buffer[0] + str2;
    std::cout << "1: Sum string ||" << str3 << "\n";
    buffer[1].stringup();
    buffer[3].stringlow();
    str3 = buffer[1];
    str3.append(buffer[3]);
    std::cout << "2: Up and low registr registers string ||" << str3 << "\n";
    str3.append(5, 'n');
    str3.append(buffer[0], 3, 2);
    std::cout << "3: Adding characters to the end of a line ||" << str3 << "\n";
    for (int i = 0; i < 4; i++) {
      std::cout << buffer[i] << "\n";
    }
    std::cout << "\n-------------Sort array string\n";
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (buffer[i] > buffer[j]) {
          String temp(buffer[i]);
          buffer[i] = buffer[j];
          buffer[j] = temp;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      std::cout << buffer[i] << "\n";
    }
  return 0;
}
