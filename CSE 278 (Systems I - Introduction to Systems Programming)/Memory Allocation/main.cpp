#include "NoArgClass.h"
#include "OneArgClass.h"
#include "TwoArgClass.h"

int main(int argc, char *argv[]) {
    /// Static allocation
    int arr1[5];  // Memory is not initialized; May contain garbage
    int arr2[] = {1, 2, 3, 4, 5};

    NoArgClass noArg1;
    // NoArgClass noArg2();  // Declares a *function* that returns a NoArgClass object

    OneArgClass oneArg1{1};  // Uniform initialization (preferred)
    OneArgClass oneArg2(1);
    OneArgClass oneArg3 = 1;
    OneArgClass oneArg4 = {1};

    TwoArgClass twoArg1{1, 2};  // Uniform initialization (preferred)
    TwoArgClass twoArg2(1, 2);
    TwoArgClass twoArg3 = {1, 2};

    /// Dynamic allocation
    int *arr3 = new int[5];
    // In general, ``auto*`` can be used to avoid rewriting the type name
    // when a pointer is initialized as it is declared
    auto *arr4 = new int[5];

    // Array size must be specified
    // The length of the initialization array must be less than or equal to the specified array size
    auto *arr5 = new int[5]{1, 2, 3, 4, 5};

    auto *noArg3 = new NoArgClass;
    auto *noArg4 = new NoArgClass();

    auto *oneArg5 = new OneArgClass{1};
    auto *oneArg6 = new OneArgClass(1);

    auto *twoArg4 = new TwoArgClass{1, 2};
    auto *twoArg5 = new TwoArgClass(1, 2);

    // Deallocate dynamic memory
    delete[] arr3;
    delete[] arr4, arr5;

    delete noArg3, noArg4;
    // delete {oneArg5, oneArg6};
    delete (twoArg4, twoArg5);
}
