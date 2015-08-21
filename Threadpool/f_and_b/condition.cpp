/*************************************************************************
	> File Name: condition.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 12:51:40 AM PDT
 ************************************************************************/

#include "mutexlock.h"
#include "condition.h"

//条件锁构造函数
Condition::Condition(MutexLock &mutex): m_mutex_ref_(mutex) {
    pthread_cond_init(&m_condition_,NULL);
}


//析构函数
Condition::~Condition() {
    pthread_cond_destroy(&m_condition_);
}


//等待条件成立,需要传入互斥锁
void Condition::wait() {
    pthread_cond_wait(&m_condition_,m_mutex_ref_.getMutexPtr());
}

//通知函数
void Condition::notify() {
    pthread_cond_signal(&m_condition_);
}

//通知所有阻塞线程
void Condition::notifyAll() {
    pthread_cond_broadcast(&m_condition_);
}
