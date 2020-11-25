#include <iostream>			
#include <string>
#include <sstream>
using namespace std;


struct messages {
    int saddress;
    int daddress;
    short sport;
    short dport;
    string payload;
};

void split(int ip, unsigned int& a, unsigned int& b, unsigned int& c, unsigned int& d)
{
    a = (ip & (255 << 24)) >> 24;
    

    b = (ip & (255 << 16)) >> 16; 
    c = (ip & (255 << 8)) >> 8;
    d = (ip & (255));

}

void printQ2()
{
    int ip = 0xff0fff00;	
    unsigned int a = 0, b = 0, c = 0, d = 0;

    split(ip, a, b, c, d);
    // function uses reference parameters to fill the channel values
    cout << "IP in hex: " << hex << ip << endl;
    cout << "A in hex: " << a << endl;
    cout << "B in hex: " << b << endl;
    cout << "C in hex: " << c << endl;
    cout << "D in hex: " << d << endl;
    cout << "Converting Back To DEC: " << dec << endl;

}

void displayMessage(const messages* mg)	// movie is a Pointer to a movie_t struct
{
    unsigned int a = 0, b = 0, c = 0, d = 0;
    unsigned int a2 = 0, b2 = 02, c2 = 02, d2 = 0;
    int s = mg->saddress;
    int dis = mg->daddress;
    split(s, a, b, c, d);
    cout <<"Source: " << a <<"." << b << "." << c << "." << d << "." << endl;
    split(dis, a2, b2, c2, d2);
    cout << "Destination: " << a2 << "." << b2 << "." << c2 << "." << d2 << "." << endl;
    cout << "Message: Hi how is it going?" << endl;
}

void getHeader(messages* mg)
{
    int* array = new int[3];
    array[0] = mg->saddress;
    array[1] = mg->daddress;
    int port = port << mg->sport << mg->dport;
    array[2] = port;
    unsigned char l = (char) mg->payload;
    int lenth = lenth << l;
    array[3] = lenth;

    cout << "Source Address: " << array[0] << endl << ", Destination Address: " << array[1] 
        << endl << "Source IP: " << array[2] << endl << "Message Length: " << array[3] << endl;
   


}

int factorial(int a)
{
    if (a > 1)
        return (a * factorial(a - 1));

    return 1;
}

int main()
{
    

    messages message;
    message.saddress = 0x000044ff;
    message.daddress = 0xff330000;
    message.sport = 0x00ff;
    message.dport = 0xab00;
    message.payload = "Hello";

    cout << "Source Address: " << message.saddress << ", Destination Address: " << message.daddress
        << "Source Port: " << message.sport << ", Destination Port: " << message.dport
        << "payload: " << message.payload;
 
    printQ2();
    message.payload = "Hi how is it going?";
    displayMessage(&message);
    getHeader(&message);
    factorial(6);
}