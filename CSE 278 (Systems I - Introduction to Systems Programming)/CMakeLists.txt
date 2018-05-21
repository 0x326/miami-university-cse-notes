cmake_minimum_required(VERSION 3.9)
project(CSE_278)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSE_278_CLASSES "Classes/main.cpp" "Classes/IntegerAggregate.cpp" "Classes/Integer.cpp")
add_executable(CSE_278_STRINGS "Strings/main.cpp")
add_executable(CSE_278_MEMORY_ALLOCATION "Memory Allocation/main.cpp" "Memory Allocation/NoArgClass.cpp" "Memory Allocation/NoArgClass.h" "Memory Allocation/OneArgClass.cpp" "Memory Allocation/OneArgClass.h" "Memory Allocation/TwoArgClass.cpp" "Memory Allocation/TwoArgClass.h")
add_executable(CSE_278_POLYMORPHISM "Polymorphism/main.cpp"
        "Polymorphism/Rectangle.cpp" "Polymorphism/SpecialRectangle.cpp" "Polymorphism/Square.cpp")
add_executable(CSE_278_FILES Files/main.cpp)
add_executable(CSE_278_NUMBER_REPRESENTATION "Number Representation/main.cpp")
add_executable(CSE_278_OVERLOADING_OPERATORS "Overloading Operators/main.cpp" "Overloading Operators/Integer.cpp")
add_executable(CSE_278_MISC Misc/main.cpp)
