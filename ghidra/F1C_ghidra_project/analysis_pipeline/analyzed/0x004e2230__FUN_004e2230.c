// Function: FUN_004e2230 @ 004e2230
// Size (bytes): 317


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e2230(int param_1,int param_2,float param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = param_2 * 0x128 + 0xd4 + param_1;
  if (ABS(param_3) < _DAT_0059e708) {
    if (ABS(param_3) < _DAT_0059eed0) {
      if (*(int *)(iVar1 + 0x118) != 0) {
        *(undefined4 *)(iVar1 + 0x118) = 0;
        FUN_005506a0(0,0,0);
        piVar2 = &DAT_008ad3ec;
        do {
          if (*piVar2 != 0) {
            FUN_005506a0(*(undefined4 *)(param_1 + 0xb6c),*piVar2,0);
          }
          piVar2 = piVar2 + 1;
        } while ((int)piVar2 < 0x8ad3f8);
      }
    }
    else if (*(int *)(iVar1 + 0x118) != 1) {
      *(undefined4 *)(iVar1 + 0x118) = 1;
      FUN_005506a0(1,0,0);
      piVar2 = &DAT_008ad3ec;
      do {
        if (*piVar2 != 0) {
          FUN_005506a0(*(undefined4 *)(param_1 + 0xb6c),*piVar2,0);
        }
        piVar2 = piVar2 + 1;
      } while ((int)piVar2 < 0x8ad3f8);
      return;
    }
  }
  else if (*(int *)(iVar1 + 0x118) != 2) {
    *(undefined4 *)(iVar1 + 0x118) = 2;
    FUN_005506a0(2,0,0);
    piVar2 = &DAT_008ad3ec;
    do {
      if (*piVar2 != 0) {
        FUN_005506a0(*(undefined4 *)(param_1 + 0xb6c),*piVar2,0);
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x8ad3f8);
    return;
  }
  return;
}


