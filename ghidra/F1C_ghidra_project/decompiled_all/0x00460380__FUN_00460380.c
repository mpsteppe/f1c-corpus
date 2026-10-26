// Function: FUN_00460380 @ 00460380
// Strings:  [MPCLIENTGRID]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00460380(int param_1)

{
  float fVar1;
  int iVar2;
  char cVar3;
  undefined1 local_80 [32];
  undefined1 local_60 [96];
  
  if ((*(int *)(param_1 + 0x3fc4) == 3) &&
     (fVar1 = *(float *)(param_1 + 0x1c) - (float)_DAT_008afe98, *(float *)(param_1 + 0x1c) = fVar1,
     fVar1 < DAT_0059e440)) {
    FUN_00461550();
    cVar3 = FUN_004630d0(local_80);
    iVar2 = DAT_008ac48c;
    if (cVar3 != '\0') {
      FUN_004c5690(local_60);
      if (*(char *)(param_1 + 0x20) == '\0') {
        if (iVar2 != DAT_008ac48c) {
          *(undefined1 *)(param_1 + 0x20) = 1;
        }
      }
      else {
        FUN_00461900();
        FUN_004c54f0(0);
        FUN_004a0dc0();
        if (DAT_007ce254 == '\0') {
          FUN_004a0030();
        }
        FUN_00497940(s_MPCLIENTGRID_005c5f5c,0xffffffff);
        *(undefined1 *)(param_1 + 0x20) = 0;
      }
      *(undefined4 *)(param_1 + 0x1c) = DAT_0059f0ac;
    }
    FUN_004b0170();
  }
  return;
}


