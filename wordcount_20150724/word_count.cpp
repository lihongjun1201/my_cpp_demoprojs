/*************************************************************************
	> File Name: word_count.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jul 2015 05:13:42 AM PDT
 ************************************************************************/

#include<iostream>
#include "word_count.h"

using namespace std;


//字典树构造函数
TrieTree::TrieTree() {
    root = new TrieNode();
    //词频统计表,记录单词和出现次数
    word_index = 0;
    lines_count = 0;
    all_words_count = 0;
    distinct_words_count = 0;
    words_count_table = new WordHash[30000];
}


//建立字典树，将单词插入字典树
void TrieTree::insert(const char *word) {
    TrieNode *location = root; //遍历字典树的指针
    
    const char *pword = word;

    //插入单词
    while( *word ) {
        if ( location->next_char[ *word - 'a' ] == NULL ) {
            TrieNode *temp = new TrieNode();
            location->next_char[ *word - 'a' ] = temp;
        }    

        location = location->next_char[ *word - 'a' ];
        word++;
    }
    location->count++;
    location->is_word = true; //到达单词末尾
    if ( location->count ==1 ) {
        strcpy(this->words_count_table[word_index++].word,pword);
        distinct_words_count++;
    }
}

//查找字典树中的某个单词
bool TrieTree::search(const char *word) {
    TrieNode *location = root;

    //将要查找的单词没到末尾字母，且字典树遍历指针非空
    while ( *word && location ) {
        location = location->next_char[ *word - 'a' ];
        word++;
    }
    
    this->words_count_table[word_index++].show_times = location->count;
    //在字典树中找到单词，并将其词频记录到词频统计表中
    return (location != NULL && location->is_word);
}

//删除字典树,递归法删除每个节点
void TrieTree::deleteTrieTree(TrieNode *root) {
    int i;
    for( i=0;i<child_num;i++ ) {
        if ( root->next_char[i] != NULL ) {
            deleteTrieTree(root->next_char[i]);
        }
    }
    delete root;
}


//---------------------------------------------------------------

void WordStatics::set_open_filename(string input_path) {
    this->open_filename = input_path;
}

string& WordStatics::get_open_filename() {
    return this->open_filename;
}

void WordStatics::open_file(string filename) {
    set_open_filename(filename);
    cout<<"文件词频统计中...请稍后"<<endl;
    
    fstream fout;
    fout.open(get_open_filename().c_str());  
    
    const char *pstr;
    while (!fout.eof() ) { //将文件单词读取到vector中
        string line,word;
        getline(fout,line);
        dictionary_tree.lines_count++;

        istringstream is(line);  
        while ( is >> word ) {
            pstr = word.c_str();
            dictionary_tree.all_words_count++;
            words.push_back(word);
        }
    } 
    
    //建立字典树
    vector<string>::iterator it;
    for ( it=words.begin();it != words.end();it++ ) {
        if ( isalpha(it[0][0]) ) { 
           dictionary_tree.insert( (*it).c_str() );
        }
    }
    
}
    
  

void WordStatics::getResult() {
    cout<<"文本总行数："<<dictionary_tree.lines_count<<endl;
    cout<<"所有单词的总数 : "<<dictionary_tree.all_words_count-1<<endl;
    cout<<"不重复单词的总数 : "<<dictionary_tree.distinct_words_count<<endl;
    
    //在树中查询不重复单词的出现次数
    dictionary_tree.setZero_wordindex();
    for(int i=0;i<dictionary_tree.distinct_words_count;i++) {
        dictionary_tree.search(dictionary_tree.words_count_table[i].word);
        result_table.push_back(dictionary_tree.words_count_table[i]);
    }
}

bool compare(const WordHash& lhs,const WordHash& rhs) {
    return lhs.show_times > rhs.show_times ;
}

void WordStatics::getTopX(int x) {
    sort(result_table.begin(),result_table.end(),compare);
    cout<<"文本中出现频率最高的前5个单词："<<endl;
    for( int i = 0; i<x; i++) {
        cout<<result_table[i].word<<": "<<result_table[i].show_times<<endl;
    }
}
