#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int getSize (char * s)
{
    char * t; // first copy the pointer to not change the original
    int size = 0;

    for (t = s; *t != '\0'; t++) {
        size++;
    }
    return size;
}

/*********************************************************************************/


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
			return true;
		token=strtok(NULL,comma);
	}
	fclose(fp);
	printf("Table %s does not exist\n",tablename);
	return false;
}

// returns -1 if attribute/table does not exist, returns index if it exists and index numer
int checkAttributeValidity(char* attribute,char* tablename)
{
	if(!tableValidity(tablename))
	{
		// printf("Table does not exist\n");
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
			return index;
		token=strtok(NULL,comma);
		index++;
	}
	printf("Attribute %s does not exist in table %s\n",attribute,tablename);
	fclose(fp);
	return -1;
}

// returns -1 if attribute/table does not exist, returns 1 for int, 2 for string
int retrieveDatatype(char* attribute,char* tablename)
{
	int index=checkAttributeValidity(attribute,tablename);
	if(index==-1)
	{
		printf("Table/attribute name does not exist\n");
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
            		continue;
            	else
            		return 2;
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
