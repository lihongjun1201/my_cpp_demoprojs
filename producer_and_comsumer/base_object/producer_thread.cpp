/*************************************************************************
	> File Name: producer_thread.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 02:06:02 AM PDT
 ************************************************************************/


#include "producer_thread.h"
#include "buffer.h"
#include <iostream>


//生成者构造函数
ProducerThread::ProducerThread(Buffer &buff): m_buffer_(buff){}


//生成者具体任务，每隔1秒产出一个整数
void ProducerThread::run() {
    srand(time(NULL));
    while (1) {
        int product = rand() % 100;
        m_buffer_.push(product);
        std::cout << "生产者产出了一个整数:" << product <<"\n";
        sleep(1);
    }
}

