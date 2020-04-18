#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int getSize(char* s)
{
    char * t; // first copy the pointer to not change the original
    int size = 0;

    for (t = s; *t != '\0'; t++)
		{
        size++;
    }
    return size;
}

int convertInt(char* s)
{
	char *str=s;
	int size=getSize(s);
	int num=0;
	for(int i=0;i<size;i++)
	{
		int temp=str[i]-'0';
		num=num*10+temp;
	}
	return num;
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2;  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
} 

/****************************************************************/

// checks table name validity
bool tableValidity(char* tablename)
{
	FILE* fp=fopen("tables/tablenames.txt","r");
	char s[1000];
	fgets(s,1000,fp);
	char comma[]=",";
	sscanf(s,"%[^\n]comma",s);
	char table[100];
	memset(table,0,100);
	sprintf(table,"%s.csv",tablename);
	char* token=strtok(s,comma);
	while(token!=NULL)
	{
		if(strcmp(token,table)==0)
		{
			return true;
		}
		token=strtok(NULL,comma);
	}
	fclose(fp);
	return false;
}

// returns -1 if attribute/table does not exist, returns index if it exists and index numer
int checkAttributeValidity(char* attribute,char* tablename)
{
	if(!tableValidity(tablename))
	{
		return -1;
	}

	char table[100];
	memset(table,0,sizeof(table));
	sprintf(table,"tables/%s.csv",tablename);
	FILE* fp=fopen(table,"r");
	char s[1000];
	char comma[]=",";
	fgets(s,sizeof(s),fp);
	sscanf(s,"%[^\n]comma",s);
	char* token=strtok(s,comma);
	int index=0;
	while(token!=NULL)
	{
		if(strcmp(token,attribute)==0)
		{
			return index;
		}
		token=strtok(NULL,comma);
		index++;
	}
	fclose(fp);
	return -1;
}

// returns -1 if attribute/table does not exist, returns 1 for int, 2 for string
int retrieveDatatype(char* attribute,char* tablename)
{
	int index=checkAttributeValidity(attribute,tablename);
	if(index==-1)
	{
		return -1;
	}

	char table[200];
  memset(table,0,sizeof(table));
  sprintf(table,"tables/%s.csv",tablename);
  FILE* fp = fopen(table, "r");
  char s[1000];
  char comma[] = ",";
  fgets(s,sizeof(s),fp);
  fgets(s,sizeof(s),fp);
  sscanf(s,"%[^\n]comma",s);
  char *token = strtok(s,comma);
  int j=0;
  while(token!=NULL)
  {
      if(index == j)
      {
          fclose(fp);
          char *str=token;
          int size=getSize(token);
          for(int i=0;i<size;i++)
          {
          	char temp=str[i];
          	if(temp>='0'&&temp<='9')
          	{
				continue;
          	}
			else
          	{
				return 2;
			}
          }
          return 1;
      }
      token = strtok(NULL,comma);
      j++;
  }
  fclose(fp);
  return -1;
}

void retrieveRecords(char* tablename,char* attribute)
{
	int index=checkAttributeValidity(attribute,tablename);
	if(index==-1)
	{
		printf("Table/attribute name does not exist\n");
		return;
	}

	char table[200];
  memset(table,0,sizeof(table));
  sprintf(table,"tables/%s.csv",tablename);
  FILE* fp = fopen(table, "r");
  char s[1000];
  char comma[]=",";
  fgets(s,sizeof(s),fp);
  while(fgets(s,sizeof(s),fp))
  {
  	sscanf(s,"%[^\n]comma",s);
  	char *token = strtok(s,comma);
  	int j=0;
    while(token!=NULL)
    {
        if(index == j)
        {
        	printf("%s\n",token);
        }
        token = strtok(NULL,comma);
        j++;
    }
  }
  fclose(fp);
  return;
}

