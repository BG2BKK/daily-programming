//跳表实现
//
//参考文章为：Skip lists: a probabilistic alternative to balanced trees
//
//提供如下接口：
//   Search：搜索给定key的值
//   Insert：插入指定的key及value
//   Delete：删除指定的key
//
//@作者： 张海波
//@时间： 2013-12-17
//@版权： 个人所有
//

#include <stddef.h>
#include "random.h"

//定义调试开关
#define Debug

//最大层数
const int MAX_LEVEL = 16;

//定义key和value的类型
typedef int KeyType;
typedef int ValueType;
	
//定义结点
typedef struct nodeStructure* Node;
struct nodeStructure{
	KeyType key;
	ValueType value;
	Node forward[1];
};
	
//定义跳跃表
typedef struct listStructure* List;
struct listStructure{
	int level;
	Node header;
};

class SkipList{
public:
    //初始化表结构
    SkipList():rnd_(0xdeadbeef)
    { NewList(); }
    
    //释放内存空间
    ~SkipList(){ FreeList(); }

    //搜索key，保存结果至value
    //找到，返回true
    //未找到，返回false
    bool Search(const KeyType& key,
                ValueType& value);

    //插入key和value
    bool Insert(const KeyType& key,
                const ValueType& value);

    //删除key,保存结果至value
    //删除成功返回true
    //未删除成功返回false
    bool Delete(const KeyType& key,
                ValueType& value);

    //链表包含元素的数目
    int size(){ return size_; }

    //打印当前最大的level
    int GetCurrentLevel();
private:
    //初始化表
    void NewList();

    //释放表
    void FreeList();
    
    //创建一个新的结点，结点的层数为level
    void NewNodeWithLevel(const int& level,
                          Node& node);

    //随机生成一个level
    int RandomLevel();
private:		
    List list_;
    Node NIL_;
    //链表中包含元素的数目
    size_t size_;
    //随机器生成器
    Random rnd_;
};

