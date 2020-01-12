#include <stdio.h>
#include <stdlib.h>
#define N 7
//函数dayin:打印数组元素
void dayin(int array[], int max)    //max为数组元素最大值
{
 
    for(int i = 0; i < max; i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");
}
//函数swap交换两个数   c++里函数库有这个函数 可以直接写
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*quicksort 快速排序算法
对数组arr[low...high]进行快速排序，
首先进行分割操作，返回中轴元素下标 j，
然后对左数组arr[low...j-1] 和 右数组arr[j+1...high]分别递归进行排序
递归终止当然是数组大小为小于等于1（0或1）时*/
void quicksort(int array[], int max, int low, int high)
{
    int i, j;
 
    if(low < high)
    {
        //int v = array[low];     //中轴元素v
        i = low + 1;            // array[low]作为基准数(一般第一个)，从array[begin+1]开始与基准数比较
        j = high;               // array[high]是数组的最后一位
        while(i < j)
        {
            if(array[i] > array[low])  // 如果比较的数组元素大于基准数，则交换位置。
            {
                swap(&array[i], &array[j]);  // 交换两个数
                j--;
            }
            else
            {
                i++;                    // 将数组向后移一位，继续与基准数比较。
            }
        }
 
/* 跳出while循环后，i = j。
 * 然后就是分割操作了
 * 这个时候将数组array分成两个部分，再将array[i]与array[low]进行比较，决定array[i]的位置。
 * 最后将array[i]与array[high]交换，进行两个分割部分的排序！退出条件不满足i = j
 */
        if(array[i] >= array[low])  // 取等>=
        {
            i--;
        }
 
        swap(&array[low], &array[i]);
 
        quicksort(array, max, low, i);
        quicksort(array, max, j, high);
    }
}
// 主函数
int main()
{
    int array[N] = {5,2,4,3,8,7,9,};
    int max = N;
 
    printf("排序前的数组\n");
    dayin(array, max);
 
    quicksort(array, max, 0, max-1);  // 快速排序
 
    printf("排序后的数组\n");
    dayin(array, max);
 
    return 0;
}
