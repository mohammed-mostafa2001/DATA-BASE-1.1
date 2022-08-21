#include <stdio.h>
#include <stdlib.h>
#include "count.h"
#include "funct.h"
extern int top_counter;
extern struct node;
boolean SDB_IsFull()
{
    if(top_counter >= 10)  // function returns 1 if the List is full (10 Node)
        return True;          // function returns 0 if the List isn't full
    else
        return False;

}

void print_data(struct node *head)
{
    if(head==NULL)
        printf("Linked List is empty");
    else
    {
        struct node *ptr=head;
        printf("\n-----------------------------------------------------------------------------------------------------------\n");
        while(ptr!=NULL)
        {
            printf(" Student Year: %d\n ",ptr->year);
            printf(" Student ID:   %d \n ",ptr->id);

            printf(" Student Course1 ID:  %d\n ",ptr->course1_id);
            printf(" Student Course1 Grade:  %d \n\n ",ptr->course1_grade);

            printf(" Student Course2 ID:  %d\n ",ptr->course2_id);
            printf(" Student Course2 Grade:  %d \n\n ",ptr->course2_grade);

            printf(" Student Course3 ID:  %d\n ",ptr->course3_id);
            printf(" Student Course3 Grade:  %d \n ",ptr->course3_grade);

            printf("-----------------------------------------------------------------------------------------------------------\n");

            ptr=ptr->link;
        }
        printf("\n");
    }
}

/***************************************************************************************************************************/
/************************************************  Add Entry ***************************************************************/
/***************************************************************************************************************************/


boolean SDB_AddEntry(int year,int id, uint8_type *arr_course_id , uint8_type *arr_course_grade )
{
    if (SDB_IsidExist(id) == 0)
    {
        struct node *ptr=(struct node*)malloc(sizeof(struct node));  //Allocating Memory

        int j =0;

        ptr->year=year;
        ptr->id=id;

        ptr->course1_id = arr_course_id[j];
        ptr->course1_grade = arr_course_grade[j];
        j++;

        ptr->course2_id = arr_course_id[j];
        ptr->course2_grade = arr_course_grade[j];
        j++;

        ptr->course3_id=arr_course_id[j];
        ptr->course3_grade=arr_course_grade[j];

        ptr->link=NULL;

        if( (ptr->course1_grade>=0 && ptr->course1_grade<=100)  && (ptr->course2_grade>=0 && ptr->course2_grade<=100)   &&(ptr->course3_grade>=0 && ptr->course3_grade<=100)   )
        {
             if(head==NULL)
            {
                // if head is NULL , set ptr as the new head
                head = ptr;
                top_counter++;
                printf(" created Succefully\n");
                return True;
            }
            else
            {
                // if list is not empty
                // insert ptr in beginning of head

                ptr->link = head;
                head = ptr;
                top_counter++;
                printf("created Succefully\n");
                return True;
            }

        }
        else
        {   printf("Error input : All Grades Must be between 0 : 100 \n");
            printf("Creating  Failed\n");
        }

    }
    else
        printf("Student's ID already Exists , we are Sorry  you can't make another node \n");

            return False;
}

/***************************************************************************************************************************/
/************************************************  Read Entry ***************************************************************/
/***************************************************************************************************************************/

boolean SDB_ReadEntry(int id)
{
   struct node * temp1 = head;

    while(temp1!=NULL){

        if(temp1->id==id)
        {
            printf("\n------------Student with ID number %d EXIST ------------\n", id);

            printf("\nStudent with ID number %d Found:\n",id);
            printf("Student Year: %d\n ",temp1->year);
            printf("Student ID:   %d \n ",temp1->id);

            printf("Student Course-1 ID:   %d \n ",temp1->course1_id);
            printf("Student Course-1 Grade:   %d \n ",temp1->course1_grade);

            printf("Student Course-2 ID:   %d \n ",temp1->course2_id);
            printf("Student Course-2 Grade:   %d \n ",temp1->course2_grade);

            printf("Student Course-3 ID:   %d \n ",temp1->course3_id);
            printf("Student Course-3 Grade:   %d \n ",temp1->course3_grade);

            return True;
        }
        temp1 = temp1->link;
    }
    printf("Student with ID number %d DOESN'T EXIST !\n", id);
    return False;
}

/*************************************************************************************************/
/**********************************  Get ID List  ************************************************/
/*************************************************************************************************/

void SDB_GetidList2()
{
    if(head==NULL)
        printf("Linked List is empty");
    else
    {
        struct node *ptr=head;
        printf("\n");
        while(ptr!=NULL)
        {
            printf("Student ID:   %d \n ",ptr->id);
            ptr=ptr->link;
        }
        printf("\n");
    }
    printf("No of Students is %d \n",top_counter);
}

/*************************************************************************************************/
/*******************************************  ID Exist  ******************************************/
/*************************************************************************************************/

boolean SDB_IsidExist(int id )
{
    struct node * temp1 = head;

    while(temp1!=NULL){

        if(temp1->id==id)
        {
            printf("------------------------------------------------------\n");
            printf("Student with ID number %d EXIST\n", id);
            return True;
        }
        temp1 = temp1->link;
    }
    printf("Student with ID number %d doesn't exist \n", id);
    return False;
}

/*************************************************************************************************/
/**********************************  Delete Entry ************************************************/
/*************************************************************************************************/


void SDB_Delete_Entry(int id)
{
    struct node * temp1 = head;
    struct node * temp2 = head;
    while(temp1!=NULL){
        if(temp1->id==id)
        {
            printf("Student with ID number %d Found: \n\n", id);
            if(temp1==temp2){
                // this condition will run if
                // the node that we need to delete is the first node
                // of the linked list
                head = head->link;
                free(temp1);
                top_counter--;
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->link = temp1->link;
                free(temp1);
                top_counter--;
                }
            printf("Student Successfully Deleted \n");
            return True;
        }
        temp2 = temp1;
        temp1 = temp1->link;
    }
    printf("Student with ID number %d is not found !!!\n", id);
}
