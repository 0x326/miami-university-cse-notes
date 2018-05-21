// Every class can only be defined once
// but this file might be included multiple times
// This guard makes sure IntegerAggregate is only defined during the first #include
#ifndef INTEGER_AGGREGATE_H
#define INTEGER_AGGREGATE_H

#include "Integer.h"

class IntegerAggregate {
    // list fields/members here
    // (private by default)

 public:
    int a;
    Integer b;
    Integer *c;
    Integer &d;

    IntegerAggregate(Integer *c, Integer &d);

    // const copy constructor
    IntegerAggregate(const IntegerAggregate &obj);

    // non-const copy constructor
    IntegerAggregate(IntegerAggregate &obj);

    // Copying a const variable requires a const copy constructor
    // Copying a non-const variable can use either but will prefer
    //   a non-const copy constructor if defined

 private: // Style: indented with one extra space

}; // notice the semicolon

#endif //INTEGER_AGGREGATE_H
