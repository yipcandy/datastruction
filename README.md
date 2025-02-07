# 简单数据结构实现

这是一个用C++类实现的简单数据结构的示例项目。

## 简介

本项目展示了如何使用C++类来实现基本的数据结构。数据结构是计算机科学中的基础概念，用于组织和存储数据，以便高效地进行访问和修改。

可供初学c++和数据结构的用户参考，mubstree 代码风格统一。

## 数据结构

本项目实现了以下数据结构：

1. **链表**：一种线性数据结构，其中每个元素包含一个指向下一个元素的指针。
2. **栈**：一种后进先出（LIFO）的数据结构，支持在一端进行插入和删除操作。
3. **队列**：一种先进先出（FIFO）的数据结构，支持在两端进行插入和删除操作。

## 特性

- **链表**：
  - 插入元素
  - 删除元素
  - 遍历元素

- **栈**：
  - 压栈（push）
  - 出栈（pop）
  - 获取栈顶元素

- **队列**：
  - 入队（enqueue）
  - 出队（dequeue）
  - 获取队首元素

## 安装与使用

建议直接下载安装包。

## 示例代码

以下是如何使用这些数据结构的示例代码：

```cpp
#include <iostream>
#include "mylist.h"
#include "Stack.h"
#include "myloopqueue.h"

int main() {
    // 链表示例
    SingleList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.print(); // 输出: 1 2 3

    // 栈示例
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.top() << std::endl; // 输出: 3
    stack.pop();
    std::cout << stack.top() << std::endl; // 输出: 2

    // 队列示例
    CLoopQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << queue.front() << std::endl; // 输出: 1
    queue.dequeue();
    std::cout << queue.front() << std::endl; // 输出: 2

    return 0;
}
```

## 贡献

欢迎贡献！请 fork 本仓库并提交 pull request。