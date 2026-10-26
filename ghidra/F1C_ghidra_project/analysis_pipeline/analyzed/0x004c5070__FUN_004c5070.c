// Function: FUN_004c5070 @ 004c5070
// Size (bytes): 106


int FUN_004c5070(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int extraout_ECX;
  int extraout_EDX;
  int iVar3;
  undefined8 uVar4;
  
  if (param_1 < 0) {
    return 0;
  }
  uVar4 = FUN_005871f0();
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 <= iVar3) {
    return 0;
  }
  FUN_004c6760(iVar3);
  if (extraout_EDX < *(int *)(extraout_ECX + 0x14)) {
    puVar1 = *(undefined4 **)(extraout_ECX + 8);
    for (iVar3 = extraout_EDX; 0 < iVar3; iVar3 = iVar3 + -1) {
      if (puVar1 == (undefined4 *)0x0) goto LAB_004c50b0;
      puVar1 = (undefined4 *)puVar1[1];
    }
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = (int *)*puVar1;
      goto LAB_004c50b6;
    }
  }
LAB_004c50b0:
  piVar2 = (int *)0x0;
LAB_004c50b6:
  iVar3 = *piVar2;
  if ((-1 < iVar3) && (iVar3 < DAT_008ac390)) {
    return iVar3 * 0x424 + DAT_008ac394;
  }
  return 0;
}


