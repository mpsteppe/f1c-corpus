// Function: FUN_004c6780 @ 004c6780
// Size (bytes): 137


int FUN_004c6780(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int extraout_ECX;
  int extraout_EDX;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar3 = 0;
  if (param_1 < 0) {
    return 0;
  }
  uVar5 = FUN_005871f0();
  iVar4 = (int)((ulonglong)uVar5 >> 0x20);
  if ((int)uVar5 <= iVar4) {
    return 0;
  }
  FUN_004c6760(iVar4);
  if (*(int *)(extraout_ECX + 0x14) <= extraout_EDX) {
    return 0;
  }
  piVar2 = *(int **)(extraout_ECX + 8);
  for (iVar4 = extraout_EDX; 0 < iVar4; iVar4 = iVar4 + -1) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    piVar2 = (int *)piVar2[1];
  }
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if (*piVar2 == 0) {
    return 0;
  }
  if (extraout_EDX < *(int *)(extraout_ECX + 0x14)) {
    puVar1 = *(undefined4 **)(extraout_ECX + 8);
    for (iVar4 = extraout_EDX; 0 < iVar4; iVar4 = iVar4 + -1) {
      if (puVar1 == (undefined4 *)0x0) goto LAB_004c67e1;
      puVar1 = (undefined4 *)puVar1[1];
    }
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = (int *)*puVar1;
      goto LAB_004c67e7;
    }
  }
LAB_004c67e1:
  piVar2 = (int *)0x0;
LAB_004c67e7:
  iVar4 = *piVar2;
  if ((-1 < iVar4) && (iVar4 < DAT_008ac488)) {
    iVar3 = iVar4 * 0x18c + DAT_008ac490;
  }
  return iVar3;
}


