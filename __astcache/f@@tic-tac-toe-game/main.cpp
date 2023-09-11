//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TGame *Game;
char currentPlayerSymbol = 'X';
int click_count = 0;

void TGame::disableAllButtons()
{
	Button1->Enabled = false;
	Button1->Opacity = 0.6;

	Button2->Enabled = false;
	Button2->Opacity = 0.6;

	Button3->Enabled = false;
	Button3->Opacity = 0.6;

	Button4->Enabled = false;
	Button4->Opacity = 0.6;

	Button5->Enabled = false;
	Button5->Opacity = 0.6;

	Button6->Enabled = false;
	Button6->Opacity = 0.6;

	Button7->Enabled = false;
	Button7->Opacity = 0.6;

	Button8->Enabled = false;
	Button8->Opacity = 0.6;

	Button9->Enabled = false;
	Button9->Opacity = 0.6;
}

bool TGame::CheckIsWinner()
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
__fastcall TGame::TGame(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TGame::ButtonClick(TObject *Sender)
{
	resetButton->Enabled = true;
	resetButton->Opacity = 1;

	TButton *clickedButton = dynamic_cast<TButton*>(Sender);
	clickedButton->Text = currentPlayerSymbol;
    clickedButton->Enabled = false;
	clickedButton->Opacity = 0.6;

    if (CheckIsWinner())
	{
		if (currentPlayerSymbol == 'X'){
			headerDisplay->Text = "Congratulations, X WON!";
			gameState->Text = "Game Over";
			ShowMessage("Player X WON!");
		}
		else{
			headerDisplay->Text = "Congratulations, O WON!";
			gameState->Text = "Game Over";
            ShowMessage("Player O WON!");
		}
        disableAllButtons();
		return;
	}

	if (currentPlayerSymbol == 'X') {
		currentPlayerSymbol = 'O';
		headerDisplay->Text = "Its Your Turn, Player : O";

	}
	else {
		currentPlayerSymbol = 'X';
		headerDisplay->Text = "Its Your Turn, Player : X";
	}

	click_count++;

	if (click_count == 9)
	{
		headerDisplay->Text = "Result is Draw";
		gameState->Text = "Game Over";
		ShowMessage("Result is Draw");
		return;
	}


}



void __fastcall TGame::resetButtonClick(TObject *Sender)
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
	 headerDisplay->Text = "Its Your Turn, Player : X";
	 gameState->Text = "Game is Running";
	 resetButton->Enabled = false;
	 resetButton->Opacity = 0.6;
     click_count = 0;

}
//---------------------------------------------------------------------------

