#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";

    // Concatenation
    std::string str3 = str1 + " " + str2;
    std::cout << "Concatenated string: " << str3 << std::endl;

    // Length
    std::cout << "Length of str1: " << str1.length() << std::endl;

    // Accessing individual characters
    std::cout << "First character of str2: " << str2[0] << std::endl;

    // Substring
    std::string substr = str3.substr(6, 5);
    std::cout << "Substring: " << substr << std::endl;

    // Find
    size_t pos = str3.find("World");
    if (pos != std::string::npos) {
        std::cout << "Found at position: " << pos << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // Replace
    str3.replace(6, 5, "Universe");
    std::cout << "Replaced string: " << str3 << std::endl;

    // Erase
    str3.erase(6, 8);
    std::cout << "Erased string: " << str3 << std::endl;

    // Insert
    str3.insert(6, "World");
    std::cout << "Inserted string: " << str3 << std::endl;

    // Compare
    int result = str1.compare(str2);
    if (result == 0) {
        std::cout << "Strings are equal" << std::endl;
    } else if (result < 0) {
        std::cout << "str1 is less than str2" << std::endl;
    } else {
        std::cout << "str1 is greater than str2" << std::endl;
    }

    std::string str = "Hello";
    str.push_back('!');
    std::cout << str << std::endl;  // Output: Hello!
    return 0;
}
