#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
   char *msgtype = "ENTER 1.SAVING 2.CURRENT 3.JOINT";
   char *message1 = "PLEASE ENTER FOUR(4) DIGITS";

long Validate_Password (int i1, int i2 , char * message1, int k) {
printf("ENTER PASSWORD FOR CUSTOMER");
long password1 =0;
long password2 =0;
do{
password1 = Validate_Input (i1, i2 , message1, k);
printf("ENTER AGAIN FOR VALIDATION");
password2 = Validate_Input (i1, i2 , message1, k);
}
while(password1!=password2 );

return password1;   
}

long Validate_Input (int i1, int i2 , char * message1, int k) {
long value;
	printf("\n");
    printf("%s > ", message1);
    while (scanf("%ld", &value) != 1 || (!(value>=i1 && value<=i2) && k==0) )
    {
        int chr;
        printf("\tINVALID INPUT :(\n"); 
        do {
            chr = getchar();
        } while ((chr != '\0') && (chr != '\n'));
        printf("%s > ", message1);
    }
    return value;
}
typedef struct message
{
long uid;
long pass;
long uid1;
long pass1;
long deposit;
long balance;
long Withdhraw;
int aid;
int apass;
long atype;
int verify;
int ch;
int ch1;
int output;
int verifyuid;
int verifyuid1;
long accno;
int verifyaccno;
int v;
}message;

void main()
{
	int sd;
	int len;
	int msgLen;
	struct sockaddr_in address;
	int result;
	FILE *fp;
	message *msg;
	message *reply;
	msg=(message*)malloc(sizeof(message));
	reply=(message*)malloc(sizeof(message));
	msgLen=sizeof(message);
	sd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=5555;
	len=sizeof(address);
	result=connect(sd,(struct sockaddr*)&address,len);
	if(result==-1){
	perror("Server not found");
	printf("\nError Result:%d",result);

}

printf("\nConnection successful");

do
{	
	printf("\n\nPLEASE SELECT THE CHOICE\n\n");
 	printf("--------------------------------------------");
 	printf("\nSR| \t           OPERATIONS             \n ");
	printf("-------------------------------------------");
	printf("\n1.| \tSINGLE USER ACCOUNT & JOINT ACCOUNT\n");
        printf("--------------------------------------------");
	printf("\n2.| \t      FOR ADMINISTRATOR            \n");
	printf("--------------------------------------------");
	printf("\n3.| \t            EXIT                   \n");
        printf("--------------------------------------------");	
	printf("\n\tEnter your Choice : ");
	
	scanf("%d",&msg->ch);
	write(sd,msg,msgLen);
	switch(msg->ch)
	{int a;
	case 1://User
		a=0;
		msg->verify=0;
		do{ 
		printf("\nENTER CUSTOMER ID: ");
		msg->uid = Validate_Input (1000,9999,message1,0);
		printf("\nENTER PASSWORD :");
		msg->pass=Validate_Password(1000,9999,message1,0);
		write(sd,msg,msgLen);
		read(sd,msg,msgLen);
		a++;
		}while(msg->verify!=1 && a<=3);
		
		if(msg->verify==0)
		{
				break;
		}
		
		do
		{	
			printf("\n\n  PLEASE SELECT THE OPERATION\n");
			printf("--------------------------------------------");
			printf("\n1.|\t          DEPOSIT      \n ");
			printf("--------------------------------------------");
			printf("\n2.|\t         WITHHDRAW     \n ");
			printf("--------------------------------------------");
			printf("\n3.|\t       BALANCE ENQUIRY  \n");
			printf("--------------------------------------------");
			printf("\n4.|\t          LOGOUT       \n");
                        printf("--------------------------------------------\n\n");
			printf("\n\tENTER YOUR CHOICE : ");
			scanf("%d",&msg->ch1);
			write(sd,msg,msgLen);
			switch(msg->ch1)
			{
			case 1:
				printf("DEPOSIT AMOUNT : Rs.");
				scanf("%ld",&msg->deposit);
				write(sd,msg,msgLen);
				read(sd,msg,msgLen);
				printf("\n\t TRANSACTION SUCCESSFULL !!!! \n\t NEW BALANCE = Rs.%ld ",msg->balance);
				break;
				
			case 2:
				printf("\nWITHDRAW AMOUNT : Rs.");
				scanf("%ld",&msg->Withdhraw);
				write(sd,msg,msgLen);
				read(sd,msg,msgLen);
				printf("\n\t TRANCATION SUCCESSFULL !!!! \n\t NEW BALANCE = Rs.%ld ",msg->balance);
				break;	
			
			case 3:
				read(sd,msg,msgLen);
				printf("\n\t BALANCE IS : Rs. %ld ",msg->balance);
				break;	
				
			}
			
		}while(msg->ch1!=4);
	break;
	case 2://Admin
			a=0;
			do{
			printf("\nENTER ADMIN ID: ");
			scanf("%d",&msg->aid);
			printf("\nADMIN PASSWORD : ");
			scanf("%d",&msg->apass);
			write(sd,msg,msgLen);
			read(sd,msg,msgLen);
			a++;
			}while(msg->verify!=1 && a<=3);
			
			do
			{	
			printf("\n\n        SELECT OPTION       \n");
 			printf("--------------------------------------------");
			printf("\n1.|\t      CREATE USER          \n");
			printf("--------------------------------------------");
			printf("\n2.|\t         LOGOUT\n");
 			printf("--------------------------------------------\n\n");
			printf("\n\tENTER THE CHOICE : ");
			scanf("%d",&msg->ch1);
			write(sd,msg,msgLen);
			switch(msg->ch1)
			{
			case 1:
				printf("\nTYPE OF ACCOUNT : ");
				msg->atype = Validate_Input (1,3,msgtype,0); 
				 
				a=0;
				msg->verifyuid=0;
				do{
				printf("\nENTER USER ID: ");
				msg->uid = Validate_Input (1000,9999,message1,0);
				write(sd,msg,msgLen);
				read(sd,msg,msgLen);
				a++;
				}while(msg->verifyuid!=1 && a<=3);
				
				if(msg->verifyuid==0)
				{
				break;
				}
				msg->pass=Validate_Password(1000,9999,message1,0);
				a=0;
				msg->verifyaccno=0;
				do{
				srand(24);
				msg->accno=(rand()%(9000))+1000;
				write(sd,msg,msgLen);
				read(sd,msg,msgLen);
				a++;
				}while(msg->verifyaccno!=1 && a<=3);
				
				if(msg->verifyaccno==0)
				{
				break;
				}
				printf("\nOPENING BALANCE: Rs.");
				msg->balance = Validate_Input (1000,9999,"NUMERIC VALUES ONLY",1);
				
				if(msg->atype==3)
				{
					a=0;
					msg->verifyuid1=0;
					do{
					printf("\nSECOND USER ID: ");
					msg->uid1 = Validate_Input (1000,9999,message1,0);
					write(sd,msg,msgLen);
					read(sd,msg,msgLen);
					a++;
					}while(msg->verifyuid1!=1 && a<=3);
					if(msg->verifyuid1==0)
					{
					break;
					}
					
					msg->pass1=Validate_Password(1000,9999,message1,0);
					write(sd,msg,msgLen);
				}
				write(sd,msg,msgLen);
			break;
			}
			
		}while(msg->ch1!=2);
	break;}

	}while(msg->ch!=3);

}