int removeIntDup(char* attribute,char* tablename,int answer[])
{
	int index=checkAttributeValidity(attribute,tablename);
	if(index==-1)
		return -1;

	char table[200];
  	memset(table,0,sizeof(table));
  	sprintf(table,"tables/%s.csv",tablename);
  	FILE* fp=fopen(table,"r");
  	int arr[10000];
  	char s[1000];
  	char comma[]=",";
  	fgets(s,sizeof(s),fp);
  	int count=0;
  	while(fgets(s,sizeof(s),fp))
  	{
  		sscanf(s,"%[^\n]comma",s);
	  	char *token = strtok(s,comma);
	  	int j=0;
	    while(token!=NULL)
	    {
	        if(index == j)
	        {
	        	int temp=convertInt(token);
	        	arr[count++]=temp;
	        	break;
	        }
	        token = strtok(NULL,comma);
	        j++;
	    }
  	}
  	int ans[count];
  	for(int i=0;i<count;i++)
  		ans[i]=arr[i];
  	mergeSort(ans,0,count-1);

  	int ans2[count];
  	int count2=0;
  	ans2[count2]=ans[0];
  	count2++;
  	for(int i=1;i<count;i++)
  	{
  		if(ans[i]==ans[i-1])
  			continue;
  		else
  			ans2[count2++]=ans[i];
  	}
  	for(int i=0;i<count2;i++)
  		answer[i]=ans2[i];
  	return count2;
}

int removeStringDup(char* attribute,char* tablename,char answer[1000][1000])
{
	int index=checkAttributeValidity(attribute,tablename);
	if(index==-1)
		return -1;

	char table[200];
  	memset(table,0,sizeof(table));
  	sprintf(table,"tables/%s.csv",tablename);
  	FILE* fp=fopen(table,"r");
  	char arr[1000][1000];
  	char s[1000];
  	char comma[]=",";
  	fgets(s,sizeof(s),fp);
  	int count=0;
  	while(fgets(s,sizeof(s),fp))
  	{
  		sscanf(s,"%[^\n]comma",s);
	  	char *token = strtok(s,comma);
	  	int j=0;
	    while(token!=NULL)
	    {
	        if(index == j)
	        {
	        	int size=getSize(token);
	        	for(int i=0;i<size;i++)
	        		arr[count][i]=token[i];
	        	count++;
	        	break;
	        }
	        token = strtok(NULL,comma);
	        j++;
	    }
  	}
  	// plain old bubble sort
  	for(int i=0;i<count-1;i++)
  	{
  		for(int j=i+1;j<count;j++)
  		{
  			char temp[1000];
  			if (strcmp(arr[j], arr[i]) < 0) 
            { 
                strcpy(temp, arr[j]); 
                strcpy(arr[j], arr[i]); 
                strcpy(arr[i], temp); 
            } 
  		}
  	}
  	char ans[1000][1000];
  	int count2=0;
  	for(int i=0;i<count;i++)
  	{
  		if(i==0)
  		{
  			int size=getSize(arr[i]);
  			for(int k=0;k<size;k++)
  				ans[count2][k]=arr[i][k];
  			count2++;
  			continue;
  		}
  		if(strcmp(arr[i],arr[i-1])==0)
  			continue;
  		else
  		{
  			int size=getSize(arr[i]);
  			for(int k=0;k<size;k++)
  				ans[count2][k]=arr[i][k];
  			count2++;
  		}
  	}
  	for(int i=0;i<count2;i++)
  	{
  		int size=getSize(ans[i]);
  		for(int k=0;k<size;k++)
  			answer[i][k]=ans[i][k];
  	}
  	return count2;
}

void Duplicates(char* attribute,char* tablename)
{
	int data_type=retrieveDatatype(attribute,tablename);
	if(data_type==-1)
		return;
	if(data_type==1)
	{
		int answer[1000];
		int p=removeIntDup(attribute,tablename,answer);
		for(int i=0;i<p;i++)
			printf("%d\n",answer[i]);
		return;
	}
	else
	{
		char answer[1000][1000];
		int p=removeStringDup(attribute,tablename,answer);
		for(int i=0;i<p;i++)
		{
			printf("%s\n",answer[i]);
		}
		return;
	}
}

int main()
{
	char check[]="Research_area";
	char table[]="prof_course";
	Duplicates(check,table);
}
