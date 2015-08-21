/*************************************************************************
	> File Name: thread_base.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:34:10 AM PDT
 ************************************************************************/

#include "thread_base.h"

//启动线程（创建）
void ThreadBase::start() {
    pthread_create(&m_thread_id_,NULL,runInThread,this);
    m_is_running_ = true;
}


//汇合线程（执行结束）
void ThreadBase::join() {
    pthread_join(m_thread_id_,NULL);
    m_is_running_ = false;
}


//析构函数（分离线程）
ThreadBase::~ThreadBase() {
    if(m_is_running_) {
        pthread_detach(m_thread_id_);
        m_is_running_ = false;
    }
}


void* ThreadBase::runInThread(void *arg)
{
    //派生子线程复写run()方法
    //向上转型，ThreadBase指针指向子对象（实现多态）
    //参数: *arg 为pthread_create()传入的this（即具体的子线程）
    ThreadBase *pthread = static_cast<ThreadBase*> (arg);
    pthread->run();

    return NULL;
}
