#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include"project.h"

u8 list_length=0;// length of the list 

reservation slots[RESERVATION_SIZE]={  //the reservation data
	{"2pm","2:30pm",0},
	{"2:30pm","3pm",0},
	{"3pm","3:30pm",0},
	{"4pm","4:30pm",0},
	{"4:30pm","5pm",0}
};


void add_patient(){
	
	if(list_length==0){  
		printf("Enter the new patients name:");
		scanf("%s",head.NAME);
		
		printf("Enter the new patients age:");
		scanf("%d",&head.AGE);
		
		printf("**1 For Male**\n");
		printf("**2 For Female**\n");
		printf("Enter the new patients gender:");
		scanf("%d",&head.GENDER);
		
		printf("Enter the new patients ID:");
		scanf("%d",&head.ID);
		
		head.next=NULL;
		head.I=list_length;
		
	}
	else{
		u32 temp_id;
		patients* new=(patients*) malloc(sizeof(patients));
		
		printf("Enter the new patients name:");
		scanf("%s",new->NAME);
		
		printf("Enter the new patients age:");
		scanf("%d",&(new->AGE));
		
		printf("**1 For Male**\n");
		printf("**2 For Female**\n");
		printf("Enter the new patients gender:");
		scanf("%d",&(new->GENDER));
		
		printf("Enter the new patients ID:");
		scanf("%d",&(new->ID));
		
		patients* temp=&head;
		while(temp!=NULL){
			
			if((new->ID)==(temp->ID)){
				printf("!!!this ID alardy exist!!!\n\n");
				temp=&head;
				printf("enter another one:");
				scanf("%d",&(new->ID));
			}
			
			else{
				temp=temp->next;
			}
		}
		
		new -> I=list_length;
		new -> next=NULL;
	
	patients* last=&head;
	
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new;
	}
	
	list_length++;
	printf("\n");
}


void edit_patient(){
	u32 id;
	u8 found=0;
	u8 while_editFlag=1;
	u8 choice;
	
	printf("enter the ID you want to edit:");
	scanf("%d",&id);
	
	if(list_length==0){
		printf("there are no patients data yet\n");
	}
	else{
		patients*last=&head;
		while(last!=NULL){
			
			if(last->ID==id){
				found=1;
				break;
			}
			
			else{
				last=last->next;
			}
		}
		if(found){
			while(while_editFlag){
				printf("What do you wnat to edit in this ID?\n");
				printf("**1 To edit the name**\n");
				printf("**2 To edit age**\n");
				printf("**3 To edit gender**\n");
				printf("**4 To EXIT**\n\n");
				printf("your choice is:");
				scanf("%d",&choice);
		
			switch(choice){
			
				case NEW_NAME:
					printf("Enter the new name:");
					scanf("%s",last->NAME);
					while_editFlag=1;
					break;
			
				case NEW_AGE:
					printf("Enter the new age:");
					scanf("%d",&(last->AGE));
					while_editFlag=1;
					break;
				
				case NEW_GENDER:
					printf("**1 For Male**\n");
					printf("**2 For Female**\n");
					printf("your Choice is:");
					scanf("%d",&(last->GENDER));
					while_editFlag=1;
					break;
					
				case EXIT_EDIT:
					while_editFlag=0;
					break;
				
				default:
					printf("!!!!!!!!!!!WRONG ENTERY!!!!!!!!!!!\n\n");
				}

			}
		}
		else{
			printf("the ID not found\n");
		}		
	}
	printf("\n");
}


void view_all_record(){
	patients* last=&head;
	while(last!=NULL){
		printf("The patients ID is: %d\n",last->ID);
		printf("The patients Name is: %s\n",last->NAME);
		printf("The patients Age is: %d\n",last->AGE);
		if(last->GENDER==1){
			printf("The patients Gender is:Male\n");
		}
		else if(last->GENDER==2){
			printf("The patients Gender is:Female\n");
		}
		printf("\n");
		last=last->next;
	}
	printf("\n");
}


void view_patient_record(){
	u32 id;
	printf("enter the ID you want to find:");
	scanf("%d",&id);
	
	u8 found=0;
	patients* last=&head;
	while((last!=NULL) && (!found)){
		if(last->ID==id){
			found=1;
		}
		else{
			last=last->next;
			found=0;
		}
	}
	if(found){
		
		printf("The patients Name is:%s\n",last->NAME);
		printf("The patients Age is:%d\n",last->AGE);
		if(last->GENDER==1){
			printf("Male\n\n");
		}
		else if(last->GENDER==2){
			printf("Female\n\n");
		}
	}
	else{
		printf("Wrond ID or The ID doesn't exist\n\n");
	}
	printf("\n");
	
}


void reserve_slot(){
	u8 i;
	u8 choice;	//chosen reservation
	u32 id;		//the ID of the patient
	
	for(i=0;i<RESERVATION_SIZE;i++){
		if((slots[i].ID_reservation)==0){
			printf("reservation number %d is available:\n",i);
			printf("from %s to %s\n\n",slots[i].start_time,slots[i].end_time);
		}		
	}
	
	printf("enter the reservation number you want:");
	
	taken:
	scanf("%d",&choice);
	
	if(slots[choice].ID_reservation!=0){
		printf("this reservation is taken!!\n");
		printf("please enter other one:");
		goto taken;
	}
	else if((choice<0) || (choice>4))
	{
		printf("wrong reservation number!!\n");
		printf("please enter other one:");
		goto taken;
	}
	else{
		printf("Enter your ID:");
		scanf("%d",&id);
		patients* last=&head;
		while(last!=NULL){
			if((last->ID)==id){
				printf("reservation completed\n");
				slots[choice].ID_reservation=last->ID;
				break;
			}
			else{
				if(last->next==NULL){
					printf("this ID is wrong\n");
					printf("enter the ID again:");		
					scanf("%d",&id);
					last=&head;
				}
				else{
					last=last->next;
				}
			}
		}
		
		
	}
	printf("\n");
}


void cancel_reservation(){
	u32 id;
	u8 i;
	u8 cancelFlag=0;		//Flag to check if the ID is found and the reservation is canceled
	printf("Enter the ID for the patient you want to cancel the reservation:");
	scanf("%d",&id);
	
	patients* last=&head;
	for(u8 i=0;i<RESERVATION_SIZE;i++){
		if(slots[i].ID_reservation==id){
			slots[i].ID_reservation=0;
			printf("Reservation is canceled");
			cancelFlag=1;
			break;
		}
	}
	if(cancelFlag==0){
		printf("This ID have no reservation or doesn't exist\n");
	}
	printf("\n");
}


void view_reservation(){
	u8 i;
	for(i=0;i<RESERVATION_SIZE;i++){
		if(slots[i].ID_reservation!=0){
			printf("there is a reservation for the ID:%d from %s to %s\n",slots[i].ID_reservation,slots[i].start_time,slots[i].end_time);
		}
	}
	printf("\n");
}