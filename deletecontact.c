#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "address.h"
Status delete_contact(Addinfo *addinfo)
{
	FILE *fp;
	int op;
	char *delim=",";
	char str[32];
	char buffer[60];
	char buffer1[58]="!!!!!!!!!!!!!!!,!!!!!!!!!!,!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!,";
	do
	{
		list_contact(addinfo);
		cont_menu("Delete Contact:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				int flag=0;
				printf("Enter the name : ");
				scanf("%s",str);
				fp=fopen(addinfo->file_name,"r+");
				while(!feof(fp))
				{
					int pos=ftell(fp);
					fscanf(fp,"%s",buffer);
					int pre=ftell(fp);
					addinfo->nam=strtok(buffer,delim);
					addinfo->num=strtok(NULL,delim);
					addinfo->ema=strtok(NULL,delim);
					for(int i=strlen(str);i<15;i++)
					{
						str[i]='!';
					}
					if(!(strcmp(addinfo->nam,str)))
					{
						buffer1[58]='\0';
						if(pos==0)
						{
							fseek(fp,-pre,SEEK_CUR);
						}
						else
						{
							int p=pre-pos-1;
							fseek(fp,-p,SEEK_CUR);
						}
						fprintf(fp,"%s",buffer1);
						flag=1;
						fclose(fp);
						return e_success;
					}
					pos=pre;
                }
				if(flag==0)
				{
					printf("Info : Entered name is not present in address book\n");

			        fclose(fp);
					return e_failure;
				}
			}
			break;

			case 2:
			{
				int flag=0;
				printf("Enter the number : ");
				scanf("%s",str);
				fp=fopen(addinfo->file_name,"r+");
				while(!feof(fp))
				{
					int pos=ftell(fp);
					fscanf(fp,"%s",buffer);
					int pre=ftell(fp);
					addinfo->nam=strtok(buffer,delim);
					addinfo->num=strtok(NULL,delim);
					addinfo->ema=strtok(NULL,delim);
					/*for(int i=strlen(str);i<15;i++)
					{
						str[i]='!';
					}*/
					if(!(strcmp(addinfo->num,str)))
					{
						buffer1[58]='\0';
						if(pos==0)
						{
							fseek(fp,-pre,SEEK_CUR);
						}
						else
						{
							int p=pre-pos-1;
							fseek(fp,-p,SEEK_CUR);
						}
						fprintf(fp,"%s",buffer1);
						flag=1;
						fclose(fp);
						return e_success;
					}
					pos=pre;
                }
				if(flag==0)
				{
					printf("Info : Entered number  is not present in address book\n");

	          		fclose(fp);
					return e_failure;
				}
			}
			break;

			case 3:
			{
				int flag=0;
				printf("Enter the emailid : ");
				scanf("%s",str);
				fp=fopen(addinfo->file_name,"r+");
				while(!feof(fp))
				{
					int pos=ftell(fp);
					fscanf(fp,"%s",buffer);
					int pre=ftell(fp);
					addinfo->nam=strtok(buffer,delim);
					addinfo->num=strtok(NULL,delim);
					addinfo->ema=strtok(NULL,delim);
					for(int i=strlen(str);i<30;i++)
					{
						str[i]='!';
					}
					if(!(strcmp(addinfo->ema,str)))
					{
						buffer1[58]='\0';
						if(pos==0)
						{
							fseek(fp,-pre,SEEK_CUR);
						}
						else
						{
							int p=pre-pos-1;
							fseek(fp,-p,SEEK_CUR);
						}
						fprintf(fp,"%s",buffer1);
						flag=1;
						fclose(fp);
						return e_success;
					}
					pos=pre;
                }
				if(flag==0)
				{
					printf("Info : Entered emailid is not present in address book\n");

	          		fclose(fp);
					return e_failure;
				}
			}
			break;

		}
   }while(op!=0);
}

