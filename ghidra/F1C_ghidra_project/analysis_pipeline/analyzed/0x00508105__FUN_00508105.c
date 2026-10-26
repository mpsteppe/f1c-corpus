// Function: FUN_00508105 @ 00508105
// Size (bytes): 169


void __thiscall FUN_00508105(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 *extraout_EDX;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0x1048) != 0) {
    param_4 = FUN_00506ce2(param_4);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  FUN_00507473();
  uVar2 = 0;
  puVar3 = extraout_EDX;
  if (*(int *)(param_1 + 0x1058) != 0) {
    do {
      *puVar3 = (char)(int)ROUND(*(float *)(iVar4 + 0xc + param_4) * DAT_0059fec8 +
                                 *(float *)(iVar1 + ((param_3 & 3) + (param_2 & 3) * 8) * 4 +
                                           (uVar2 & 3) * 4));
      puVar3 = puVar3 + 1;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x10;
    } while (uVar2 < *(uint *)(param_1 + 0x1058));
  }
  return;
}


