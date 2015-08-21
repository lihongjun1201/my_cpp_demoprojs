/*************************************************************************
	> File Name: producer_thread.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 01:45:24 AM PDT
 ************************************************************************/

#ifndef _PRODUCER_THREAD_H
#define _PRODUCER_THREAD_H

#include "thread_base.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class Buffer;

class ProducerThread: public ThreadBase {
 public:
    ProducerThread(Buffer &buff);
    virtual void run() override;  //具体任务
 private:
    Buffer &m_buffer_;
};










#endif
