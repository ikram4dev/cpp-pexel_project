object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 473
  ClientWidth = 630
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusLable: TLabel
    Left = 69
    Top = 419
    Width = 6
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 59
    Width = 46
    Height = 18
    Caption = 'colors'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 125
    Width = 76
    Height = 18
    Caption = 'brush size'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object CanvaArea: TPaintBox
    Left = 216
    Top = 16
    Width = 400
    Height = 400
    OnMouseDown = CanvaAreaMouseDown
    OnMouseMove = CanvaAreaMouseMove
    OnMouseUp = CanvaAreaMouseUp
  end
  object Label1: TLabel
    Left = 39
    Top = 16
    Width = 120
    Height = 25
    Caption = 'Pexel Draw'
    Color = 13224677
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object ColorPalette: TColorBox
    Left = 24
    Top = 83
    Width = 145
    Height = 22
    Style = [cbStandardColors]
    TabOrder = 0
    OnChange = ColorPaletteChange
  end
  object BrushSize: TTrackBar
    Left = 24
    Top = 149
    Width = 150
    Height = 45
    TabOrder = 1
  end
  object ClearButton: TButton
    Left = 24
    Top = 248
    Width = 135
    Height = 50
    Caption = 'Clear'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = ClearButtonClick
  end
  object SaveButton: TButton
    Left = 24
    Top = 336
    Width = 135
    Height = 50
    Caption = 'Save'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = SaveButtonClick
  end
  object SaveDialog1: TSaveDialog
    Left = 96
    Top = 208
  end
end
