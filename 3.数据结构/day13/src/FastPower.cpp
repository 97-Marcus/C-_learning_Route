#include <stdio.h>

int FastPower(int nNum,int n){
    if (n == 0) return 1;
    if (n == 1) return nNum;
    
    if (n%2 == 1) {     //奇数
        return nNum*FastPower(nNum,n-1);
    }else {             //偶数
        int nValue = FastPower(nNum, n/2);
        return nValue*nValue;
    }
}

int main(){
    int nResult = FastPower(2, 7);
    printf("%d\n",nResult);
    return 0;
}