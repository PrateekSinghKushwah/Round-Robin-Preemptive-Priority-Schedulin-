#include<stdio.h>
#include<String.h>

struct s1{
	char first[50];
	int second;
};

struct s{
	int first;
	int burst1;
	struct s1 s2;
};

struct ans{
	char first[100];
	int arrival;
	int burst2;
	int second;
};
int main()
{
	int size;
	printf("Enter The Number Of Processes : ");
	scanf("%d",&size);
	int size1 = size;
	struct s a[size];
	struct ans a1[size];
	int priority[size]; int burst[size];
	int i;
	for(i=0;i<size;i++)
	{
		printf("\nEnter Arrival Time Of Process %d : ",i+1);
		scanf("%d",&a[i].first);
		printf("Enter Name Of Process %d : ",i+1);
		scanf("%s",&a[i].s2.first);
		printf("Enter Burst Time Of Process %d : ",i+1);
		scanf("%d",&a[i].s2.second);
		a[i].burst1=a[i].s2.second; 
		printf("Enter Priority Of Process %d : ",i+1);
		scanf("%d",&priority[i]);
	}
	printf("\n");
	int j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			struct s temp;
			if(a[i].first==a[j].first)
			{
				if(priority[i]<priority[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			
			else if((a[i].first)>(a[j].first))
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	int time = 2; int k = 0; signed int l=0;
	while(size>0)
	{
		if(a[0].s2.second-time<=0)
		{
			
			k = k + a[0].s2.second;
			strcpy(a1[l].first,a[0].s2.first);
			a1[l].second = k;
			a1[l].arrival = a[0].first;
			a1[l].burst2 = a[0].burst1;
			l=l+1;
			struct s temp;
		    for(i=0;i<size-1;i++)
	        {
		      temp = a[i];
		      a[i] = a[i+1];
		      a[i+1] = temp;
	        }
	        size = size-1;
		}
		
		else
		{
			k = k + time;
			a[0].s2.second = a[0].s2.second - time;
		struct s temp;
		struct s temp1 = a[0];
	    for(i=0;i<size-1;i++)
	    {
		temp = a[i];
		a[i] = a[i+1];
		a[i+1] = temp;
	    }
	    size = size-1;
	    a[size] = temp1;
	    ++size;
		}
	}
printf("Arrival Time\t Process\t Completion Time\t Turn Around Time\t Waiting Time\n");
	float avgtat=0; float avgwt=0;
	for(i=0;i<size1;i++)
	{
		printf("     %d\t ",a1[i].arrival);
		printf("\t  %s\t",a1[i].first);
		printf("\t   %d ms ",a1[i].second);
		printf("\t\t    %d\t ",a1[i].second-a1[i].arrival);
		avgtat = avgtat + a1[i].second-a1[i].arrival;
		printf("\t\t    %d \n",(a1[i].second-a1[i].arrival)-(a1[i].burst2));
		avgwt = avgwt + a1[i].second - a1[i].arrival - a1[i].burst2;
	}
	
	printf("\n\n");
	printf("Average Turn Around Time Is - %f\n", avgtat/(size1*1.0));
	printf("Average Waiting Time Time Is - %f", avgwt/(size1*1.0));
}
