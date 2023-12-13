#include <iostream>
#include <vector>

using namespace std;

// 查找目标值在有序数组中的范围
vector<int> searchRange(int target, const vector<int>& arr) {
    int start = -1;
    int end = -1;

    // 查找起始位置
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            start = mid; // 更新起始位置
            high = mid - 1; // 继续在左侧查找
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // 查找结束位置
    low = 0;
    high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            end = mid; // 更新结束位置
            low = mid + 1; // 继续在右侧查找
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {start, end};
}

int main() {
    // 示例：创建一个有序数组
    vector<int> arr = {1, 2, 2, 2, 2, 4, 4, 5};

    // 在有序数组中查找目标值的范围
    int target = 2;
    vector<int> result = searchRange(target, arr);

    if (result[0] != -1) {
        cout << "Target " << target << " found in the range [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "Target " << target << " not found in the array" << endl;
    }

    return 0;
}
