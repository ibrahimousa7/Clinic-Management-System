#ifndef PROJECT_H
#define PROJECT_H


#define ADMIN	1
#define USER	2
#define CLOSE	3

//defintions for Admin's mode
#define ADD_NEW_PATIENT		1
#define EDIT_PATIENT		2
#define VIEW_RECORD_ADMIN	3
#define ADD_RESERVATION		4
#define CANCEL_RESERVATION	5
#define VIEW_RESERVATION_ADMIN	6


//defintions for user's mode
#define VIEW_RECORD_USER		1
#define VIEW_RESERVATIONS_USER	2

//defintions for Gender
#define MALE	1
#define FEMALE	2

//defintions for the chocies in the edit function
#define NEW_NAME	1
#define NEW_AGE		2
#define NEW_GENDER	3
#define EXIT_EDIT	4

//defintions for reservation struct
#define RESERVATION_SIZE	5
/*-----------------------------------------------------------------*/



typedef struct node_type patients;

struct node_type{
	u8 NAME[30];	//avaliable to view and edit
	u32 AGE;		//avaliable to view and edit
	u8 GENDER;  	//avaliable to view and edit
	u32 ID;			//avaliable to view
	u8 I;			//not avaliable to view or edit
	patients* next;	//not avaliable to view or edit 
}head;

typedef struct{
	u8 start_time[10];
	u8 end_time[10];
	u32 ID_reservation;		//the ID of the rservaied patient if ID=0-->not reserved
}reservation;



void add_patient();				//add new patient's information **only for admins**

void edit_patient();			//edit the data for all of the patients **only for admins**

void view_all_record();			//view all patients' data **only for admins**

void reserve_slot();			//to reserve a slot with the doctor **only for admins**

void view_all_reservations();	//to view all reservations **only for admins**

void cancel_reservation();		//to cancel a reservation with the doctor **only for admins**

void view_patient_record();		//for the user to view his record with his ID

void view_reservation();		//for the user to view today's reservation with the patients IDs


#endif

