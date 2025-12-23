/* Algorithm Challenge & Problem Solving
 * 39 - Copy Prime Numbers to a New Array
 *
 * This program fills an array with random numbers between 1 and 100, then copies only the prime numbers into another array using the, AddArrayElement function.
 *
 * The challenge focuses on:
 * - Prime number checking
 * - Filtering array elements
 * - Reusing functions
 * - Simulating dynamic arrays using fixed-size arrays
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Enum to represent whether a number is prime or not
enum primornot
{
    prim = 1,
    notprim = 2
};

// Checks if a given number is prime
primornot checknumber(int Number)
{
    int limit = round(Number / 2);

    for (int i = 2; i <= limit; i++)
    {
        if (Number % i == 0)
            return primornot::notprim;
    }
    return primornot::prim;
}

// Generates a random number within a given range
int RandNumber(int From, int To)
{
    int Rand = rand() % (To - From + 1) + From;
    return Rand;
}

// Fills an array with random numbers
void FillArrayWhithRandomNumber(int arr[100], int &arrlength)
{
    cout << "Enter number of elements:\n";
    cin >> arrlength;

    for (int i = 0; i < arrlength; i++)
    {
        arr[i] = RandNumber(1, 100);
    }
}

// Prints array elements
void PrintArray(int arr[100], int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Adds a new element to the array
void AddArrayElement(int Number, int arr[100], int &arrlength)
{
    arrlength++;
    arr[arrlength - 1] = Number;
}

// Copies only prime numbers to the destination array
void CopyPrimNumberUsingAddArrayElement(
    int arrSource[100],
    int arrDistination[100],
    int arrlength,
    int &arrDistinationLength)
{
    for (int i = 0; i < arrlength; i++)
    {
        if (checknumber(arrSource[i]) == primornot::prim)
        {
            AddArrayElement(arrSource[i], arrDistination, arrDistinationLength);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrlength = 0;
    int arr2[100], arr2length = 0;

    FillArrayWhithRandomNumber(arr, arrlength);

    CopyPrimNumberUsingAddArrayElement(arr, arr2, arrlength, arr2length);

    cout << "Array Elements: ";
    PrintArray(arr, arrlength);

    cout << "\nPrime Numbers Array: ";
    PrintArray(arr2, arr2length);

    return 0;
}
