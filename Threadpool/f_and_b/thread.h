/*************************************************************************
	> File Name: thread.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:25:30 AM PDT
 ************************************************************************/

#ifndef _THREAD_H
#define _THREAD_H

#include "noncopyable.h"
#include <pthread.h>
#include <functional>


class Thread: private Noncopyable {
 public:
    //定义回调函数，形式：void（）
    typedef std::function<void()> ThreadCallback;

    //线程构造函数，要传入不同的具体实现的回调函数
    Thread(ThreadCallback cb):m_thread_id_(0),
                 m_is_running_(false),
                 m_callback_(cb)
    {}

    ~Thread(); 

    void start();
    void join();

    static void* runInThread(void *arg); //需要传入线程中的函数
 private:
    pthread_t m_thread_id_;
    bool m_is_running_;
    ThreadCallback m_callback_;
};




#endif
