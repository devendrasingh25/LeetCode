#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0'; // convert char to int
        if (j >= 0) sum += b[j--] - '0';

        result = char(sum % 2 + '0') + result; // current bit
        carry = sum / 2; // carry for next position
    }

    return result;
}

int main() {
    string a = "1010", b = "1011";
    cout << addBinary(a, b) << endl;  // Output: 10101
    return 0;
}
