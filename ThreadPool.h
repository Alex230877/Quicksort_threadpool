#pragma once
#include <vector>
#include <thread>
#include "BlockedQueue.h"
#include "TaskMonitor.h"

class ThreadPool 
{
private:
    int m_thread_count;
    std::vector<std::thread> m_threads;
    std::vector<BlockedQueue> m_thread_queues;
    std::vector<TaskMonitor> trigger;
    int m_index;
public:
    ThreadPool();
    void start();
    void stop();
    void push_task(QuickSort * ob);
    void threadFunc(int qindex);
    bool checkTaskMonitor();
    void setTaskMonitor(int i);
    ~ThreadPool() = default;
};