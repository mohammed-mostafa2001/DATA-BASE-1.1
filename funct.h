#ifndef FUNCT_H_INCLUDED
#define FUNCT_H_INCLUDED
typedef enum
{
    False,
    True
} boolean;

void print_data(struct node *head);
boolean SDB_IsFull();
boolean SDB_AddEntry(int year,int id, uint8_type *arr_course_id , uint8_type *arr_course_grade );
void SDB_Delete_Entry(int id);
boolean SDB_ReadEntry(int id);
void SDB_GetidList2();
boolean SDB_IsidExist(int id );

#endif // FUNCT_H_INCLUDED
