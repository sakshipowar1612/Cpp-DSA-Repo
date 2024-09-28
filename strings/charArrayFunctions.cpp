#include <iostream>
#include <cstring>
#include<string>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    // String length
    std::cout << "Length of str1: " << strlen(str1) << std::endl;
    
    // String copy 
    strcpy(str1, str2);
    std::cout << "str1 after strcpy: " << str1 << std::endl;
    
    // String concatenation
    strcat(str1, "!!!");
    std::cout << "str1 after strcat: " << str1 << std::endl;
    
    // String comparison
    if (strcmp(str1, str2) == 0) {
        std::cout << "str1 and str2 are equal" << std::endl;
    } else {
        std::cout << "str1 and str2 are not equal" << std::endl;
    }


    return 0;
}
