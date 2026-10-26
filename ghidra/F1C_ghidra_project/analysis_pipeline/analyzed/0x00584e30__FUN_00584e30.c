// Function: FUN_00584e30 @ 00584e30
// Size (bytes): 247


bool __thiscall FUN_00584e30(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  DWORD DVar5;
  int iVar6;
  bool bVar7;
  
  bVar7 = false;
  if ((*(HANDLE *)(param_1 + 0x570) != (HANDLE)0x0) &&
     ((DVar5 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x570),*(DWORD *)(param_1 + 0x574)),
      DVar5 == 0 || (DVar5 == 0x80)))) {
    piVar1 = *(int **)(param_1 + 0x560);
    iVar6 = 0;
    if (piVar1 != (int *)0x0) {
      *(undefined1 *)(piVar1 + 2) = 0;
      iVar6 = *piVar1;
      if (iVar6 != 0) {
        piVar4 = *(int **)(param_1 + 0x560);
        piVar1 = (int *)0x0;
        while (piVar3 = piVar4, piVar3 != (int *)0x0) {
          if (*piVar3 == iVar6) {
            if (piVar3 == *(int **)(param_1 + 0x568)) {
              *(int *)(param_1 + 0x568) = piVar3[1];
            }
            if (piVar1 == (int *)0x0) {
              *(int *)(param_1 + 0x560) = piVar3[1];
            }
            else {
              piVar1[1] = piVar3[1];
            }
            if (*(int **)(param_1 + 0x564) == piVar3) {
              *(int **)(param_1 + 0x564) = piVar1;
            }
            *(int *)(param_1 + 0x56c) = *(int *)(param_1 + 0x56c) + -1;
            if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
              FUN_005867b0();
              FUN_00587bcf(iVar2);
            }
            FUN_00587bcf(piVar3);
            goto LAB_00584e8f;
          }
          piVar1 = piVar3;
          piVar4 = (int *)piVar3[1];
        }
      }
      iVar6 = 0;
    }
LAB_00584e8f:
    bVar7 = iVar6 != 0;
    *param_2 = iVar6;
    if (*(HANDLE *)(param_1 + 0x570) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x570));
    }
  }
  return bVar7;
}


