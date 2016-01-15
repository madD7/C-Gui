/***************************** MAD Engineers ****************************
Copyright (c) 2014

Author		: madD7
File		: $URL$
Description	: 
Originator	: 
$Id$

*/




/* Include Files ************************************************************************* @{
*/
#include <gtk/gtk.h>
#include <stdio.h>

/*
* @}
*/



typedef struct
{
	GtkEntry *plog;
	GtkEntry *ppwd;
}AuthEntries;
AuthEntries logentry;



/* Functions ***************************************************************************** @{
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
void BtnPressdEvt_Config(GtkButton* Btn_Config, gpointer data)
{
	GtkBuilder* pbuilder;
	GtkWidget* ploginwindow;
//	AuthEntries logentry;
	GError*	error = NULL;

	pbuilder = gtk_builder_new();

	if(! gtk_builder_add_from_file(pbuilder, "guiHa.glade", &error))
	{
		g_warning("%s", error->message);
		g_free(error);
		return;
	}

	logentry.plog = GTK_ENTRY(gtk_builder_get_object(pbuilder, "TxtBx_Uname"));
	logentry.ppwd = GTK_ENTRY(gtk_builder_get_object(pbuilder, "TxtBx_Pswd"));
	gtk_builder_connect_signals(pbuilder, &logentry);
	ploginwindow = GTK_WIDGET(gtk_builder_get_object(pbuilder, "LoginMain"));

	g_object_unref(G_OBJECT(pbuilder) );
	gtk_widget_show_all(ploginwindow);
}





/***************************************************************************************
Synopsis	: 
Input		: 
Output		: None
Returns		: 
Description	: 
Notes		: None
Published	: No
*/
void BtnPressdEvt_Login(GtkButton* Btn_Login, AuthEntries *pAuth)
{
	char login[30]={0}, passwd[30]={0};
	char *plogin = login, *ppasswd = passwd;

	plogin =  gtk_entry_get_text(pAuth->plog);
	ppasswd =  gtk_entry_get_text(pAuth->ppwd);

	printf("%s %s \n",plogin,ppasswd);
	fflush(stdout);
}




/***************************************************************************************
Synopsis	: 
Input		: 
Output		: None
Returns		: 
Description	: 
Notes		: None
Published	: No
*/
int main(int argc, char* argv[])
{
	GtkBuilder* pbuilder;
	GtkWidget* pmainwindow;
	GError* error=NULL;
	
	gtk_init(&argc, &argv);
	pbuilder = gtk_builder_new();
	
	if(! gtk_builder_add_from_file(pbuilder, "guiHa.glade", &error))
	{
		g_warning("%s", error->message);
		g_free(error);
		return 1;
	}
	
	gtk_builder_connect_signals(pbuilder, NULL);
	pmainwindow = GTK_WIDGET(gtk_builder_get_object(pbuilder, "Main"));

	gtk_widget_show(pmainwindow);
	gtk_main();
	return 0;		
}


/*
* @}
*/

/* ~~~~~ END OF FILE ~~~~~ */






