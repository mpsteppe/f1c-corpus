// Function: FUN_00583f50 @ 00583f50
// Size (bytes): 374


void __fastcall FUN_00583f50(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  DWORD DVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piStack00000004;
  int local_8;
  
  local_8 = 0;
  iVar3 = __ftol();
  while( true ) {
    if (local_8 == 0) {
      piStack00000004 = (int *)(param_1 + 0x57c);
      iVar8 = param_1 + 0x560;
    }
    else {
      piStack00000004 = (int *)(param_1 + 0x598);
      iVar8 = param_1 + 0x544;
    }
    if (((HANDLE)piStack00000004[4] == (HANDLE)0x0) ||
       ((DVar4 = WaitForSingleObject((HANDLE)piStack00000004[4],piStack00000004[5]),
        piVar9 = piStack00000004, DVar4 != 0 && (DVar4 != 0x80)))) {
      piVar9 = (int *)0x0;
    }
    piVar5 = (int *)*piVar9;
    piVar9[2] = (int)piVar5;
    if ((piVar5 != (int *)0x0) && (iVar7 = *piVar5, iVar7 != 0)) break;
LAB_00584098:
    if ((HANDLE)piStack00000004[4] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)piStack00000004[4]);
    }
    local_8 = local_8 + 1;
    if (1 < local_8) {
      return;
    }
  }
  do {
    iVar6 = *(int *)(iVar7 + 0x4c) - iVar3;
    *(int *)(iVar7 + 0x4c) = iVar6;
    if ((iVar6 < 1) &&
       ((DVar4 = WaitForSingleObject(*(HANDLE *)(iVar8 + 0x10),1), DVar4 != 0x102 &&
        (DVar4 != 0xffffffff)))) {
      piVar2 = (int *)*piVar9;
      piVar5 = (int *)0x0;
      while (piVar1 = piVar2, piVar1 != (int *)0x0) {
        if (*piVar1 == iVar7) {
          if (piVar1 == (int *)piVar9[2]) {
            piVar9[2] = piVar1[1];
          }
          if (piVar5 == (int *)0x0) {
            *piVar9 = piVar1[1];
          }
          else {
            piVar5[1] = piVar1[1];
          }
          if ((int *)piVar9[1] == piVar1) {
            piVar9[1] = (int)piVar5;
          }
          piVar9[3] = piVar9[3] + -1;
          FUN_005864e0();
          FUN_00587bcf(piVar1);
          break;
        }
        piVar5 = piVar1;
        piVar2 = (int *)piVar1[1];
      }
      FUN_00586000(iVar7,0);
      if (*(HANDLE *)(iVar8 + 0x10) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)(iVar8 + 0x10));
      }
      piVar5 = (int *)piVar9[2];
    }
    else {
      if (piVar9[2] == 0) goto LAB_00584098;
      piVar5 = *(int **)(piVar9[2] + 4);
      piVar9[2] = (int)piVar5;
    }
    if ((piVar5 == (int *)0x0) || (iVar7 = *piVar5, iVar7 == 0)) goto LAB_00584098;
  } while( true );
}


