#include <iostream>
#include <thread>
#include <string>
#include <cstdlib>
#include <unistd.h>

void thread_runner(const int arg1, const std::string &arg2) {  // arg3, and so on
    std::cout << "Thread created with parameters " << arg1 << " and '" << arg2 << "'" << std::endl;

    // yield() suggests to the OS to reschedule the threads it should run
    // std::this_thread::yield();
}

#define THREADS 10

int main(const int argc, const char *argv[]) {
    std::thread threads[THREADS];

    for (auto &i : threads) {
        std::cout << "Creating thread" << std::endl;
        i = std::thread(thread_runner, i, "Hello");
    }

    for (auto &thread : threads) {
        thread.join();
        std::cout << "Thread exited" << std::endl;
    }

    return EXIT_SUCCESS;
}
