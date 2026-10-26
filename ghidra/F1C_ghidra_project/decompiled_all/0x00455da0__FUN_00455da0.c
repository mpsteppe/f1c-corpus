// Function: FUN_00455da0 @ 00455da0
// Strings:  [D:\dev\F1_1999_2002\Source\hwinput.cpp, Entered HWInput::Restart()]


void __fastcall FUN_00455da0(int param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  if (DAT_007c569c != 5) {
    cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_hwinp_005c56a4,0x1495);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Entered_HWInput__Restart___005c5700);
    }
  }
  FUN_0044f680(0,0,DAT_005d6d60,DAT_005d6d64);
  FUN_0044f0a0();
  if (DAT_007d1ffc != 0) {
    FUN_0044ff50();
  }
  *(undefined1 *)(param_1 + 0x2428) = 0;
  uVar3 = 0x1a;
  piVar2 = (int *)(param_1 + 0x1f98);
  while ((*piVar2 == 0 && (piVar2[1] == 0x59))) {
    uVar3 = uVar3 + 1;
    piVar2 = piVar2 + 0xb;
    if (0x21 < uVar3) {
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x2428) = 1;
  return;
}


