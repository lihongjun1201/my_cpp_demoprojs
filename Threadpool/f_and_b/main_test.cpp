/*************************************************************************
	> File Name: main_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Aug 2015 11:59:16 PM PDT
 ************************************************************************/

#include "thread_pool.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>


//具体任务，函数对象
struct MyTask {
    void operator()()
    {
        srand(time(NULL));
        int num = rand() % 100;
        std::cout << "随机生成一个整数" << num <<"\n";
        sleep(2);
    }
};


int main(void) {
    Threadpool thread_pool(5,4);
    thread_pool.start();

    MyTask task;
    while (1) {
        thread_pool.addTask(task);
        sleep(1);
    }

    thread_pool.stop();

    return 0;
}
