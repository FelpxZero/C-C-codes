#include <iostream>
#include <string>

void inverterString(std::string& str) {
    int inicio = 0;
    int fim = str.length() - 1;

    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    std::string minhaString = "invertida";
    std::cout << "String original: " << minhaString << std::endl;

    inverterString(minhaString);

    std::cout << "String invertida: " << minhaString << std::endl;

    return 0;
}
