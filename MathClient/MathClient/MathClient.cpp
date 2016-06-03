// MathClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MathLibrary.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double a = 7.4;
    int b = 99;

    cout << "a + b = " <<
        MathLibrary::Functions::Add(a, b) << endl;
    cout << "a * b = " <<
        MathLibrary::Functions::Multiply(a, b) << endl;
    cout << "a + (a * b) = " <<
        MathLibrary::Functions::AddMultiply(a, b) << endl;

    return 0;
}

// MathClient.cpp : Defines the entry point for the console application.
// Compile by using: cl /EHsc /link MathLibrary.lib MathClient.cpp