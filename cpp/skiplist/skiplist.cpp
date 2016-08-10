//skiplist头文件重要函数实现
//
//@作者：张海波
//@时间：2013-12-17
//@版权：个人所有

#include "skiplist.h"
#include "time.h"
#include <assert.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void DebugOutput(const string& information){
#ifdef Debug
    cout << information << endl;
#endif
}

void SkipList::NewList(){
    //设置NIL结点
    NewNodeWithLevel(0, NIL_);
    NIL_->key = 0x7fffffff;
    //设置链表List
    list_ = (List)malloc(sizeof(listStructure));
    list_->level = 0;
    //设置头结点
    NewNodeWithLevel(MAX_LEVEL,list_->header);
    for(int i = 0; i < MAX_LEVEL; ++i){
        list_->header->forward[i] = NIL_;
    }
    //设置链表元素的数目
    size_ = 0;
}

void SkipList::NewNodeWithLevel(const int& level,
                                Node& node){
    //新结点空间大小
    int total_size = sizeof(nodeStructure) + level*sizeof(Node);
    //申请空间
    node = (Node)malloc(total_size);
    assert(node != NULL);
}

void SkipList::FreeList(){
    Node p = list_->header;
    Node q;
    while(p != NIL_){
        q = p->forward[0];
        free(p);
        p = q;
    }
    free(p);
    free(list_);
}


bool SkipList::Search(const KeyType& key,
                      ValueType& value){
    Node x = list_->header;
    int i;
    for(i = list_->level; i >= 0; --i){
        while(x->forward[i]->key < key){
            x = x->forward[i];
        }
    }
    x = x->forward[0];
    if(x->key == key){
        value = x->value;
        return true;
    }else{
        return false;
    }
}


bool SkipList::Insert(const KeyType& key,
                      const ValueType& value){
    Node update[MAX_LEVEL];
    int i;
    Node x = list_->header;
    //寻找key所要插入的位置
    //保存大约key的位置信息
    for(i = list_->level; i >= 0; --i){
        while(x->forward[i]->key < key){
            x = x->forward[i];
        }

        update[i] = x;
    }

    x = x->forward[0];
    //如果key已经存在
    if(x->key == key){
        x->value = value;
        return false;
    }else{
        //随机生成新结点的层数
        int level = RandomLevel();
        //为了节省空间，采用比当前最大层数加1的策略
        if(level > list_->level){
            level = ++list_->level;
            update[level] = list_->header;
        }
        //申请新的结点
        Node newNode;
        NewNodeWithLevel(level, newNode);
        newNode->key = key;
        newNode->value = value;

        //调整forward指针
        for(int i = level; i >= 0; --i){
            x = update[i];
            newNode->forward[i] = x->forward[i];
            x->forward[i] = newNode;
        }
        
        //更新元素数目
        ++size_;

        return true;
    }
}


bool SkipList::Delete(const KeyType& key,
                      ValueType& value){
    Node update[MAX_LEVEL];
    int i;
    Node x = list_->header;
    //寻找要删除的结点
    for(i = list_->level; i >= 0; --i){
        while(x->forward[i]->key < key){
            x = x->forward[i];
        }

        update[i] = x;
    }

    x = x->forward[0];
    //结点不存在
    if(x->key != key){
        return false;
    }else{
        value = x->value;
        //调整指针
        for(i = 0; i <= list_->level; ++i){
            if(update[i]->forward[i] != x)
                break;
            update[i]->forward[i] = x->forward[i];
        }
        //删除结点
        free(x);
        //更新level的值，有可能会变化，造成空间的浪费
        while(list_->level > 0
            && list_->header->forward[list_->level] == NIL_){
            --list_->level;
        }
        
        //更新链表元素数目
        --size_;

        return true;
    }
}


int SkipList::RandomLevel(){   
    int level = static_cast<int>(rnd_.Uniform(MAX_LEVEL));
    if(level == 0){
        level = 1;
    }
    //cout << level << endl;
    return level;
}

int SkipList::GetCurrentLevel(){
    return list_->level;
}
