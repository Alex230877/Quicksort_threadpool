#include "TaskMonitor.h"

TaskMonitor::TaskMonitor() : trigger(false) {}

void TaskMonitor::setTaskMonitor()
{
    std::unique_lock<std::mutex> l(_defender);
    if (trigger == false)
    {
        trigger = true;
    }
    else
    {
        trigger = false;
    }
}

bool TaskMonitor::getTaskMonitor()
{
    std::unique_lock<std::mutex> l(_defender);
    return trigger;
}