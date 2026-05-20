#include "../include/thread_pool.h"

/*
 * ThreadPool implementation
 * Provides a fixed-size pool of worker threads that execute tasks
 * from a shared task queue in a thread-safe manner.
 */

ThreadPool::ThreadPool(size_t numThreads) {
    stop = false;

    // Create worker threads
    for (size_t i = 0; i < numThreads; i++) {

        workers.emplace_back([this]() {

            while (true) {

                std::function<void()> task;

                {
                    // Lock task queue for thread-safe access
                    std::unique_lock<std::mutex> lock(queueMutex);

                    // Wait until there is a task or the pool is stopping
                    condition.wait(lock, [this]() {
                        return stop || !tasks.empty();
                    });

                    // Exit condition: no more tasks and stop flag is set
                    if (stop && tasks.empty()) {
                        return;
                    }

                    // Retrieve next task from queue
                    task = tasks.front();
                    tasks.pop();
                }

                // Execute task outside the lock to avoid blocking other threads
                task();
            }
        });
    }
}

/*
 * Enqueue a new task into the thread pool
 */
void ThreadPool::enqueue(std::function<void()> task) {

    {
        // Protect shared queue during modification
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.push(task);
    }

    // Notify one waiting worker thread
    condition.notify_one();
}

/*
 * Destructor
 * Ensures all threads finish execution safely before destruction
 */
ThreadPool::~ThreadPool() {

    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }

    // Wake up all threads so they can exit
    condition.notify_all();

    // Join all worker threads
    for (std::thread& worker : workers) {
        worker.join();
    }
}