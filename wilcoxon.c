#include<stdio.h>
void test(int t_cal,int t_table)
{
    if(t_cal>t_table)
    {
        printf("The Null hypothesis is accepted");
    }
    if(t_cal<t_table)
    {
        printf("The Null hypothesis is rejected");
    }
}
int min(int t_plus,int t_minus)
{
    if(t_plus>t_minus)
    {
        return t_plus;
    }
    if(t_plus<t_minus)
    {
        return t_minus;
    }
}
void calculateRanks(int n, int diff[], int ranks[]) {
    int i, j, count;
    int temp[n];

    for (i = 0; i < n; i++) {
        ranks[i] = 1;
        temp[i] = 0;
    }

    for (i = 0; i < n - 1; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (diff[i] > diff[j])
                ranks[i]++;
            else if (diff[i] < diff[j])
                ranks[j]++;
            else
                count++;
        }
        if (count > 1) {
            for (j = i; j < n; j++) {
                if (diff[i] == diff[j])
                    temp[j] = ranks[i];
            }
            for (j = i; j < n; j++) {
                if (temp[j] != 0)
                    ranks[j] = temp[j];
            }
        }
    }
}
int main()
{
    int a[20],b[20],diff[20],ModDiff[20];
    int ranks[20],r_plus[20],r_minus[20];
    int i,n,t_plus=0,t_minus=0,t_cal,t_table;
    printf("Enter the number of readings:");
    scanf("%d",&n);
    printf("Enter the observations of first column:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the observations of second column:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        diff[i]=a[i]-b[i];
    }
    for(i=0;i<n;i++)
    {
        if(diff[i]<0)
        {
            ModDiff[i]=diff[i]-2*diff[i];
        }
        if(diff[i]>0)
        {
            ModDiff[i]=diff[i];
        }
    }
     calculateRanks(n, diff, ranks);
for(i=0;i<n;i++)
{
    if(diff[i]>0)
    {
        r_plus[i]=ranks[i];
        t_plus +=r_plus[i];
    }
    else if(diff[i]<0)
    {
        r_minus[i]=ranks[i];
        t_minus +=r_minus[i];
    }
}
    t_cal=min(t_plus,t_minus);
    printf("Enter the table value:");
    scanf("%d",&t_table);
    test(t_cal,t_table);
    
    return 0;
}