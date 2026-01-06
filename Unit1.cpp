//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CanvaAreaMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
if(IsDrawing){
DrawPixel(X,Y);
}

int gridX=X/GridCellSize;
int gridY=Y/GridCellSize;

StatusLable->Caption="Position: ( "+IntToStr(gridX)+" , "+IntToStr(gridY)+ " )";
}
//---------------------------------------------------------------------------
void TMainForm::DrawPixel(int x,int y){
CanvaArea->Canvas->Brush->Color=CurrentColor;

int pixelX=(x/GridCellSize)*GridCellSize;
int pixelY=(y/GridCellSize)*GridCellSize;

CanvaArea->Canvas->FillRect(TRect(pixelX, pixelY,
pixelX + GridCellSize,
pixelY + GridCellSize));
}
//---------------------------------------------------------------------------
void TMainForm::DrawGrid(){
CanvaArea->Canvas->Pen->Color=clGray;
CanvaArea->Canvas->Pen->Width=1;

for(int i=0;i<=CanvaArea->Width; i+=GridCellSize){
CanvaArea->Canvas->MoveTo(i,0);
CanvaArea->Canvas->LineTo(i,CanvaArea->Height);
}
for(int j=0;j<=CanvaArea->Height;j+=GridCellSize){
CanvaArea->Canvas->MoveTo(0,j);
CanvaArea->Canvas->LineTo(CanvaArea->Width,j);
}
}
void __fastcall TMainForm::ClearButtonClick(TObject *Sender)
{
CanvaArea->Canvas->Brush->Color=clWhite;
CanvaArea->Canvas->FillRect(CanvaArea->ClientRect);
DrawGrid();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveButtonClick(TObject *Sender)
{
if(SaveDialog1->Execute()){
Graphics::TBitmap*bmp=new Graphics::TBitmap();

try{
	bmp->Width=CanvaArea->Width;
	bmp->Height=CanvaArea->Height;

	bmp->Canvas->CopyRect(
	CanvaArea->ClientRect,
	CanvaArea->Canvas,
	CanvaArea->ClientRect
	);

	bmp->SaveToFile(SaveDialog1->FileName);
	StatusLable->Caption="Draw is saved";
}
__finally{
	delete bmp;
}
}
}
//---------------------------------------------------------------------------
void TMainForm::FloodFill(int x,int y,TColor oldColor ,TColor newColor){
if(x<0||x>=CanvaArea->Width || y<0||y>=CanvaArea->Height)
return;
}
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
GridCellSize=20;
IsDrawing=false;
CurrentBrushSize = 1;
CurrentColor = ColorPalette->Selected;
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::CanvaAreaMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
 IsDrawing=true;
 DrawPixel(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CanvaAreaMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  IsDrawing=false;
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ColorPaletteChange(TObject *Sender)
{
CurrentColor = ColorPalette->Selected;
}
//---------------------------------------------------------------------------


