// Function: FUN_00463ef0 @ 00463ef0
// Size (bytes): 125


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00463ef0(int *param_1)

{
  if (*(int *)(*param_1 + 0x1d0) != 1) {
    *(undefined4 *)(*param_1 + 0x3fc4) = 0;
  }
  if (DAT_007ce260 == '\0') {
    if (DAT_007d0410 == 5) {
      _DAT_007d0a44 = 0;
      if (DAT_007d0a4c < 1) {
        if (DAT_007d0a50 < 0) {
          _DAT_007d0a44 = DAT_007d0a50;
        }
      }
      else {
        _DAT_007d0a44 = DAT_007d0a4c;
      }
      DAT_007d0990 = 0;
      if (0 < DAT_007d0998) {
        DAT_007d0990 = DAT_007d0998;
        return;
      }
      if (DAT_007d099c < 0) {
        DAT_007d0990 = DAT_007d099c;
        return;
      }
    }
    else {
      *(undefined4 *)(*param_1 + 0x3fc4) = 0;
    }
  }
  return;
}


