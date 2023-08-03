#pragma once
#include "QuickSort.h"
#include <mutex>
#include <queue>
#include <condition_variable>

class BlockedQueue 
{
private:
    std::mutex m_locker;
    std::queue<QuickSort *> m_task_queue;
    std::condition_variable m_notifier;
public:
    BlockedQueue() = default;
    void push(QuickSort *);
    void pop(QuickSort *(&));
    bool fast_pop(QuickSort *(&));
    ~BlockedQueue() = default;
};