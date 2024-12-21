#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int maxAbsoluteDifference(const vector<int>& arr) {
    // 初始化最大值和最小值
    int maxVal = numeric_limits<int>::min();
    int minVal = numeric_limits<int>::max();

    // 遍历数组找到最大值和最小值
    for (int num : arr) {
        if (num > maxVal) maxVal = num;
        if (num < minVal) minVal = num;
    }

    // 计算最大差的绝对值
    return abs(maxVal - minVal);
}

int main() {
    vector<int> arr = {2, 5, 1, 9, 7, 3}; // 示例数组
    int result = maxAbsoluteDifference(arr);
    cout << "最大绝对值差是: " << result << endl; // 输出结果
    return 0;
}
