/*************************************************************************
	> File Name: consumer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 02:21:37 AM PDT
 ************************************************************************/

#include "consumer.h"
#include "buffer.h"
#include <unistd.h>
#include <iostream>

//消费者构造函数
Consumer::Consumer(Buffer &buff): m_buff_(buff) {}


//消费者具体任务，每隔2秒从缓冲区中拿走一个整数产品
void Consumer::onConsume() {
    while (1) {
        int product = m_buff_.pop();
        std::cout << "消费者获得一个整数产品：" << product << "\n";
        sleep(2);
    }
}

