/**************************************** MAD Engineers ****************************************

  Copyright (c) 2014

Author		: madD7
File		: $URL$
Description	: 
Originator	: 
$Id$

*/




/* Include Files **************************************************************************
* @{
*/
#include "error.h"
#include "appinclude.h"

/*
* @}
*/





/* Functions ******************************************************************************
* @{
*/


/***************************************************************************************
Synopsis	: 
Input		: 
Output		: None
Returns		: 
Description	: 
Notes		: None
Published	: No
*/
void Error(const char* Msg)
{
	GtkBuilder* pbuilder;
	GtkWidget* perrorwindow;
	//GtkEntry* perrorentry;
	GError* error=NULL;

	pbuilder = gtk_builder_new();
	
	if(! gtk_builder_add_from_file(pbuilder, GLADEFILE, &error))
	{
		g_warning("%s", error->message);
		g_free(error);
		return;
	}

	perrorwindow = GTK_WIDGET(gtk_builder_get_object(pbuilder, "Error"));
	gtk_entry_set_text( GTK_ENTRY(gtk_builder_get_object(pbuilder, "Txt_Error")), Msg);
	gtk_widget_show(perrorwindow);
	g_object_unref(G_OBJECT(pbuilder));
	
	gtk_widget_show_all(perrorwindow);
}


/*
* @}
*/

/* ~~~~~ END OF FILE ~~~~~ */

