#include <iostream>
using namespace std;

bool fib(int num){
    int a = 0;
    int b = 1;
    int c = a + b;
    
    while (c <= num) {
        if (c == num) {
            return true;
        }
        a = b;
        b = c;
        c = a + b;
    }
    return false;
} 

int main() {
    int num;
    cout << "Digite um número: ";
    cin >> num;
    
     if (fib (num)) {
        cout << num << " pertence à sequência de Fibonacci." << endl;
    } else {
        cout << num << " não pertence à sequência de Fibonacci." << endl;
    }
    
    return 0;
}
