// 堆排序
#include <iostream>
using namespace std;

void HeadAdjust(int A[], int k, int len);

// 建立大根堆
void BuildMaxHeap(int A[], int len) {
    for (int i = len / 2; i > 0; i--) {
        HeadAdjust(A, i, len);
    }
}

// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
    A[0] = A[k];                             // A[0]暂存子树的根结点
    for (int i = 2 * k; i <= len; i *= 2) {  // 沿key较大的子结点向下筛选
        if (i < len && A[i] < A[i + 1]) {
            i++;  // 取key子结点较大者的下标
        }
        if (A[0] >= A[i]) {
            break;  // 根key比子结点下标都大，无须调整
        } else {
            A[k] = A[i];  // 将A[i]调整到双亲结点上
            k = i;        // 修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0];  // 被筛选结点的值放入最终位置
}

/**
 * 堆排序完整逻辑
 **/

// 对长为len的数组A，进行排序
void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len);            // 初始建堆
    for (int i = len; i > 1; i--) {  // n-1趟交换和建堆过程
        swap(A[i], A[1]);            // 将堆顶元素和堆底元素交换
        printf("第%d次堆排序：", len - i + 1);
        for(int i = 1; i <= len; i++) cout << A[i] << " ";
        cout << endl;

        HeadAdjust(A, 1, i - 1);     // 把剩余的待排序元素整理成
    }
}

int main(){
    int A[] = {-1, 46, 74, 53, 14, 26, 38, 86, 65, 27, 34};

    HeapSort(A, 10);  // 注意：这个代码下标从1开始，0号位置元素取任意值即可，10为元素个数
    return 0;
}