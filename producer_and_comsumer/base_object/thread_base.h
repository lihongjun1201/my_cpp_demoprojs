/*************************************************************************
	> File Name: thread_base.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:25:30 AM PDT
 ************************************************************************/

#ifndef _THREAD_BASE_H
#define _THREAD_BASE_H

#include "noncopyable.h"
#include <pthread.h>


class ThreadBase: private Noncopyable {
 public:
    ThreadBase():m_thread_id_(0),
                 m_is_running_(false)
    {}

    ~ThreadBase();

    void start();
    void join();

    virtual void run() = 0;   //线程具体要执行的任务，由子类实现

    static void* runInThread(void *arg); //需要传入线程中的函数
 private:
    pthread_t m_thread_id_;
    bool m_is_running_;
};




#endif
