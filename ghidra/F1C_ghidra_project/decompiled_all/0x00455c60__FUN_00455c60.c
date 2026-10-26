// Function: FUN_00455c60 @ 00455c60
// Strings:  [D:\dev\F1_1999_2002\Source\hwinput.cpp, Entered HWInput::Setup()]


void __fastcall FUN_00455c60(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  if (DAT_007c569c != 5) {
    cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_hwinp_005c56a4,0x1469);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Entered_HWInput__Setup___005c56cc);
    }
  }
  iVar2 = DirectInput8Create(DAT_007ce2a0,0x800,&DAT_005ad4a0,param_1,0);
  if (iVar2 == 0) {
    FUN_0044ee10(DAT_007ce2dc,DAT_005ec4a4,2);
    FUN_0044fa60(DAT_007ce2dc,DAT_005ec4a4);
    FUN_0044fa60(DAT_007ce2dc,DAT_005ec4a4);
    FUN_0044fbe0();
    FUN_0044fbe0();
    FUN_0044fa60(DAT_007ce2dc,DAT_005ec4a4);
    FUN_0044fa60(DAT_007ce2dc,DAT_005ec4a4);
    FUN_004533a0();
    return;
  }
  return;
}


