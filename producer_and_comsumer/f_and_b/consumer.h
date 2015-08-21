/*************************************************************************
	> File Name: comsumer.h
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 02:17:26 AM PDT
 ************************************************************************/

#ifndef _CONSUMER__H
#define _CONSUMER__H


class Buffer;

class Consumer {
 public:
    Consumer(Buffer &buff);
    void onConsume();  //消费者具体消费行为，回调函数

 private:
    Buffer &m_buff_;
};





#endif
