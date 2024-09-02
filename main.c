#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"
#include"project.h"

void main(void){

	u32 password;
	
	u8 password_counter;		//a counter for the password trials
	
	u8 adminFlag;				//flag for to check if your a real admin or a hacker
	
	u8 mode;					//1. User  2. Admin
	
	u8 admin_mode;				//1. Add new patient record  2. Edit patient record  3. Reserve a slot with the doctor  4. Cancel reservation.

	u8 user_mode;				//1. View the patient record  2. View today reservation
	
	u8 while_flag=1;			//flag for the program loop
	
	u8 hacker =0;				//used to exit the program if the password entered 3 times wrong
	
	while(while_flag && !hacker){
		
	
		printf("*********************************THE MODE*********************************\n");
		printf("----------Choose a mode----------\n");
		printf("**1 For Admin mode**\n");
		printf("**2 For User mode**\n");
		printf("**3 To EXIT the program**\n\n");
		printf("your choise:");
		scanf("%d",&mode);
		printf("\n");
	
		switch(mode){
			case ADMIN:
				
				for(password_counter=0;password_counter<3;password_counter++){
					printf("enter the password:");
					scanf("%d",&password);
					if(password==1234){
						printf("----------------------------------***WELCOME DR.MOUSA***----------------------------------\n");
						adminFlag=1;
						break;
					}
					else{
						if(password_counter==2){
							printf("***no more tries GOODBYE***");
							adminFlag=0;
							hacker=1;
							break;
						}
						else{
							printf("You have %d tries left\n",3-password_counter-1);
							
						}
					}
				}
				if(adminFlag){
					
					printf("*********************************THE ADMIN MODES*********************************\n");
					printf("----------Choose a mode----------\n");
					printf("**1 To Add new patient record**\n");
					printf("**2 To Edit patient record**\n");
					printf("**3 To print patient record**\n");
					printf("**4 To Reserve a slot with the doctor**\n");
					printf("**5 To Cancel reservation**\n\n");
					printf("your choice is:");
					scanf("%d",&admin_mode);
					printf("\n");
					switch(admin_mode){
						
						case ADD_NEW_PATIENT:		//to add new patients
							add_patient();
							break;
						
						case EDIT_PATIENT:			//to edit on patient's infotmation
							edit_patient();
							break;
							
						case VIEW_RECORD_ADMIN:		//to print patient's infotmation
							view_all_record();
							break;
							
						case ADD_RESERVATION:		//to add reservation with the doctor
							reserve_slot();
							break;

						case CANCEL_RESERVATION:	//to cancel reservation with the doctor
							cancel_reservation();
							break;							
					}
				}
				break;
		
			case USER:
				enter_again_user:
					printf("*********************************THE USER MODES*********************************\n");
					printf("----------Choose a mode----------\n");
					printf("**1 To View the patient record**\n");
					printf("**2 To View today reservation**\n\n");
					
					printf("your choise:");
					scanf("%d",&user_mode);
					
					switch(user_mode){
						case VIEW_RECORD_USER: //To View a patient record
							view_patient_record();
							break;
							
						case VIEW_RESERVATIONS_USER: //to  View the today's reservations
							view_reservation();
							break;
						
						default:
							printf("!!!!!!!!!!!WRONG ENTERY!!!!!!!!!!!\n\n");
							goto enter_again_user;
					}
				while_flag=1;
				break;
				
			case CLOSE:
				while_flag=0;
				break;
			
			default:
				printf("!!!!!!!!!!!!!WRONG ENTERY!!!!!!!!!!!!!\n\n\n");
			
		}
	}
}

