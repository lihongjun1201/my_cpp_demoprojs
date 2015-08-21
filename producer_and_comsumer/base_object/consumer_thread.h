/*************************************************************************
	> File Name: comsumer_thread.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 02:17:26 AM PDT
 ************************************************************************/

#ifndef _CONSUMER_THREAD_H
#define _CONSUMER_THREAD_H

#include "thread_base.h"

class Buffer;

class ConsumerThread: public ThreadBase {
 public:
    ConsumerThread(Buffer &buff);
    virtual void run() override;
 private:
    Buffer &m_buff_;
};





#endif
