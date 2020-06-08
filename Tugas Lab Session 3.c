/* 
		   LAB  3 Data Structure
By : 
  
  Nama : I Putu Krisna Dhaema Saputra
  NIM  : 2301924353
  
*/

//Header File
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>



//Deklarasi Struct
struct service{
	char name[50];
	char type[50];
	char brand[50];
	char damaged[50];
	struct service* next;
};

struct service* front;
struct service* rear;

//Fungsi Queue
int push(char*name, char*type, char*brand, char*damaged){

if(rear == NULL){
		rear = (struct service *)malloc(sizeof(struct service));
		rear->next = NULL;
		strcpy(rear->name,name);
		strcpy(rear->brand,brand);
		strcpy(rear->type,type);
		strcpy(rear->damaged,damaged);
		front = rear;
	}
	else{
		struct service *temp = NULL;
		temp = (struct service *)malloc(sizeof(struct service));
		rear->next = temp;
		strcpy(temp->name,name);
		strcpy(temp->brand,brand);
		strcpy(temp->type,type);
		strcpy(temp->damaged,damaged);
		rear = temp; 
		rear->next = NULL;
	}
}

//Fungsi memunculkan main menu
int main_menu(){
	printf("PRINTER SERVICES\n");
	printf("+++++++++++++++++++++++++++++\n\n");
	printf("1. Service List\n");
	printf("2. Add Service\n");
	printf("3. Take Service\n");
	printf("4. Exit\n\n");
}

//Fungsi Memunculkan Service List	
void services(){
	struct service* temp = NULL;
	temp = (struct service*)malloc(sizeof(struct service));
	temp = front;
	int i =1;
	
	system("cls");
	
	printf("\t\t\t\t --- Printer Services ---\n");
	printf("\n+----+---------------------+-----------------+-------------+----------------------+");
	printf("\n| No.| Customer Name       | Printer's Brand | Type        | Damaged              |");
	printf("\n+----+---------------------+-----------------+-------------+----------------------+\n");
	while(temp != NULL){
		printf("| %-2d | %-19s | %-15s | %-11s | %-20s |\n",i,temp->name,temp->brand,temp->type,temp->damaged);
		temp = temp->next;
		i++;
	}
	printf("+----+---------------------+-----------------+-------------+----------------------+");
	getch();
}


//Fungsi menu ke 2 yaitu add service (Engueue)
void add_service(){
	char name[50];
	char brand[50];
	char type[50];
	char damaged[50];
	char choice;
	
	system("cls");
	
	//input name
    do{
		system("cls");
		printf("Input Customer's Name: ");
		gets(name);
    }while(strlen(name) == 0);
    
	//Input Printer's Brand
	do{
		system("cls");
		printf("Input Customer's Name: %s ",name); 
		
		printf("\n\nInput Printer's Brand [canon/epson/hp]: ");
	    gets(brand);
		
		if(strcmp(brand, "canon") !=0 && strcmp(brand, "epson") !=0 && strcmp(brand, "hp") !=0){
			printf("\n      		Please choose appropriate brand !\n The brand of new entry name must be between canon, epson, or hp.");
			getch();
		}
		
	}while(strcmp(brand, "canon") !=0 && strcmp(brand, "epson") !=0 && strcmp(brand, "hp") !=0);
	
	//input Printer's Type
	do{
		system("cls");
		printf("Input Customer's Name: %s ",name); 
		printf("\n\nInput Printer's Brand [canon/epson/hp]: %s ",brand);
		
		printf("\n\nInput Printer's Type [4..20]: ");
		gets(type);
		
		if(strlen(type) < 4 || strlen(type) > 20){
			printf("\n\n printer's type must be between 4 and 20 length. ");
			getch();
		}
		
	}while(strlen(type) < 4 || strlen(type) > 20);
	
	//Input Printer's Damaged
	do{
		system("cls");
		printf("Input Customer's Name: %s ",name); 
		printf("\n\nInput Printer's Brand [canon/epson/hp]: %s ",brand);
		printf("\n\nInput Printer's Type [4..20]: %s ",type);
		
		printf("\n\nInput Damaged [5..20]: ");
		gets(damaged);
		
		if(strlen(damaged) < 5 || strlen(damaged) > 20){
			printf("\n\n Printer's damaged must be between 5 and 20 length. ");
			getch();
		}
	}while(strlen(damaged) < 5 || strlen(damaged) > 20);
	
	push(name,brand,type,damaged);
	
	printf("\n--- Add New Order Success ---");
	getch();

}
		
// Fungsi menu ke 3, Take Service (dequeue)
void take(){
	struct service *temp = NULL;
	temp = (struct service *)malloc(sizeof(struct service));
	temp = front;
	
	if(front == NULL){
		
		printf("\nThere is no printer to  repair.");
		getch();
		return;
		
	}else{
		if(temp->next != NULL){
			temp = temp->next;
			free(front);
			front = temp;
			printf("\nPrinter has been repaired");
			getch();
		}else{
			free(front);
			front = NULL;
			rear = NULL;
			printf("\nPrinter has been repaired");
			getch();
		}
	}
}


//fungsi main
int main(){
	int choice;
	
	
	do{ 
		system("cls");
		
		main_menu();	
		printf(">> Input your choice : ");
	    fflush(stdin);
		scanf("%d",&choice);
			
		switch (choice){
			case 1 :{
				services();
				break;
			}
			case 2 :{
				add_service();
				break;
			}
			case 3 :{
				take();
				break;
			}
	
    	}
    
    }while(choice !=4);
    
	system("cls");
 
	
	printf("Thanks for using this program");

  	getch();
  	
  	return 0;
}

