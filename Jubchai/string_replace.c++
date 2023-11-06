#include <iostream>
#include <string>

int main() {
    std::string longString;

    std::cout << "Enter a long string: ";
    std::getline(std::cin, longString);

    // Iterate through the string and replace three consecutive spaces with " 0 "
    for (size_t i = 0; i < longString.size() - 2; ++i) {
        if (longString[i] == ' ' && longString[i + 1] == ' ' && longString[i + 2] == ' ') {
            longString.replace(i, 3, " 0 ");
        }
    }

    // Print the modified string
    std::cout << "Modified string: " << longString << std::endl;

    return 0;
}
