// Function: FUN_00584cd0 @ 00584cd0
// Size (bytes): 247


bool __thiscall FUN_00584cd0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  DWORD DVar5;
  int iVar6;
  bool bVar7;
  
  bVar7 = false;
  if ((*(HANDLE *)(param_1 + 0x554) != (HANDLE)0x0) &&
     ((DVar5 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x554),*(DWORD *)(param_1 + 0x558)),
      DVar5 == 0 || (DVar5 == 0x80)))) {
    piVar1 = *(int **)(param_1 + 0x544);
    iVar6 = 0;
    if (piVar1 != (int *)0x0) {
      *(undefined1 *)(piVar1 + 2) = 0;
      iVar6 = *piVar1;
      if (iVar6 != 0) {
        piVar4 = *(int **)(param_1 + 0x544);
        piVar1 = (int *)0x0;
        while (piVar3 = piVar4, piVar3 != (int *)0x0) {
          if (*piVar3 == iVar6) {
            if (piVar3 == *(int **)(param_1 + 0x54c)) {
              *(int *)(param_1 + 0x54c) = piVar3[1];
            }
            if (piVar1 == (int *)0x0) {
              *(int *)(param_1 + 0x544) = piVar3[1];
            }
            else {
              piVar1[1] = piVar3[1];
            }
            if (*(int **)(param_1 + 0x548) == piVar3) {
              *(int **)(param_1 + 0x548) = piVar1;
            }
            *(int *)(param_1 + 0x550) = *(int *)(param_1 + 0x550) + -1;
            if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
              FUN_005867b0();
              FUN_00587bcf(iVar2);
            }
            FUN_00587bcf(piVar3);
            goto LAB_00584d2f;
          }
          piVar1 = piVar3;
          piVar4 = (int *)piVar3[1];
        }
      }
      iVar6 = 0;
    }
LAB_00584d2f:
    bVar7 = iVar6 != 0;
    *param_2 = iVar6;
    if (*(HANDLE *)(param_1 + 0x554) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x554));
    }
  }
  return bVar7;
}


