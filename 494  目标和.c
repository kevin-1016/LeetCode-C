/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>

int count;
void dfs(int* nums, int numsSize, int S, int index, int sum)
{
    if(index == numsSize) {
        if(sum == S) {
            count++;
        }
        return;
    }

    dfs(nums, numsSize, S, index + 1, sum + nums[index]);
    dfs(nums, numsSize, S, index + 1, sum - nums[index]);
}

int findTargetSumWays(int* nums, int numsSize, int S){
    if(numsSize == 0 || nums == NULL) {
        return 0;
    }

    count = 0;
    dfs(nums, numsSize, S, 0, 0);
    return count;
}

int main()
{
    int num[5] = {1,1,1,1,1};
    printf("res = %d", findTargetSumWays(&num, 5, 3));
    return 0;
}
