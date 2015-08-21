/*************************************************************************
	> File Name: thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:34:10 AM PDT
 ************************************************************************/

#include "thread.h"

//启动线程（创建）
void Thread::start() {
    pthread_create(&m_thread_id_,NULL,runInThread,this);
    m_is_running_ = true;
}


//汇合线程（执行结束）
void Thread::join() {
    pthread_join(m_thread_id_,NULL);
    m_is_running_ = false;
}


//析构函数（分离线程）
Thread::~Thread() {
    if(m_is_running_) {
        pthread_detach(m_thread_id_);
        m_is_running_ = false;
    }
}


void* Thread::runInThread(void *arg)
{
    //参数: *arg 为pthread_create()传入的this（即具体的子线程）
    Thread *pthread = static_cast<Thread*>(arg);
    
    //关键，执行回调函数即可
    pthread->m_callback_();

    return NULL;
}
