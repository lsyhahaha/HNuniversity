#include <iostream>
using namespace std;
 
void InsertSort(int A[],int n){ //n是数组长度
	int i,j,low ,high,mid;
	for(i =2;i<=n;i++){           //i是从待排序序列中拿出来的数值。	依次将A[2]~A[n]插入前面的已排序序列（注意这里是从2开始，这里是用哨兵的方法）
		A[0]=A[i];             //A[0]处暂时存放A[i]
		low=1;high=i-1;         //设值折半查找的范围（默认递增有序）
		//用一个while循坏，用折半查找方法查找插入位置
		while(low<=high){
			mid=(low+high)/2; //取中间点
			if(A[0]<A[mid]) high=mid-1; //查找左半子表（记忆：先左后右）
			else low=mid+1; //查找右半子表。
		} //重点：最终,high指向了小于等于A[0]的位置。
		//把high后的元素统一后移
		for(j = i-1;j>=high+1;j--){
			A[j+1]=A[j];//统一后移元素，空出插入位置
		}
		//把A[0]插入high+1处
		A[high+1]=A[0];	
	}
}
 
int main()
{   
	//1 建立一个原始的乱序的数组
    system("chcp 65001");
	int A[]={0,7,9,2,1};//0第一个元素作为哨兵没有用处
	printf("排序之前： \n");
	int len_1=sizeof(A)/sizeof(0);//得到数组的长度
	int m;
	for(m=1;m<len_1;m++){ //第一个元素（也就是数组下标为0），只是作为哨兵，所以不打印
		printf("%d",A[m]);
	}
	printf("\n");
	
	//2 调用插入排序方法
	InsertSort(A,4);
	
	//3 校验是否排序成功
	printf("排序之后： \n");
	int n;
	for(n=1;n<5;n++){
		printf("%d",A[n]);
	}
	return 0;
	
}