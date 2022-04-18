#include <stdio.h>
#include <string.h>

int BracketsMatch(const char *strBrackets){
    if (strBrackets == NULL)    //空 没有括号 所以不匹配
        return 0;
    
    int i = 0;
    int nCount = 0;

    while (i < strlen(strBrackets)) {
        //计 ( 的数量
        if (strBrackets[i] == '(') {
            nCount++;
        }else if (strBrackets[i] == ')'){
            //遇到 )与左括号进行匹配 抵消一个
            nCount--;
            //左括号少于右括号 匹配不成功
            if (nCount < 0) {
                return 0;
            }
        } 
        //遍历下一个括号
        i++;
    }
    //左括号数量是否多于右括号
    return nCount > 0 ? 0 : 1;  
                //如果大于0则不匹配(0)，否则匹配(1)
}

int main()
{
    int nResult = BracketsMatch("()()()((()))");
    printf("%d\n",nResult);
    return 0;
} 