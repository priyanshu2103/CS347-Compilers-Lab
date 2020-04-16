#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
	printf("Table does not exist\n");
	return false;
}


bool checkAttributeValidity(char* attribute,char* tablename)
{
	if(!tableValidity(tablename))
	{
		printf("Table does not exist\n"); 
		return false;
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
	while(token!=NULL)
	{
		if(strcmp(token,attribute)==0)
			return true;
		token=strtok(NULL,comma);
	}
	printf("Attribute does not exist in table %s\n",tablename);
	fclose(fp);
	return false;
}

// jis function mein bhi daalna ho daal lena!
void printCartesianProduct(char* tablename1,char* tablename2)
{
	if(!tableValidity(tablename1))
	{
		printf("Table %s does not exist\n",tablename1);
		return;
	}
	if(!tableValidity(tablename2))
	{
		printf("Table %s does not exist\n",tablename2);
		return;
	}
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
    fgets(s1,sizeof(s1),fp1);
    fgets(s2,sizeof(s2),fp2);
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

int main()
{
	char check[]="mishra";
	if(tableValidity(check))
		printf("Hullehullarehullehulle\n");
	else
		printf("Katgya\n");
	// CSV FILE BANA KE CHECK KARLENA BAAKI DONON FUNC
	// GOOD NIGHT
}