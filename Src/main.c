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
#include <appinclude.h>

/*
* @}
*/


AuthEntries_Type logentry;



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
	GError*	error = NULL;

	pbuilder = gtk_builder_new();

	if(! gtk_builder_add_from_file(pbuilder, GLADEFILE, &error))
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
void BtnPressdEvt_Login(GtkButton* Btn_Login, AuthEntries_Type *pAuth)
{
	char login[30]={0}, passwd[30]={0};
	char *plogin = login, *ppasswd = passwd;

	plogin =  gtk_entry_get_text(pAuth->plog);
	ppasswd =  gtk_entry_get_text(pAuth->ppwd);

	if((ppasswd == NULL) || *ppasswd == ' ' || strcmp(plogin, LOGIN_ID) || strcmp(ppasswd, LOGIN_PASSWORD))
	{
		Error("Authentication failed");
	}
	else
	{
		printf("%s %s", plogin, ppasswd);
	}
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
	
	if(! gtk_builder_add_from_file(pbuilder, GLADEFILE, &error))
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






