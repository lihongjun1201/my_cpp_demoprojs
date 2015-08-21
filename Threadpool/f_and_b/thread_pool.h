/*************************************************************************
	> File Name: thread_pool.h
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Aug 2015 08:14:28 PM PDT
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include "buffer.h"
#include <vector>
#include <functional>

class Thread;


class Threadpool {
 public:
    typedef std::function<void()> Task;

    Threadpool(int bufsize,int threadnum);
    ~Threadpool();

    void start();
    void stop();

    //线程池获取任务，加入任务Buffer,参数为任务回调函数（函数对象）
    void addTask(Task task);    
    Task getTask();

    void ThreadFunc();

 private:
    int m_size_;                            //缓存区大小
    Buffer m_buffer_ ;                      //缓存区
    int m_thread_num_;                      //线程池数量
    std::vector<Thread* > m_threadspool_;   //线程池
    bool m_is_exit_;                        //记录线程是否退出工作
};



#endif
