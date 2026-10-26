// Function: FUN_004c4bb0 @ 004c4bb0
// Size (bytes): 256


undefined4 __thiscall FUN_004c4bb0(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if ((*param_2 != 0) && (0 < param_3)) {
    piVar3 = *(int **)(param_1 + 8);
    *(int **)(param_1 + 0x10) = piVar3;
    if ((piVar3 != (int *)0x0) && (iVar5 = *piVar3, iVar5 != 0)) {
LAB_004c4bd7:
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      iVar6 = 0;
      if (0 < param_3) {
        do {
          iVar2 = FUN_00566810();
          if (iVar2 != 0) {
            piVar3 = *(int **)(param_1 + 8);
            piVar4 = (int *)0x0;
            if (piVar3 != (int *)0x0) goto LAB_004c4c50;
            goto LAB_004c4ca8;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_3);
      }
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      piVar3 = *(int **)(param_1 + 0x10);
      goto LAB_004c4c30;
    }
  }
LAB_004c4c3a:
  return *(undefined4 *)(param_1 + 0x14);
LAB_004c4c50:
  if (*piVar3 != iVar5) goto code_r0x004c4c54;
  if (piVar3 == *(int **)(param_1 + 0x10)) {
    *(int *)(param_1 + 0x10) = piVar3[1];
  }
  if (piVar4 == (int *)0x0) {
    *(int *)(param_1 + 8) = piVar3[1];
  }
  else {
    piVar4[1] = piVar3[1];
  }
  if (*(int **)(param_1 + 0xc) == piVar3) {
    *(int **)(param_1 + 0xc) = piVar4;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  if ((char)piVar3[2] != '\0') {
    FUN_00587bcf(*piVar3);
  }
  FUN_00587bcf(piVar3);
LAB_004c4ca8:
  piVar3 = *(int **)(param_1 + 8);
  *(int **)(param_1 + 0x10) = piVar3;
  goto LAB_004c4c30;
code_r0x004c4c54:
  piVar1 = piVar3 + 1;
  piVar4 = piVar3;
  piVar3 = (int *)*piVar1;
  if ((int *)*piVar1 == (int *)0x0) goto code_r0x004c4c5d;
  goto LAB_004c4c50;
code_r0x004c4c5d:
  piVar3 = *(int **)(param_1 + 8);
  *(int **)(param_1 + 0x10) = piVar3;
LAB_004c4c30:
  if ((piVar3 == (int *)0x0) || (iVar5 = *piVar3, iVar5 == 0)) goto LAB_004c4c3a;
  goto LAB_004c4bd7;
}


