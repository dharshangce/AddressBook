#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"

int main(int argc,char *argv[])
{
	Addinfo addinfo; 
	FILE *fp;
	int op;
	if(argc>1)
	{
		if(strstr(argv[1],".csv")!=NULL)
		{

			strcpy(addinfo.file_name,argv[1]);
			fp=fopen(addinfo.file_name,"r");
			if(get_filesize(fp)>1)
			{
				printf("INFO:File is Not empty\n");

			}
			else
			{
				printf("INFO: File is empty so you should add the contens\n");
			}

		}
		else
		{
			printf("INFO:Please pass valid source file\n");
			return e_failure;
		}

	}
	else
	{
		printf("INFO: Please pass valid argument\n");
		return e_failure;
	}
	do
	{

	main_menu();
	printf("Please select an option : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			if(add_contact(&addinfo)==e_success)
			{
				printf("INFO : Contact added Successfully\n");
				
				//main_menu();
				return e_success;
			}
			else
			{
				printf("INFO : Error to Add the contact\n ");
				return e_failure;
			}
			break;
		case 2:
			if(search_contact(&addinfo)==e_success)
			{
				printf("INFO : Contact Search Done Successfully\n");
				return e_success;
			}
			else
			{
				printf("INFO : Contact Search Not Done \n");
				return e_failure;
			}
			break;
		case 3:
		    if(edit_contact(&addinfo)==e_success)
			{
				printf("Info : Contact edited Successfully\n");
			}
			else
			{
				printf("Info : Error in edit the contact\n");
			}
			break;
		case 4:
			if(delete_contact(&addinfo)==e_success)
			{
				printf("Info : Contact deleted Successfully\n");
				return e_success;
			}
			else
			{
				printf("Info : Contact deletion Failure\n");
				return e_failure;
			}
			break;
		case 5:
			if(list_contact(&addinfo)==e_success)
			{
				printf("Info : List the Contact Successfully\n");
				return e_success;
			}
			else
			{
				printf("Info : Error in List the Contacts\n");
				return e_failure;
			}
			break;
		case 0:
			return e_success;
		default:
			printf("Enter the proper option\n");
			break;
	}
	}
	while(op!=0);

     fclose(fp);
     return e_success;
}
int  get_filesize(FILE *fptr)
{
	fseek(fptr,0,SEEK_END);
	return (ftell(fptr));
}
void  main_menu()
{
	printf("####### Address Book #######\n");
	printf("####### Features: \n");
	printf("0. Exit\n1. Add Contact\n2. Search Contact\n3. Edit Contact\n4. Delete Contact\n5. List Contact\n");


}
