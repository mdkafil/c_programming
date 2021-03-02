#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[10];
	int marks[4];
};

int main()
{
	FILE *fp = fopen("1.txt", "r");
	struct student a[10];
	int i=0;
	printf("Student details...\n");
	while(!feof(fp)	)
	{
		fscanf(fp, "%s", a[i].name);
		for(int j=0; j<4; j++)
		{
			fscanf(fp, "%d", &a[i].marks[j]);
		}
		printf("%s\n",a[i].name);
		for(int j=0; j<4; j++)
		{
			printf("%d\n",a[i].marks[j]);
		}
		i++;
	}
	fclose(fp);
	
	return 0;
}