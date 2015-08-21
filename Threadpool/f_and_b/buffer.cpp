/*************************************************************************
	> File Name: buffer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:06:49 AM PDT
 ************************************************************************/

#include "buffer.h"


//缓存区构造函数（条件变量非满/非空的构造需要传入互斥锁mutex）
Buffer::Buffer(int size):
    m_mutex_(),
    m_notfull(m_mutex_),
    m_notempty(m_mutex_),
    m_size_(size) 
{}



//判空
bool Buffer::isEmpty() {
    return (m_queue_.size() == 0);
}

//判满
bool Buffer::isFull() {
    return (m_queue_.size() == m_size_);
}


//加入产品
void Buffer::push(Task task) {
    MutexLockGuard guard(m_mutex_);   //加锁 (栈对象自动销毁，即自动解锁)
    while(isFull()) //满则等待 不满条件成立
        m_notfull.wait();

    m_queue_.push(task);  //将产品加入缓冲区
    
    m_notempty.notify();    //缓冲区有产品了，通知非空条件变量成立
}

//取走消费产品
Buffer::Task Buffer::pop() {
    MutexLockGuard guard(m_mutex_); //上锁
    while(isEmpty())       //若无产品，则等待非空条件成立
        m_notempty.wait();

    Task task = m_queue_.front();  //从缓冲队列中取出商品
    m_queue_.pop();

    m_notfull.notify();  //缓冲区中有空闲位置了，通知非满条件变量成立

    return task;
}
