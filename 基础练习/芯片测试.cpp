#include<stdio.h>
int main()
{
    int n,i,j,count;
    int a[25][25];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(j=0;j<n;j++)
    {
        count=0;
        for(i=0;i<n;i++)
        {
            count+=a[i][j];   //统计每一列的测试结果，即一个芯片经过所有芯片的测试，得到的结果统计 
        }
        if(count>n/2)
        {
            printf("%d ",j+1);
        } 
    }
    return 0;
}