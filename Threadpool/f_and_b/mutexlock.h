/*************************************************************************
	> File Name: mutexlock.h
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2015 09:46:18 AM PDT
 ************************************************************************/

#ifndef _MUTEXLOCK_H
#define _MUTEXLOCK_H


#include "noncopyable.h"
#include <pthread.h>

class MutexLock: private Noncopyable {
 public:
    MutexLock();
    ~MutexLock();

    void lock();
    void unlock();

    pthread_mutex_t* getMutexPtr(); //获取互斥锁指针

 private:
    pthread_mutex_t m_mutex_;
};


// RAII技术管理互斥锁 
class MutexLockGuard {
 public:
    MutexLockGuard(MutexLock &mutex):
        m_mutex_(mutex) {
            m_mutex_.lock();
        }

    ~MutexLockGuard() {
        m_mutex_.unlock();
    }

 private:
    MutexLock &m_mutex_;
};




#endif
