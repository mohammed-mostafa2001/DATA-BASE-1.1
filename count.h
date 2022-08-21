/**
 * @file    count.H
 * @author  MOHAMMED-MOSTAFA-ELSAYED
 * @brief   File contains the standard types definition for more code portability
 * @version 1.0
 * @date    2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */


#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED
#include "STD_TYPES_M.h"
struct node
{
    int year ;
    int id ;
    uint8_type course1_id;
    uint8_type course1_grade;

    uint8_type course2_id;
    uint8_type course2_grade;

    uint8_type course3_id;
    uint8_type course3_grade;

    struct node *link;
}*head;

uint8_type SDB_GetUsedSize();

#endif // COUNT_H_INCLUDED
