#include <stdio.h>
#include <stdlib.h>
#include "count.h"
#include "funct.h"
#include "STD_TYPES_M.h"

int top_counter=0;
uint8_type choice =1 ;
int year;
int id =0;
uint8_type arr_course_id[3] ={0};
uint8_type arr_course_grade[3] ;

int main()
{
        head=NULL;
        uint8_type counter;
        int full;

        while(choice!=0)
        {
            if(top_counter<=10)
            {
                printf("\nSelect one order of the following:\n");
                printf("Enter number 1 for data entry\n");
                printf("Enter number 2 for delete entry\n");
                printf("Enter number 3 for showing number of entries\n");
                printf("Enter number 4 to Display nodes Info\n");
                printf("Enter number 5 to know if the list is full\n");
                printf("Enter number 6 to get IDs list\n");
                printf("Enter number 7 to check if a certain ID exists\n");
                printf("Enter number 8 to display a data of  certain student with ID\n");
                printf("Enter 0 to Quit\n");
                scanf("%d",&choice);
                system("CLS");
                switch(choice)
                {
                case 1:

                    printf("Enter Student Year: ");
                    scanf("%d",&year);

                    printf("Enter Student's ID: ");
                    scanf("%d",&id);

                    for(int i=0 ; i<3;i++)
                    {
                        printf("Enter Course %d ID: ",i+1);
                        scanf("%hhu",&arr_course_id[i]);

                        printf("Enter Course %d grade:",i+1);
                        scanf("%hhi",&arr_course_grade[i]);
                    }
                    SDB_AddEntry(year,id , arr_course_id , arr_course_grade);
                    break;

                case 2:

                    printf("Enter Student's ID: ");
                    scanf("%d",&id);
                    SDB_Delete_Entry(id);
                    break;

                case 3:

                    // Know the number of nodes made
                    counter= SDB_GetUsedSize();
                    break;

                case 4:

                    // Display Function
                    print_data(head);
                    break;

                case 5:

                    // is full function
                    full= SDB_IsFull();
                    printf("\nFull Status: %d",full);

                case 6:

                    SDB_GetidList2();
                    break;

                case 7:
                    // search of the existance of specific ID
                    printf("Enter Student's ID: ");
                    scanf("%d",&id);
                    SDB_IsidExist(id);
                    break;

                case 8:
                    printf("Enter Student's ID: ");
                    scanf("%d",&id);
                    int b;
                    b = SDB_ReadEntry(id);
                    break;

                default :
                    printf("Exitting System...\n");
                    return 0;
                    break;
                }
        }
        else
        {
            printf("Linked List Size Exceeded Maximum Size\n");
            break;
        }

    }

    return 0;
}

