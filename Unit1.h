//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *CanvaArea;
	TColorBox *ColorPalette;
	TTrackBar *BrushSize;
	TButton *ClearButton;
	TLabel *StatusLable;
	TLabel *Label2;
	TLabel *Label3;
	TButton *SaveButton;
	TSaveDialog *SaveDialog1;
	TLabel *Label1;
	void __fastcall CanvaAreaMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CanvaAreaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall CanvaAreaMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ColorPaletteChange(TObject *Sender);

private:	// User declarations
TColor CurrentColor;
int CurrentBrushSize;
bool IsDrawing;
int GridCellSize;
void DrawPixel(int x,int y);
void DrawGrid();
void FloodFill(int x,int y,TColor oldColor ,TColor newColor);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
