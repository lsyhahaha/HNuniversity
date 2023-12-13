#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 获取数字的指定位数上的数字
int getDigit(int num, int place) {
    for (int i = 0; i < place - 1; ++i) {
        num /= 10;
    }
    return num % 10;
}

// 获取数字的位数
int getNumDigits(int num) {
    int digits = 0;
    while (num > 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

// 基数排序函数
void radixSort(vector<int>& arr) {
    int maxNum = *max_element(arr.begin(), arr.end());
    int numDigits = getNumDigits(maxNum);

    for (int place = 1; place <= numDigits; ++place) {
        vector<vector<int>> buckets(10);

        // 将数字放入相应的桶中
        for (int i = 0; i < arr.size(); ++i) {
            int digit = getDigit(arr[i], place);
            buckets[digit].push_back(arr[i]);
        }

        // 重新合并桶中的数字
        arr.clear();
        for (int i = 0; i < 10; ++i) {
            arr.insert(arr.end(), buckets[i].begin(), buckets[i].end());
        }
    }
}

int main() {
    // 示例数据
    vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};

    // 输出原始数据
    cout << "Original data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // 进行基数排序
    radixSort(data);

    // 输出排序后的数据
    cout << "Sorted data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
