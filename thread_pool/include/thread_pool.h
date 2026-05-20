#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

/*
 * ThreadPool class
 * ----------------
 * A simple thread pool implementation for executing tasks concurrently.
 * It manages a fixed number of worker threads that continuously fetch
 * and execute tasks from a shared task queue.
 */
class ThreadPool {
private:
    // Worker threads executing tasks
    std::vector<std::thread> workers;

    // Queue storing pending tasks (each task is a callable object)
    std::queue<std::function<void()>> tasks;

    // Mutex to protect access to the task queue
    std::mutex queueMutex;

    // Condition variable to notify worker threads of new tasks
    std::condition_variable condition;

    // Flag indicating whether the thread pool is stopping
    bool stop;

public:
    /*
     * Constructor
     * Initializes the thread pool and launches worker threads.
     *
     * @param numThreads Number of worker threads to create
     */
    ThreadPool(size_t numThreads);

    /*
     * Destructor
     * Gracefully stops all worker threads and cleans up resources.
     */
    ~ThreadPool();

    /*
     * Enqueue a new task into the thread pool.
     *
     * @param task A callable function to be executed by worker threads
     */
    void enqueue(std::function<void()> task);
};

#endif