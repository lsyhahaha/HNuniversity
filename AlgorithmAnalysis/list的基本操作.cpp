#include <iostream>
#include <list>

int main() {
    // 创建一个空的 list
    std::list<int> myList;

    // 在 list 尾部插入元素
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    // 在 list 头部插入元素
    myList.push_front(0);

    // 迭代器遍历 list
    std::cout << "List elements: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 在指定位置插入元素
    auto insertPos = std::find(myList.begin(), myList.end(), 2);
    if (insertPos != myList.end()) {
        myList.insert(insertPos, 99);
    }

    // 删除指定元素
    myList.remove(3);

    // 删除第一个元素
    myList.pop_front();

    // 删除最后一个元素
    myList.pop_back();

    // 修改指定位置的元素
    auto modifyPos = std::find(myList.begin(), myList.end(), 99);
    if (modifyPos != myList.end()) {
        *modifyPos = 100;
    }

    // 检查是否为空
    if (myList.empty()) {
        std::cout << "List is empty." << std::endl;
    } else {
        std::cout << "List size: " << myList.size() << std::endl;
    }

    // 清空 list
    myList.clear();

    return 0;
}
