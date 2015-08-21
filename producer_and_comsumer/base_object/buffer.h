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

class Buffer {
 public:
    Buffer(int size);
    
    void push(int );
    int pop();

    bool isEmpty();
    bool isFull();

 private:
    MutexLock m_mutex_;
    Condition m_notfull;
    Condition m_notempty;
    int m_size_;
    std::queue<int> m_queue_;  //缓存队列
};
    




#endif
