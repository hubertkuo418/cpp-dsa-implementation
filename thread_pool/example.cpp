#include "include/thread_pool.h"

#include <iostream>
#include <chrono>
#include <mutex>

static std::mutex coutMutex;

int main() {

    ThreadPool pool(3);

    for (int i = 0; i < 10; i++) {

        pool.enqueue([i]() {

    {
        std::lock_guard<std::mutex> lock(coutMutex);

        std::cout << "Task " << i
                  << " running on thread "
                  << std::this_thread::get_id()
                  << std::endl;
    }

});
    }

    return 0;
}