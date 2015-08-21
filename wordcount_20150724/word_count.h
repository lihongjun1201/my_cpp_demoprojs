/*************************************************************************
	> File Name: word_count.h
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jul 2015 04:43:27 AM PDT
 ************************************************************************/

#ifndef _WORD_COUNT_H
#define _WORD_COUNT_H

#include<stdio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>

using std::string;
using std::vector;

typedef struct tag {
    char word[50];  //单个单nt show_times; //出现次数
    int show_times; //出现次数
}WordHash;

const int child_num = 26;

//字典树节点
typedef struct Trie {
    int count;
    struct Trie *next_char[child_num];
    bool is_word;
 
    //节点构造函数
    Trie(): is_word(false) {
        memset(next_char,NULL,sizeof(next_char));
    }
}TrieNode;

class TrieTree {
 public:
    TrieTree();
    void insert(const char *word);
    bool search(const char *word);
    void deleteTrieTree(TrieNode *root);
    inline void setZero_wordindex(){ word_index = 0; }

    int word_index;
    WordHash *words_count_table; //词频统计表
    int lines_count;
    int all_words_count; //单词总数
    int distinct_words_count;  //不重复单词数

 private:
    TrieNode *root; //字典树根节点
};

//文本词频统计类
class WordStatics {
 public:
    void open_file(string filename);
    void write_file();

    void set_open_filename(string input_path);
    string& get_open_filename();

    void getResult();
    void getTopX(int x);

 private:
    vector<string> words;  //保存文本中所有单词
    TrieTree dictionary_tree; //字典树
    
    vector<WordHash> result_table; //结果词频表
    string open_filename; //将要处理的文本路径
    string write_filename; //词频统计结果文件
};



#endif
