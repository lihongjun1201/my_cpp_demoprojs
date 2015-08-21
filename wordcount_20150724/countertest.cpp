/*************************************************************************
> File Name: countertest.cpp
> Author: 
> Mail: 
> Created Time: Fri 24 Jul 2015 05:41:23 AM PDT
************************************************************************/

#include<iostream>
#include "word_count.h"
using namespace std;

int main(int argc,char *argv[]) {
    WordStatics word_counter;
    
    cout<<"请输入文件名："<<endl;
    
    string input;
    cin>>input;
    word_counter.open_file(input);
    word_counter.getResult();
    cout<<endl<<"请输入n，可以查看排名前n的单词词频:"<<endl;
    int n;
    cin>>n;

    word_counter.getTopX(n);





    
    


    return 0;
}

