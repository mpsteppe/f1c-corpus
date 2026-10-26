// Function: FUN_00424cd0 @ 00424cd0
// Size (bytes): 348


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00424cd0(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  if (param_2 == 4) {
    FUN_004a46f0(param_1,1,1);
  }
  else if (param_2 == 5) {
    *(undefined1 *)(param_1 + 0x1152) = 0;
    FUN_004a46f0(param_1,0,0);
  }
  else if (param_2 == 1) {
    param_1[0x104f] = (int)((float)_DAT_008afea0 + _DAT_0059e800);
  }
  else if (param_2 == 0xf) {
    if (DAT_007c56a4 == 7) {
      bVar5 = *(int *)(*param_1 + 0x4064) == 0;
    }
    else {
      bVar5 = DAT_007c56a8 != 8;
    }
    if (bVar5) {
      if ((char)param_1[0x1104] == '\0') {
        FUN_0042adb0();
      }
    }
    else {
      FUN_004c6d90(0);
      FUN_004a5c80(0);
    }
    param_1[0x1151] = 0;
    FUN_0042acd0(0x12);
    param_1[0x1154] = 1;
    *(undefined1 *)(param_1 + 0x1152) = 1;
  }
  piVar1 = (int *)param_1[0x112a];
  if (piVar1 != (int *)0x0) {
    iVar2 = param_1[0x112c];
    iVar3 = 0;
    piVar4 = piVar1;
    if (-1 < iVar2) {
      do {
        if (*piVar4 == param_2) {
          return;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 2;
      } while (iVar3 <= iVar2);
    }
    iVar3 = iVar2 + 1;
    param_1[0x112c] = iVar3;
    if (param_1[0x112b] <= iVar3) {
      param_1[0x112c] = iVar2;
      return;
    }
    piVar1[iVar3 * 2] = param_2;
    *(undefined4 *)(param_1[0x112a] + 4 + param_1[0x112c] * 8) = param_3;
    FUN_00429ee0();
    param_1[0x112c] = -1;
    if ((param_2 == 0) && (param_1[0x1019] == 2)) {
      *(undefined1 *)(param_1 + 0x117d) = 0;
    }
  }
  return;
}


