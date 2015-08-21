/*************************************************************************
	> File Name: producer.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2015 02:06:02 AM PDT
 ************************************************************************/


#include "producer.h"
#include "buffer.h"
#include <iostream>


//生成者构造函数
Producer::Producer(Buffer &buff): m_buffer_(buff){}


//实现回调函数，具体生产任务
//每秒产生一个整数产品
void Producer::onProduce()
{
    srand(time(NULL));
    while (1) {
        int product = rand() % 100;
        m_buffer_.push(product);
        std::cout << "生产者生成出了一个整数商品:" << product <<"\n";
        sleep(1);
    }
}
