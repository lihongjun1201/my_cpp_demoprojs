/*************************************************************************
	> File Name: condition.h
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2015 09:45:19 AM PDT
 ************************************************************************/

#ifndef _CONDITION_H
#define _CONDITION_H

#include "noncopyable.h"
#include <pthread.h>

//互斥锁前向声明
class MutexLock;


class Condition: public Noncopyable {
 public:
    Condition(MutexLock &mutex);
    ~Condition();

    void wait();
    void notify();
    void notifyAll();

 private:
    pthread_cond_t m_condition_;   //条件成员变量
    MutexLock &m_mutex_ref_;   //互斥锁的引用
};







#endif
