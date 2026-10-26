// Function: FUN_00463bc0 @ 00463bc0
// Strings:  [SELECTCIRCUITPAGE, MULTIPLAYER_CREATEGAME]


undefined4 __fastcall FUN_00463bc0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(char *)(*param_1 + 0xc5) != '\0') {
    DAT_007d0410 = 5;
    if (DAT_007d0418 < 6) {
      if (DAT_007d041c < 5) {
        DAT_007d0410 = DAT_007d041c;
      }
    }
    else {
      DAT_007d0410 = DAT_007d0418;
    }
    DAT_007d0f94 = 1;
    FUN_0057a920();
    iVar2 = FUN_00463c60();
    if (iVar2 == 0) {
      FUN_00497940(s_MULTIPLAYER_CREATEGAME_005c6600,0xffffffff);
      return 1;
    }
    FUN_00497940(s_SELECTCIRCUITPAGE_005c65ec,0xffffffff);
    uVar1 = 1;
  }
  return uVar1;
}


