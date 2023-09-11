//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TGame : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TText *headerDisplay;
	TText *gameState;
	TButton *resetButton;
	TText *Text3;
	void __fastcall ButtonClick(TObject *Sender);
	void __fastcall resetButtonClick(TObject *Sender);

private:	// User declarations
	bool TGame::CheckIsWinner();

public:		// User declarations
	__fastcall TGame(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TGame *Game;
//---------------------------------------------------------------------------
#endif
