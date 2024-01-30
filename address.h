#ifndef  ADDRESS_H
#define ADDRESS_H


typedef struct Addrinfo
{

	char name[50];
	char number[10];
	char email[50];
	char file_name[50];
    int name_len;
	int number_len;
    int email_len;
	char *nam;
	char *num;
	char *ema;
	//int sr_no;

}Addinfo;


typedef enum
{
	e_success,
	e_failure,
}Status;



int get_filesize(FILE *fp);

void menu();
void cont_menu();
void main_menu();
Status check_digit(char *);
Status add_contact(Addinfo *addinfo);
Status search_contact(Addinfo *addinfo);
Status edit_contact(Addinfo *addinfo);
Status delete_contact(Addinfo *addinfo);
Status list_contact(Addinfo *addinfo);
Status save_contact(Addinfo *addinfo);
  

#endif
