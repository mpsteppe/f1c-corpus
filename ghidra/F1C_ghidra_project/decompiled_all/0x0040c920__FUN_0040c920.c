// Function: FUN_0040c920 @ 0040c920
// Strings:  [MAINVIEW, Entered CamMan::Init(), D:\dev\F1_1999_2002\Source\camera.cpp]


void __fastcall FUN_0040c920(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_camer_005be958,0xe31);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_CamMan__Init___005be940);
  }
  uVar2 = FUN_00544f50(s_MAINVIEW_005be8e0);
  *param_1 = uVar2;
  DAT_005ea550 = 0;
  DAT_005ea554 = 0;
  DAT_005ea558 = 0;
  DAT_005ea500 = 0;
  DAT_005ea504 = 0;
  DAT_005ea508 = 0;
  FUN_0040c240();
  FUN_0040c3b0();
  FUN_0040c520();
  *(undefined1 *)((int)param_1 + 0x2d) = 0;
  iVar3 = FUN_0040c140();
  if (iVar3 == 0) {
    param_1[2] = param_1[6];
  }
  FUN_0054a200(0x20,1);
  return;
}


