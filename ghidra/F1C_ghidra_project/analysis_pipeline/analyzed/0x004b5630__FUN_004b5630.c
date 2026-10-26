// Function: FUN_004b5630 @ 004b5630
// Size (bytes): 292


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b5630(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  void *pvVar6;
  int iVar7;
  
  piVar1 = *(int **)(param_1 + 0x20);
  *(int **)(param_1 + 0x28) = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar7 = *piVar1;
    while (iVar7 != 0) {
      cVar5 = FUN_005001d0();
      if (((cVar5 != '\0') && (cVar5 = FUN_005001f0(), cVar5 != '\0')) ||
         (ABS(*(float *)(iVar7 + 0x370) - *(float *)(param_1 + 0x30)) <= (float)_DAT_005acd30)) {
        if (*(int *)(param_1 + 0x28) != 0) {
          *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 4);
        }
      }
      else {
        piVar4 = *(int **)(param_1 + 0x20);
        piVar1 = (int *)0x0;
        while (piVar3 = piVar4, piVar3 != (int *)0x0) {
          if (*piVar3 == iVar7) {
            if (piVar3 == *(int **)(param_1 + 0x28)) {
              *(int *)(param_1 + 0x28) = piVar3[1];
            }
            if (piVar1 == (int *)0x0) {
              *(int *)(param_1 + 0x20) = piVar3[1];
            }
            else {
              piVar1[1] = piVar3[1];
            }
            if (*(int **)(param_1 + 0x24) == piVar3) {
              *(int **)(param_1 + 0x24) = piVar1;
            }
            *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
            if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
              FUN_004b0170();
              FUN_00587bcf(iVar2);
            }
            FUN_00587bcf(piVar3);
            break;
          }
          piVar1 = piVar3;
          piVar4 = (int *)piVar3[1];
        }
        pvVar6 = operator_new(0xc);
        if (pvVar6 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_004bac20(iVar7,0);
        }
        if (*(int *)(param_1 + 0x10) == 0) {
          *(int *)(param_1 + 0x14) = iVar7;
          *(int *)(param_1 + 0x18) = iVar7;
          *(int *)(param_1 + 0x10) = iVar7;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        }
        else {
          *(int *)(iVar7 + 4) = *(int *)(param_1 + 0x10);
          *(int *)(param_1 + 0x10) = iVar7;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        }
      }
      if (*(int **)(param_1 + 0x28) == (int *)0x0) {
        return;
      }
      iVar7 = **(int **)(param_1 + 0x28);
    }
  }
  return;
}


