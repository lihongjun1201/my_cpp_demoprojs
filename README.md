## my_cpp_demoprojs

###1.线程池-Threadpool
封装了Mutex，Condition，Thread等，利用c++11的Function & bind技术 实现了线程池

###2.生产者与消费者-produce_and_consumer
方式一：基于继承，通过继承Thread基类，实现Producer线程子类和Consumer线程子类，
重载各自的基类虚函数run（）即可

方式二：基于function&bind

###3.词频统计-wordcount
封装了Trie字典树，实现词频统计，可以获取TopK的单词。
可以通过其他方式实现：1-stl::map；2-sed & awk等

###4.封装log4cpp-mylog4cpp
简单地对log4cpp进行封装，使用起来更加方便只需简单几步。编译加上 -llog4cpp -lpthread即可。
