/**************************************** MAD Engineers ****************************************
MAD Engineers
Copyright (c) 2014

Author		: madD7
File		: $URL$
Description	: 
Originator	: 
$Id$

*/


#ifndef		__APPINCLUDE_H
#define		__APPINCLUDE_H



/* Include Files **************************************************************************
* @{
*/
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "error.h"
/*
* @}
*/


#define GLADEFILE		"guiHa.glade"
#define LOGIN_ID		"MadMeIn"
#define LOGIN_PASSWORD	"P@55w0rD"


/* Data Types & Variables *****************************************************************
* @{
*/

typedef struct 
{
	GtkEntry *plog;
	GtkEntry *ppwd;
}AuthEntries_Type;

/*
* @}
*/



/* Functions ******************************************************************************
* @{
*/


/*
* @}
*/


#endif


/* ~~~~~ END OF FILE ~~~~~ */

