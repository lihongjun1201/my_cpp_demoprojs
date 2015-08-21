/*************************************************************************
	> File Name: logtest.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Jul 2015 06:08:28 AM PDT
 ************************************************************************/

#define _LOG4CPP_

#include<iostream>
#include "Mylog.h"
#include "func.h"


using namespace std;

int main(void) {
    //Mylog& log = Mylog::getInstance();
    //log.setPriority(ERROR);
    logError("error allen");
    logWarn("warn allen");
    
    func();


    return 0;
}
