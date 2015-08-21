/*************************************************************************
	> File Name: buffer.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 12:58:11 AM PDT
 ************************************************************************/

#ifndef _BUFFER_H
#define _BUFFER_H

#include "mutexlock.h"
#include "condition.h"
#include <queue>
#include <functional>

class Buffer {
 public:
    typedef std::function<void()> Task;
    Buffer(int size);
    
    void push(Task task );
    Task pop();

    bool isEmpty();
    bool isFull();

 private:
    MutexLock m_mutex_;
    Condition m_notfull;
    Condition m_notempty;
    int m_size_;
    std::queue<Task> m_queue_;  //缓存队列,产品为任务函数对象
};
    




#endif
