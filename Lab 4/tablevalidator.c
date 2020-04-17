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
	sprintf(table,"%s.csv",tablename);
	FILE* fp=fopen(table,"r");
	char s[1000];
	char comma[]=",";
	fgets(s,sizeof(s),fp);
	sscanf(s,"%[\n]comma",s);
	char* token=strtok(s,comma);
	int index=0;
	while(token!=NULL)
	{
		if(strcmp(token,attribute)==0)
			return index;
		token=strtok(NULL,comma);
		index++;
	}
	printf("Attribute does not exist in table %s\n",tablename);
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
            char str[]=token;
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
    	char *token = strtok(str,comma);
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


void printCartesianProduct(char* tablename1,char* tablename2)
{
	// if(!tableValidity(tablename1))
	// {
	// 	printf("Table %s does not exist\n",tablename1);
	// 	return;
	// }
	// if(!tableValidity(tablename2))
	// {
	// 	printf("Table %s does not exist\n",tablename2);
	// 	return;
	// }
	char comma[]=",";
	char table1[100],table2[100];
	memset(table1,0,sizeof(table1));
	memset(table2,0,sizeof(table2));
	sprintf(table1, "input/%s.csv", tablename1);
	sprintf(table2, "input/%s.csv", tablename2);
	FILE* fp1=fopen(table1,"r");
	FILE* fp2=fopen(table2,"r");

	// printing attribute names
	char s1[1000];
    fgets(s1,sizeof(s1),fp1);
    sscanf(s1,"%[^\n]comma",s1);
    char *token1;
    token1 = strtok(s1, comma);
    while( token1 != NULL )
    {
        printf( "%s.%s, ", tablename1, token1);
        token1 = strtok(NULL,comma);
    }
    char s2[1000];
    fgets(s2,sizeof(s2),fp2);
    sscanf(s2,"%[^\n]comma",s2);
    char *token2;
    token2=strtok(s2,comma);
    while(token2!=NULL)
    {
        printf("%s.%s",tablename2,token2);
        token2 = strtok(NULL,comma);
        if (token2 != NULL)               // last entry , removing
        	printf(", ");
    }

    // printing records
    // fgets(s1,sizeof(s1),fp1);
    // fgets(s2,sizeof(s2),fp2);
    fclose(fp2);
    while(fgets(s1,sizeof(s1),fp1))
    {
        sscanf(s1,"%[^\n]comma",s1);
        fp2=fopen(table2,"r");
        fgets(s2,sizeof(s2),fp2);
        fgets(s2,sizeof(s2),fp2);

        while (fgets(s2,sizeof(s2),fp2))
        {
            printf("%s",s1);
            printf(",%s",s2);
        }
        fclose(fp2);
    }
    fclose(fp1);
}

// int main()
// {
// 	char check[]="mishra";
// 	if(tableValidity(check))
// 		printf("Hullehullarehullehulle\n");
// 	else
// 		printf("Katgya\n");
// 	// CSV FILE BANA KE CHECK KARLENA BAAKI DONON FUNC
// 	// GOOD NIGHT
// }
