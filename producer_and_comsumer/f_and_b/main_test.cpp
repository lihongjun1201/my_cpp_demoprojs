/*************************************************************************
	> File Name: main_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2015 09:43:26 AM PDT
 ************************************************************************/

#include "producer.h"
#include "consumer.h"
#include "buffer.h"
#include "thread.h"

#include<iostream>


int main(void) {
    
    Buffer warehouse(5);  //商品仓库，容量为5

    Producer producer(warehouse);
    Consumer consumer(warehouse);

    //生产者线程对象接受生成者对象所实现的回调函数，即具体的生产动作
    Thread *p_producer = new Thread(std::bind(&Producer::onProduce,producer));
    
    //消费者线程对象接受消费者对象所实现的回调函数，即具体的消费行为
    Thread *p_consumer = new Thread(std::bind(&Consumer::onConsume,consumer));
    
    
    //分别执行线程
    p_producer->start();
    p_consumer->start();

    p_producer->join();
    p_consumer->join();




    return 0;
}
