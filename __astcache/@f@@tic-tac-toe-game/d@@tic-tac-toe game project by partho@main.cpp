//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;

char currentPlayerSymbol = 'X';
int x = 0;


bool TForm2::CheckIsWinner()
{
	if (Button1->Text == Button2->Text && Button1->Text == Button3->Text && !Button1->Text.IsEmpty())
		return true;
	if (Button4->Text == Button5->Text && Button4->Text == Button6->Text && !Button4->Text.IsEmpty())
		return true;
	if (Button7->Text == Button8->Text && Button7->Text == Button9->Text && !Button7->Text.IsEmpty())
		return true;
	if (Button1->Text == Button4->Text && Button1->Text == Button7->Text && !Button1->Text.IsEmpty())
		return true;
	if (Button2->Text == Button5->Text && Button2->Text == Button8->Text && !Button2->Text.IsEmpty())
		return true;
	if (Button3->Text == Button6->Text && Button3->Text == Button9->Text && !Button3->Text.IsEmpty())
		return true;
	if (Button1->Text == Button5->Text && Button1->Text == Button9->Text && !Button1->Text.IsEmpty())
		return true;
	if (Button3->Text == Button5->Text && Button3->Text == Button7->Text && !Button3->Text.IsEmpty())
		return true;

	return false;
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonClick(TObject *Sender)
{
	resetButton->Opacity = 1;
	if(x>=9) return;
	TButton *clickedButton = dynamic_cast<TButton*>(Sender);
	clickedButton->Text = currentPlayerSymbol;
	clickedButton->Enabled = false;
	clickedButton->Opacity = 0.4;

	if (CheckIsWinner())
	{
		if (currentPlayerSymbol == 'X'){
			winnerLabel->Text = "Player X WON!";
			ShowMessage("Player X WON!");
		}
		else{
			winnerLabel->Text = "Player O WON!";
			ShowMessage("Player O WON!");
		}
		return;
	}

	if (currentPlayerSymbol == 'X') {
		currentPlayerSymbol = 'O';
		currentPlayer->Text = "Its Your Turn, Player : O";
	}
	else {
		currentPlayerSymbol = 'X';
		currentPlayer->Text = "Its Your Turn, Player : X";
	}



	++x;
	if (x == 9)
	{
		winnerLabel->Text = "Result is Draw";
		ShowMessage("Result is Draw");
		return;
	}
}


void __fastcall TForm2::resetButtonClick(TObject *Sender)
{
	 Button1->Text = "";
	 Button1->Enabled = true;
	 Button1->Opacity = 1;

	 Button2->Text = "";
	 Button2->Enabled = true;
	 Button2->Opacity = 1;

	 Button3->Text = "";
	 Button3->Enabled = true;
	 Button3->Opacity = 1;

	 Button4->Text = "";
	 Button4->Enabled = true;
	 Button4->Opacity = 1;

	 Button5->Text = "";
	 Button5->Enabled = true;
	 Button5->Opacity = 1;

	 Button6->Text = "";
	 Button6->Enabled = true;
	 Button6->Opacity = 1;

	 Button7->Text = "";
	 Button7->Enabled = true;
	 Button7->Opacity = 1;

	 Button8->Text = "";
	 Button8->Enabled = true;
	 Button8->Opacity = 1;

	 Button9->Text = "";
	 Button9->Enabled = true;
	 Button9->Opacity = 1;

	 currentPlayerSymbol = 'X';
	 currentPlayer->Text = "Its Your Turn, Player : X";
	 x = 0;
	 winnerLabel->Text = "Game is Running";

	 resetButton->Opacity = 0.3;

}
//---------------------------------------------------------------------------


