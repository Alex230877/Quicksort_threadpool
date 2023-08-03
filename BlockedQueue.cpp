#include "BlockedQueue.h"
#include <iostream>

void BlockedQueue::push(QuickSort * ob)
{
    std::lock_guard<std::mutex> l(m_locker);
    m_task_queue.push(ob);
    m_notifier.notify_one();
}

void BlockedQueue::pop(QuickSort * (& ob))
{
    std::unique_lock<std::mutex> l(m_locker);
    if (m_task_queue.empty())
    {
        m_notifier.wait(l, [this](){return !m_task_queue.empty();});
    }
    ob = m_task_queue.front();
    m_task_queue.pop();
}

bool BlockedQueue::fast_pop(QuickSort * (& ob))
{
    std::lock_guard<std::mutex> l(m_locker);
    bool b = m_task_queue.empty();
    if (b == true)
    {
        ob = nullptr;
    }
    else
    {
        ob = m_task_queue.front();
        m_task_queue.pop();
    }
    return b;
}