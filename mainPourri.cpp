//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

static int callback(void *, int, char **, char **);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    sqlite3 *db = NULL;
    int rc;
    char *zErrMsg = 0;
    AnsiString path = "Northwind.db";           // Chemin vers la bd
    AnsiString sql = "SELECT * FROM Region";    // Requête SQL
	
    Memo1->Clear();
    Memo1->ScrollBars = ssBoth;
	
    rc = sqlite3_open(path.c_str(), &db);
    if(rc != SQLITE_OK)
    {
        MessageBox(NULL, sqlite3_errmsg(db), "SQL error", MB_ICONERROR);
        sqlite3_close(db);
    }
	
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        MessageBox(NULL, zErrMsg, "SQL error", MB_ICONERROR);
        sqlite3_free(zErrMsg);
    }
	
    sqlite3_close(db);
}
//---------------------------------------------------------------------------

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    AnsiString TempText = "";
    AnsiString MyText = "";
	
    for(int i=0; i<argc; i++)
    {
        TempText.sprintf("%s = %s\t", azColName[i], argv[i] ? argv[i] : "NULL");
        MyText += TempText;
    }
    Form1->Memo1->Lines->Add(MyText);
    return 0;
}