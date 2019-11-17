#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    if(len == 0) {
        return 0;
    }

    int table[256] = {-1}; //重复的字母的下标，如果当前字母下标>0，则该字母已经出现过，需要回退到这个字母出现的下一个位置重新搜索
    int left = 0;
    int right = 0;
    int res = 0;

    memset(table, -1, sizeof(int) * 256);
    while(right < len) {
        if(table[s[right]] == -1) {
            table[s[right]] = right;
            right++;
            res = MAX(res, right - left);
            //printf("[%d-%d]", left, right);
        } else { 
            //printf("[new start:%d]", table[s[right]]);
            left = table[s[right]] + 1;
            right = left;          
            memset(table, -1, sizeof(int) * 256);
        }
    }
    return res;
}

int main()
{
    printf("res = %d", lengthOfLongestSubstring("abcabcabc"));
    return 0;
}
