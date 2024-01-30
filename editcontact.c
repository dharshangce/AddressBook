#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "address.h"
#include <ctype.h>


Status edit_contact(Addinfo *addinfo)
{
	FILE *fp;
	int op;
	char *delim=",";
	char str[32];
	char buffer[60];
	do
	{

		list_contact(addinfo);
		cont_menu("Edit_contact:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					int flag=0;
					printf("Enter the name : ");
					scanf("%s",str);
	                fp=fopen(addinfo->file_name,"r+");
					while(!(feof(fp)))
					{
						int pos=ftell(fp);
						fscanf(fp,"%s",buffer);
						int pre=ftell(fp);
						addinfo->nam=strtok(buffer,delim);
						 addinfo->num=strtok(NULL,delim);
					    addinfo->ema=strtok(NULL,delim);
						char new_name[strlen(addinfo->nam)+1];
						int j=0;
						for(int i=0;addinfo->nam[i];i++)
						{
							if(isalnum(addinfo->nam[i]))
							{
								new_name[j++]=addinfo->nam[i];
							}
						}
						new_name[j]='\0';
						if(!(strcmp(new_name,str)))
						{
							printf("Enter the new name : ");
							char arr[15];
							scanf("%s",arr);
							char *na=strdup(addinfo->nam);
							char *nu=strdup(addinfo->num);
							char *em=strdup(addinfo->ema);
							for(int i=0;na[i];i++)
							{
								na[i]=(na[i]&0x00);
							}
							for(int i=0;i<strlen(arr);i++)
							{
								na[i]=na[i]|arr[i];
							}
                            
							for(int i=strlen(na);i<15;i++)
							{
								na[i]='!';
							}
                            strcat(na,delim);
							strcat(nu,delim);
							strcat(em,delim);
							char buffer1[60];
							sprintf(buffer1,"%s%s%s",na,nu,em);
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
							fputc('\n',fp);
							flag=1;
							fclose(fp);
							return e_success;
						}
						pos=pre;
                    }
					if(flag==0)
					{
						printf("Info : Entered name is not present in address book\n");
						return e_failure;
					}
				}
				fclose(fp);
				break;
			case 2:
				{
                    int flag=0;
					printf("Enter the number : ");
					scanf("%s",str);

                	fp=fopen(addinfo->file_name,"r+");
					while(!(feof(fp)))
					{
						int pos=ftell(fp);
						fscanf(fp,"%s",buffer);
						int pre=ftell(fp);
						addinfo->nam=strtok(buffer,delim);
						 addinfo->num=strtok(NULL,delim);
					    addinfo->ema=strtok(NULL,delim);
						int j=0;
						if(!(strcmp(addinfo->num,str)))
						{
							printf("Enter the new number: ");
							char arr[10];
							scanf("%s",arr);
							char *na=strdup(addinfo->nam);
							char *nu=strdup(addinfo->num);
							char *em=strdup(addinfo->ema);
							for(int i=0;nu[i];i++)
							{
								nu[i]=(nu[i]&0x00);
							}
							for(int i=0;i<strlen(arr);i++)
							{
								nu[i]=nu[i]|arr[i];
							}
                            
                            strcat(na,delim);
							strcat(nu,delim);
							strcat(em,delim);
							char buffer1[60];
							sprintf(buffer1,"%s%s%s",na,nu,em);
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
							fputc('\n',fp);
							fclose(fp);
							flag=1;
							return 0;

						}
						pos=pre;
                    }
					if(flag==0)
					{
						printf("Info : Entered Phone number is not present in address book\n ");
						return e_failure;
					}
					
				fclose(fp);
				break;
				}
			case 3:
				{
                   int flag=0;
					printf("Enter the email : ");
					scanf("%s",str);
	                fp=fopen(addinfo->file_name,"r+");
					while(!(feof(fp)))
					{
						int pos=ftell(fp);
						fscanf(fp,"%s",buffer);
						int pre=ftell(fp);
						addinfo->nam=strtok(buffer,delim);
						 addinfo->num=strtok(NULL,delim);
					    addinfo->ema=strtok(NULL,delim);
						char new_email[strlen(addinfo->ema)+1];
						int j=0;
						for(int i=0;addinfo->ema[i];i++)
						{
							if(isalnum(addinfo->ema[i])||addinfo->ema[i]=='@'||addinfo->ema[i]=='.')
							{
								new_email[j++]=addinfo->ema[i];
							}
						}
						new_email[j]='\0';
						if(!(strcmp(new_email,str)))
						{
							printf("Enter the new email : ");
							char arr[15];
							scanf("%s",arr);
							char *na=strdup(addinfo->nam);
							char *nu=strdup(addinfo->num);
							char *em=strdup(addinfo->ema);
							for(int i=0;em[i];i++)
							{
								em[i]=(em[i]&0x00);
							}
							for(int i=0;i<strlen(arr);i++)
							{
								em[i]=em[i]|arr[i];
							}
                            
							for(int i=strlen(na);i<30;i++)
							{
								em[i]='!';
							}
                            strcat(na,delim);
							strcat(nu,delim);
							strcat(em,delim);
							char buffer1[60];
							sprintf(buffer1,"%s%s%s",na,nu,em);
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
							//fputc('\n',fp);
							fclose(fp);
							flag=1;
							return 0;
						}
						pos=pre;
                    }
					if(flag==0)
					{
						printf("Info : Entered email id is not present in address book\n");
						return e_failure;
					}

				}
				fclose(fp);
				break;
            }
	}while(op!=0);
	fclose(fp);
          return 0;
}

























































































































































































































































































































































