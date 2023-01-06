// HashMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Dictionary.cpp"

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    while (true)
    {
        Dictionary<int, int> test = Dictionary<int, int>(2);
        //bool temp1 = test.Set(1, 1);
        //bool temp1point5 = test.Set(2, 2);
        //bool temp2 = test.Set(1, 2);
        bool result1 = test.Set(5, 6);
        bool result2 = test.Set(15, 3);
        bool result3 = test.Set(6, 15);
        bool result4 = test.Set(1, 11);
        int result = test.Get(6);
        bool result5 = test.Set(6, 6);

        int notRandom = 5;
        int  result7 = test.Get(5);
        int  result8 = test.Get(15);
        int  result9 = test.Get(6);
        int  result10 = test.Get(1);

        bool result11 = test.Set(1, 10);
        int  result12 = test.Get(1);

        bool result13 = test.Set(50, 5);

        bool result14 = test.Remove(50, 3);
        bool result15 = test.Remove(50, 5);
        bool result16 = test.Remove(50, 5);
    }
    //int  result17 = test.Get(50);
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
