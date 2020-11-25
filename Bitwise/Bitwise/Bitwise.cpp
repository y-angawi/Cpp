// Bitwise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void argb(int x) {

    int mask = 0xff;
    
    int blue = x & mask;
    x = x >> 8;
    int green = x & mask;
    x = x >> 8;
    int red = x & mask;
    x = x >> 8;
    int alpha = x & mask;

    cout << "Blue: " << hex << blue << " Green: " << green << " Red: " << red << " Alpha: " << alpha << dec;

}

int main()
{
    // q1
    /*int x = 15;
    cout << "Size Of int " << sizeof(x) << " its value in hexadecimal: " << hex << x <<" and in decimal " << dec << x;
    cout << x << endl;
    x = x << 4;
    cout << hex << x << dec << " " <<x << endl;*/

    // q2
    unsigned char alpha = 0xff, red = 0x0f, green = 0xff, blue = 0x00;
    int colour = 0;

    colour = colour | alpha;
    colour = colour << 8;

    colour = colour | red;
    colour = colour << 8;

    colour = colour | green;
    colour = colour << 8;

    colour = colour | blue;
   // colour = colour << 8;

    cout << hex << colour << dec << " " << colour << endl;

    // q3
    argb(0xff0ff000);

 

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
