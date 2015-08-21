/*************************************************************************
	> File Name: mutextlock.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2015 09:49:10 AM PDT
 ************************************************************************/

#include "mutexlock.h"

//互斥锁构造函数
MutexLock::MutexLock() {
    pthread_mutex_init(&m_mutex_,NULL);
}


//析构函数
MutexLock::~MutexLock() {
    pthread_mutex_destroy(&m_mutex_);
}


//上锁
void MutexLock::lock() {
    pthread_mutex_lock(&m_mutex_);
}

//解锁
void MutexLock::unlock() {
    pthread_mutex_unlock(&m_mutex_);
}


//获得互斥锁指针
pthread_mutex_t* MutexLock::getMutexPtr() {
    return &m_mutex_;
}

