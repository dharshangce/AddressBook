#include <stdio.h>
#include "address.h"
#include <string.h>
#include <ctype.h>
Status search_contact(Addinfo *addinfo)
{
	FILE *fp;
	fp=fopen(addinfo->file_name,"r");
	int op;
	int flag=0;
	char buffer[250];
	char *name;
	char *number;
	char *email;
	char *delim=",";
	char str[32];
	do{
	
	flag=0;	
	cont_menu("search_contact:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
     	{
		printf("Enter the name : ");
		scanf("%s",str);
        while(fscanf(fp,"%s",buffer)!=EOF)
	    {
			char *name=strtok(buffer,delim);
			char *number=strtok(NULL,delim);
			char *email=strtok(NULL,delim);
			if(name && number && email)
				email[strcspn(email,"\n")]='\0';

			char new_name[strlen(name)+1];
			char new_number[strlen(number)+1];
			char new_email[strlen(email)+1];
			int j=0;
			for(int i=0;name[i];i++)
			{
				if(isalnum(name[i]))
				{
					new_name[j++]=name[i];

				}
			}
			new_name[j]='\0';
			j=0;
           for(int i=0;number[i];i++)
		   {
			   if(isdigit(number[i]))
			   {
				   new_number[j++]=number[i];
			   }
		   }
		   new_number[j]='\0';
		   j=0;
		   for(int i=0;email[i];i++)
		   {
			   if(isalnum(email[i])||email[i]=='@'||email[i]=='.')
			   {
				   new_email[j++]=email[i];
			   }
		   }
		   new_email[j]='\0';

		  if(!(strcmp(new_name,str)))
		  {
            flag=1;

	        printf("=================================================================================================\n");
        	printf("Name                Phone.no                Email Id                                             \n");
	        printf("==================================================================================================\n");

        	printf("%-20s%-24s%s\n",new_name,new_number,new_email);
		rewind(fp);
		fclose(fp);
		return e_success;
			break;

		  }
		}
		if(flag==0)
		  {
			printf("INFO: Entered name is not present\n");
			return e_failure;
		  }
		 
		break;
		}
    case 2:
	{
		printf("Enter the phone number : ");
		scanf("%s",str);

        while(fgets(buffer,sizeof(buffer),fp)!=NULL)
	    {

			
			char *name=strtok(buffer,delim);
			char *number=strtok(NULL,delim);
			char *email=strtok(NULL,delim);
			if(name && number && email)
			{
				email[strcspn(email,"\n")]='\0';
			}

			char new_name[strlen(name)+1];
			char new_number[strlen(number)+1];
			char new_email[strlen(email)+1];
			int j=0;
			for(int i=0;name[i];i++)
			{
				if(isalnum(name[i]))
				{
					new_name[j++]=name[i];

				}
			}
			new_name[j]='\0';
			j=0;
           for(int i=0;number[i];i++)
		   {
			   if(isdigit(number[i]))
			   {
				   new_number[j++]=number[i];
			   }
		   }
		   new_number[j]='\0';
		   j=0;
		   for(int i=0;email[i];i++)
		   {
			   if(isalnum(email[i])||email[i]=='@'||email[i]=='.')
			   {
				   new_email[j++]=email[i];
			   }
		   }
		   new_email[j]='\0';

		  if(!(strcmp(new_number,str)))
		  {
            flag=1;

	        printf("=================================================================================================\n");
        	printf("Name                Phone.no                Email Id                                             \n");
	        printf("==================================================================================================\n");

        	printf("%-20s%-24s%s\n",new_name,new_number,new_email);
		rewind(fp);
		fclose(fp);
		return e_success;
			break;

		  }
		}
		if(flag==0)
		  {
			printf("INFO: Entered phone number is not present\n");
			fclose(fp);
			return e_failure;
		}
		break;

	}
    case 3:
	{
		printf("Enter email id :");
		scanf("%s",str);

		
        while(fgets(buffer,sizeof(buffer),fp)!=NULL)
	    {
		  
          
			char *name=strtok(buffer,delim);
			char *number=strtok(NULL,delim);
			char *email=strtok(NULL,delim);
			if(name && number && email)
			{
				email[strcspn(email,"\n")]='\0';
			}
			char new_name[strlen(name)+1];
			char new_number[strlen(number)+1];
			char new_email[strlen(email)+1];
			int j=0;
			for(int i=0;name[i];i++)
			{
				if(isalnum(name[i]))
				{
					new_name[j++]=name[i];

				}
			}
			new_name[j]='\0';
			j=0;
           for(int i=0;number[i];i++)
		   {
			   if(isdigit(number[i]))
			   {
				   new_number[j++]=number[i];
			   }
		   }
		   new_number[j]='\0';
		   j=0;
		   for(int i=0;email[i];i++)
		   {
			   if(isalnum(email[i])||email[i]=='@'||email[i]=='.')
			   {
				   new_email[j++]=email[i];
			   }
		   }
		   new_email[j]='\0';
 		  if(!(strcmp(new_email,str)))
		  {
            flag=1;

	        printf("=================================================================================================\n");
        	printf("Name                Phone.no                Email Id                                             \n");
	        printf("==================================================================================================\n");

        	printf("%-20s%-24s%s\n",new_name,new_number,new_email);
			rewind(fp);
			fclose(fp);
			return e_success;
			break;

		  }
		}
		if(flag==0)
		  {
			printf("INFO: Entered email id is not present\n");
			fclose(fp);
			return e_failure;
	      }
		break;
	}
	}
   }while(op!=0);
	fclose(fp);
}
