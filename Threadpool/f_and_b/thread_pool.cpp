/*************************************************************************
	> File Name: thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Aug 2015 08:25:10 PM PDT
 ************************************************************************/

#include "thread_pool.h"
#include "thread.h"


//线程池构造函数
//传入参数：任务区大小，线程数量（注意顺序）
Threadpool::Threadpool(int bufsize,int threadnum):
    m_size_(bufsize),
    m_buffer_(m_size_),
    m_thread_num_(threadnum),
    m_threadspool_(m_thread_num_),
    m_is_exit_(false)
{}


//线程池析构函数
Threadpool::~Threadpool() {
    stop();
}


//启动线程池中所有线程
void Threadpool::start() {
    for (int index = 0; index != m_thread_num_; ++index) {
        //新建线程
        Thread *thread_ptr = new Thread(std::bind(&Threadpool::ThreadFunc,this));
        //加入线程池（vector）
        m_threadspool_.push_back(thread_ptr); 
        //启动线程
        thread_ptr->start();
    }
}
 
//结束线程池
void Threadpool::stop() {
    if (m_is_exit_) {
        m_is_exit_ = true;
        std::vector<Thread* >::iterator iter;
        for (iter = m_threadspool_.begin(); iter != m_threadspool_.end(); ++iter) {
            (*iter)->join();
            delete *iter;
        }

        m_threadspool_.clear();
    }
}


//添加任务，参数为任务函数对象
void Threadpool::addTask(Task task) {
    m_buffer_.push(task);
}



//获取任务
Threadpool::Task Threadpool::getTask() {
    return m_buffer_.pop();
}


//传入各线程的函数，即任务区中的函数对象
void Threadpool::ThreadFunc() {
    while (!m_is_exit_) {
        Task task = getTask();
        
        if ( task != NULL ) {
            task();
        }
    }
}

