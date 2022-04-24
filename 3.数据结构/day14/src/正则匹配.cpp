#include <stdio.h>

int RegularMatching(const char *p1,int len1,const char *p2,int len2,int start1,int start2)
{
	if((start1 > len1) && (start2 > len2))
		return 1;

	while(1)
	{
		if(p2[start2 + 1] != '*')
		{
			if((p2[start2] == p1[start1])||p2[start2] == '.'){
				return RegularMatching(p1,len1,p2,len2,start1 + 1,start2 + 1);
			}
			else{
				return 0;
			}
		}
		else if(p2[start2 + 1] == '*')
		{
			if((p2[start2] == p1[start1])||p2[start2] == '.'){
				return (RegularMatching(p1,len1,p2,len2,start1,start2 + 2)||
                        RegularMatching(p1,len1,p2,len2,start1 + 1,start2 + 2)||
                        RegularMatching(p1,len1,p2,len2,start1 + 1,start2));
			}
			else{
				start2 += 2;
				return RegularMatching(p1,len1,p2,len2,start1,start2);
			}
		}
	}
}

int main(){
    char p1[] = "abbcd";
	char p2[] = "a*.*cd*";
    int answer = RegularMatching(p1,sizeof(p1)/sizeof(p1[0])-1,p2,sizeof(p2)/sizeof(p2[0])-1,0,0);
    if (answer == 0) {
        printf("匹配失败~");
    }else 
        printf("匹配成功~");
    return 0;
}