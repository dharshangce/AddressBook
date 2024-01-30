#include <stdio.h>
#include "address.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

Status list_contact(Addinfo *addinfo)
{
	printf("List Contacts: \n");
	FILE *fp;
	fp=fopen(addinfo->file_name,"r");
	char buffer[100];
 const	char  *delim=",";

	printf("=================================================================================================\n");
	printf("Name                Phone.no                Email Id                                             \n");
	printf("==================================================================================================\n");
	
	while(fscanf(fp,"%s",buffer)!=EOF)
	{
    char *name=strtok(buffer,delim);
	char *number=strtok(NULL,delim);
	char *email=strtok(NULL,delim);

	if(name && number && email)
		email[strcspn(email,"\n")]='\0';
	if(!strcmp(name,"!!!!!!!!!!!!!!!"))
	{
		continue;
	}
	char new_nam[strlen(name)+1];
	char new_num[strlen(number)+1];
	char new_ema[strlen(email)+1];
	int j=0,k=0,l=0,x=0,y=0;
	for(int i=0;name[i];i++)
	{
		if(isalnum(name[i]))
			new_nam[j++]=name[i];
	}
	new_nam[j]='\0';
    for(int i=0;number[i];i++)
	{
	   if(isdigit(number[i]))
		{
			new_num[l++]=number[i];
		}
	
	}
	new_num[l]='\0';
	for(int i=0;email[i];i++)
	{

         if(isalnum(email[i])||email[i]=='@'||email[i]=='.')
		 {
		   new_ema[y++]=email[i];
		   
	   }
	}
   new_ema[y]='\0';
   
	
	
	printf("%-20s%-24s%s\n",new_nam,new_num,new_ema);
    }
	fclose(fp);
	return e_success;
}

