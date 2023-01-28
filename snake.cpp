//A program to play snake on the console

#include <stdlib.h>
#include <iostream> 
#include <thread>

using namespace std;

#define sleepms(val) std::this_thread::sleep_for(val##ms)
int main() 
{
    cout << "\r\nHello World!";
    sleepms(1000);
    cout << "\r\nHello World!";
    sleepms(1000);
    cout << "\33[2K\r";
    sleepms(1000);
    cout << "\r\nHello World!";
    sleepms(1000);
    cout << "\r\nHello World!";
    sleepms(1000);
    cout << "\33[2K\r";
    sleepms(1000);
    cout << "\r\n";
    return 0;
}