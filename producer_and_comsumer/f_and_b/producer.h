/*************************************************************************
	> File Name: producer.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:45:24 AM PDT
 ************************************************************************/

#ifndef _PRODUCER_H
#define _PRODUCER_H

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class Buffer;

class Producer {
 public:
    Producer(Buffer &buff);
    
    void onProduce();  //实现具体的回调函数，即生成任务

    //无需继承线程类，重写虚函数run()了
    //virtual void run() override;  //具体任务
 private:
    Buffer &m_buffer_;
};










#endif
