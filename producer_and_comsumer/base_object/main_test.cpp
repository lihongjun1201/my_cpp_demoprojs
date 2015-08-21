/*************************************************************************
	> File Name: main_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2015 09:43:26 AM PDT
 ************************************************************************/

#include "producer_thread.h"
#include "consumer_thread.h"
#include "buffer.h"

#include<iostream>



int main(void) {
    
    Buffer warehouse(5);

    ThreadBase *p_producer = new ProducerThread(warehouse);

    ThreadBase *p_consumer = new ConsumerThread(warehouse);

    p_producer->start();
    p_consumer->start();

    p_producer->join();
    p_consumer->join();




    return 0;
}
