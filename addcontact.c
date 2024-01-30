#include <stdio.h>
#include "address.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void cont_menu(const char *str)
{
	printf("####### Address Book #######\n");
	printf("####### %s:\n",str);
	printf("0. Back\n1. Name\n2. Phone Number\n3. Email Id\nPlease select an option: ");
}
Status add_contact(Addinfo *addinfo)
{
	int o;
   FILE *fp;
    fp=fopen(addinfo->file_name,"a+");
	do
	{
    
	cont_menu("Add Contact:");
	scanf("%d",&o);

		switch(o)
		{
		
			case 1:
				{
				char name[32];

				printf("Enter the name (15 Spaces) : ");
				scanf("%s",name);
				if(strlen(name)<15)
				{
					for(int i=strlen(name);i<15;i++)
					{
						name[i]='!';
					}
				}

				strcpy(addinfo->name,name);
				strcat(addinfo->name,",");
				addinfo->name_len=strlen(addinfo->name);

				fwrite(addinfo->name,addinfo->name_len,sizeof(char),fp);
				
				}
				break;
			case 2:
				{
				char num[32];
				printf("Enter the phone number(10 spaces) : ");
				scanf("%s",num);
				if(check_digit(num)==e_success)
				{
					strcpy(addinfo->number,num);
					strcat(addinfo->number,",");
					addinfo->number_len=strlen(addinfo->number);
					fwrite(addinfo->number,addinfo->number_len,sizeof(char),fp);
				}
				else
				{
					printf("INFO: Error Please pass valid phone number\n");
				
				}
				}
				break;
			
			case 3:
				{
				char email[100];
				printf("Enter the email id(30 spaces) : ");
				scanf("%s",email);

				if(strlen(email)<30)
				{
					for(int i=strlen(email);i<30;i++)
					{
						email[i]='!';
					}
				}
				if(strstr(email,"@gmail.com")!=NULL)
				{
					strcpy(addinfo->email,email);
					strcat(addinfo->email,",");
					addinfo->email_len=strlen(addinfo->email);
					fwrite(addinfo->email,addinfo->email_len,sizeof(char),fp);
					
					fputc('\n',fp);
					fclose(fp);
					return e_success;
				}
				else
				{
					printf("INFO:Error Please pass valid email id\n");
				}
				}
				break;
	    }
	}while(o!=0);
	fclose(fp);
   return e_success;
}
Status check_digit(char*str)
{
	int i;
	if(strlen(str)!=10)
	{
		return e_failure;
	}
	for(i=0;i<strlen(str);i++)
	{
		if(!isdigit(str[i]))
			return e_failure;
	}
	return e_success;
}
