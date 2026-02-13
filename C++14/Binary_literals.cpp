// code example for Binary literals
/*
Definition:
Binary literals  allowing direct representation of binary numbers in code 
using a specific prefix.
Binary literals are resolved at compile time.
The binary number can be expressed as 0b or 0B as the prefix.
Hexadecimal number with prefix '0x'
Octal number with prefix '0'

Use Case 1 — Bit Masking (Real-World Scenario)
Very common in:
Embedded systems
Networking
Low-level driver development
Permission flags

Binary literals:
Improve bitmask readability
Reduce mistakes in flag configuration
Make hardware register definitions clearer
Improve maintainability

*/

#include <iostream>
using namespace std;

int main()
{    
	cout << "\n Binary literals with Examples :";
    int a = 0b1010;      // 10
    int b = 0b1111;      // 15
    // PRINT BINARY NUMBER
	cout << "\n Binary number a = " << a;  // Output: a = 10
	cout << "\n b = " << b;  // Output: b = 15

    // Hexadecimal number with prefix '0x'
    int h = 0x13ac;
    // Print the number of the hexadecimal form
    cout << "\n Hexadecimal number h = " << h;

    // Octal number with prefix '0'
    int o = 0117;
    // Print the number of the octal form
    cout << "\n octal number o = " << o << endl;  

	cout << "\n Use Case 1 Bit Masking (Real-World Scenario) :\n";
    const unsigned int READ = 0b0001;
    const unsigned int WRITE = 0b0010;
    const unsigned int EXECUTE = 0b0100;

    unsigned int permission = READ | WRITE;

    if (permission & WRITE)
        cout << "Write allowed\n";


	cout << "\n Use Case 2 TCP Flags (Real-World Scenario) :\n";
    const unsigned int SYN = 0b00000010;
    const unsigned int ACK = 0b00010000;

    unsigned int tcpFlags = SYN | ACK;
    cout << "TCP Flags: " << tcpFlags;

    // Example: Control Register
    unsigned char controlReg = 0b1010'0101;

	cout << "\n Use Case 2 — Hardware Register Representation :\n";
    cout << "Register Value: " << static_cast<int>(controlReg);

    cout << endl;    
}
