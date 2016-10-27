#include "stdio.h"
#include "stdlib.h"

typedef void (*state_ret)(int event);
typedef state_ret (*state)(int event);

// 申明状态函数
state_ret STATE1(int event);
state_ret STATE2(int event);
state_ret STATE3(int event);

// 事件列表
enum EVENT_NUM{
  EVENT1,
  EVENT2,
  EVENT3,
  EVENT4,
};

int main(void)
{
  int event;
  int i = 0;
  
  // 初始状态设置为STATE1
  state curState;
  curState = STATE1;
  while(1){
    
    // 每次循环改变一次event值，实际中一般由外部事件驱动
    switch(i%5){
      case 0: event = EVENT1; break;
      case 1: event = EVENT2; break;
      case 2: event = EVENT3; break;
      case 3: event = EVENT4; break;
      case 4: event = EVENT2; break;
      default: break;
    }

    // 运行当前状态函数，返回下一状态函数指针，并保存起来
    curState = (state)curState(event);
    i++;
  }
  return 0;
}

// 状态1函数的实现
state_ret STATE1(int event)
{
  // 设置当前状态
  state_ret curState = (state_ret)STATE1;

  // 根据event确定下一状态
  switch(event){
    case EVENT1: curState = (state_ret)STATE2; break;
    case EVENT3: curState = (state_ret)STATE3; break;
    default: break;
  }

  // 返回下一状态函数指针
  return curState;
}

// 状态2函数实现
state_ret STATE2(int event)
{
  state_ret curState = (state_ret)STATE2;
  switch(event){
    case EVENT2: curState = (state_ret)STATE1; break;
    default: break;
  }
  return curState;
}

// 状态3函数实现
state_ret STATE3(int event)
{
  state_ret curState = (state_ret)STATE3;
  switch(event){
    case EVENT4: curState = (state_ret)STATE2; break;
    default: break;
  }
  return curState;
}


