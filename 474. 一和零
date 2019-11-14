/*
在计算机界中，我们总是追求用有限的资源获取最大的收益。

现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。

你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:

给定 0 和 1 的数量都不会超过 100。
给定字符串数组的长度不会超过 600。
示例 1:

输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
输出: 4

解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
示例 2:

输入: Array = {"10", "0", "1"}, m = 1, n = 1
输出: 2

解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
*/

#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
void calcZeroAndOne(char* str, int* zero, int* one)
{
    *zero = 0;
    *one = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == '0') {
            (*zero)++;
        }
        if(str[i] == '1') {
            (*one)++;
        }
    }
}

int findMaxForm(char ** strs, int strsSize, int m, int n){
    if(strsSize == 0 || strs == NULL) {
        return 0;
    }

    int** dp = (int**)malloc(sizeof(int*) * (m + 1));
    for(int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
        memset(dp[i], 0, sizeof(int) * (n + 1));
    }

    //dp[i][j]表示在容量为i个0，j个1的背包里，最多容纳的字符串种类数，zero表示该字符串中0的数量，one表示1的数量。
    //dp[i][j] = MAX(dp[i - zero][j - one], dp[i][j]);
    for(int k = 0; k < strsSize; k++) {
        int zero = 0;
        int one = 0;
        calcZeroAndOne(strs[k], &zero, &one);
        //printf("[%d-%d]\n", zero, one);     
        for(int i = m; i >= 0; i--) {
            for(int j = n; j >= 0; j--) {
                if(i - zero >= 0 && j - one >= 0) {
                    dp[i][j] = MAX(dp[i - zero][j - one] + 1, dp[i][j]);
                }
            }
        }
    }
    /*
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            printf("%d  ", dp[i][j]);
        }
        printf("\n");
    }*/
    return dp[m][n];
}

int main()
{
    int strsSize = 5;
    char** strs = (char**)malloc(sizeof(char*) * strsSize);
    for(int i = 0; i < strsSize; i++) {
        strs[i] = (char*)malloc(sizeof(char) * 20);
    }
    strs[0] = "10";
    strs[1] = "0001";
    strs[2] = "111001";
    strs[3] = "1";
    strs[4] = "0";

    int m = 5;
    int n = 3;
    printf("res = %d", findMaxForm(strs, strsSize, m, n));
    return 0;
}
