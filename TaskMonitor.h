#pragma once
#include <mutex>

class TaskMonitor
{
private:
    bool trigger;
    std::mutex _defender;
public:
    TaskMonitor();
    void setTaskMonitor();
    bool getTaskMonitor();
    ~TaskMonitor() = default;
};