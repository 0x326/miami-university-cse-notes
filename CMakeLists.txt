cmake_minimum_required(VERSION 3.9)
project(MIAMI_UNIVERSITY_CSE_NOTES)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# CSE 278
add_executable(CSE_278_CLASSES
        "CSE 278 (Systems I - Introduction to Systems Programming)/Classes/main.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Classes/IntegerAggregate.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Classes/Integer.cpp")

add_executable(CSE_278_STRINGS
        "CSE 278 (Systems I - Introduction to Systems Programming)/Strings/main.cpp")

add_executable(CSE_278_MEMORY_ALLOCATION
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/main.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/NoArgClass.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/NoArgClass.h"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/OneArgClass.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/OneArgClass.h"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/TwoArgClass.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Memory Allocation/TwoArgClass.h")

add_executable(CSE_278_POLYMORPHISM
        "CSE 278 (Systems I - Introduction to Systems Programming)/Polymorphism/main.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Polymorphism/Rectangle.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Polymorphism/SpecialRectangle.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Polymorphism/Square.cpp")

add_executable(CSE_278_FILES
        "CSE 278 (Systems I - Introduction to Systems Programming)/Files/main.cpp")

add_executable(CSE_278_NUMBER_REPRESENTATION
        "CSE 278 (Systems I - Introduction to Systems Programming)/Number Representation/main.cpp")

add_executable(CSE_278_OVERLOADING_OPERATORS
        "CSE 278 (Systems I - Introduction to Systems Programming)/Overloading Operators/main.cpp"
        "CSE 278 (Systems I - Introduction to Systems Programming)/Overloading Operators/Integer.cpp")

add_executable(CSE_278_MISC
        "CSE 278 (Systems I - Introduction to Systems Programming)/Misc/main.cpp")

# CSE 381
add_executable(CSE_381_DATA_STRUCTURES_VECTOR
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/C++ Data Structures/vector.cpp")

add_executable(CSE_381_DATA_STRUCTURES_UNORDERED_MAP
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/C++ Data Structures/unordered_map.cpp")

add_executable(CSE_381_CONSOLE_IO
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/Console IO/main.c")

add_executable(CSE_381_IPC_PIPES
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/IPC (Interprocess Communication)/pipes.c")

add_executable(CSE_381_IPC_SHARED_MEMORY
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/IPC (Interprocess Communication)/shared-memory.c")

add_executable(CSE_381_NETWORKING_SERVER
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/Networking/server.c")

add_executable(CSE_381_MULTITHREADING_PTHREAD
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/Multithreading/pthread.c")

add_executable(CSE_381_MULTITHREADING_OPENMP
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/Multithreading/OpenMP.c")

add_executable(CSE_381_MULTITHREADING_THREAD
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/Multithreading/thread.cpp")

add_executable(CSE_381_PARALLELISM_TASK
        "CSE 381 (Systems II - OS, Currency, Virtualization, and Security)/Parallelism/Task Parallelism.c")
