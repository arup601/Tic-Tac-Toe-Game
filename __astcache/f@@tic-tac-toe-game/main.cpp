﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TGame *Game;
//---------------------------------------------------------------------------
__fastcall TGame::TGame(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
