//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TGame *Game;
char currentPlayerSymbol = 'X';

//---------------------------------------------------------------------------
__fastcall TGame::TGame(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TGame::ButtonClick(TObject *Sender)
{
    TButton *clickedButton = dynamic_cast<TButton*>(Sender);
	clickedButton->Text = currentPlayerSymbol;

	if (currentPlayerSymbol == 'X') {
		currentPlayerSymbol = 'O';
		currentPlayer->Text = "Its Your Turn, Player : O";
	}
	else {
		currentPlayerSymbol = 'X';
		currentPlayer->Text = "Its Your Turn, Player : X";
	}
}
//---------------------------------------------------------------------------

