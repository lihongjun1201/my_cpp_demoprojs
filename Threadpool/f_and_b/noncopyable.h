/*************************************************************************
	> File Name: noncopyable.h
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Aug 2015 09:40:11 AM PDT
 ************************************************************************/

#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

//不可复制的基类
//供有不可复制要求的子类继承

class Noncopyable {
 protected:
    Noncopyable(){}

 private:
    Noncopyable(const Noncopyable &rhs);
    Noncopyable& operator= (const Noncopyable &rhs);
};




#endif
