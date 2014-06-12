#include <stdio.h>  
#include <math.h>  
#define MAX_NUM 31  
  
int haha(int a, int b) {
    return a > b ? a-b : b-a;
}

int main()  
{  
    int n;  
    int i;  
    int arr_[MAX_NUM];  
    int num_;  
    int count_odd;  
    int count_even;  
      
    scanf("%d",&n);  
      
    while (n--)  
    {  
        scanf("%d", &num_);  
        for (i=0; i<num_; i++)  
        {  
            scanf("%d", &arr_[i]);  
        }  
        if (num_ % 2 == 1)  
        {  
            printf("YES\n");  
        }  
        else  
        {  
            count_even = 0;  
            count_odd = 0;  
            for (i=0; i<num_; i++)  
            {  
                if (arr_[i] == 1)  
                {  
                    if (i % 2)  
                    {  
                        count_odd++;  
                    }  
                    else  
                        count_even++;  
                }  
                  
            }  
            if ( haha(count_even, count_odd) <= 1 )  
            {  
                printf("YES\n");  
            }  
            else  
            {  
                printf("NO\n");  
            }  
        }          
    }  
      
    return 0;  
}  
