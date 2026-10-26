// Function: FUN_005087a2 @ 005087a2
// Size (bytes): 197


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005087a2(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  undefined1 *extraout_EDX;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)(param_1 + 0x1048) != 0) {
    param_4 = FUN_00506ce2(param_4);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  FUN_00507473();
  uVar3 = 0;
  puVar4 = extraout_EDX;
  if (*(int *)(param_1 + 0x1058) != 0) {
    do {
      pfVar2 = (float *)(param_4 + iVar5);
      *puVar4 = (char)(int)ROUND(*(float *)(iVar1 + ((param_3 & 3) + (param_2 & 3) * 8) * 4 +
                                           (uVar3 & 3) * 4) +
                                 (*pfVar2 * _DAT_005adb18 +
                                 pfVar2[1] * _DAT_005adb1c + pfVar2[2] * _DAT_005adb20) *
                                 DAT_0059fec8);
      puVar4 = puVar4 + 1;
      uVar3 = uVar3 + 1;
      iVar5 = iVar5 + 0x10;
    } while (uVar3 < *(uint *)(param_1 + 0x1058));
  }
  return;
}


