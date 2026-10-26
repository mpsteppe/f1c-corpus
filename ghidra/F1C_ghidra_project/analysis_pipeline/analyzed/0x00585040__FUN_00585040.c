// Function: FUN_00585040 @ 00585040
// Size (bytes): 236


void __fastcall FUN_00585040(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  DWORD DVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *local_4;
  
  local_4 = param_1;
  cVar4 = FUN_00584cd0(&local_4);
  while (cVar4 != '\0') {
    (**(code **)(*param_1 + 0x5c))(local_4);
    cVar4 = FUN_00584cd0(&local_4);
  }
  piVar8 = param_1 + 0x166;
  if (((HANDLE)param_1[0x16a] == (HANDLE)0x0) ||
     ((DVar5 = WaitForSingleObject((HANDLE)param_1[0x16a],param_1[0x16b]), DVar5 != 0 &&
      (DVar5 != 0x80)))) {
    piVar8 = (int *)0x0;
  }
  do {
    do {
      if (((piVar8[3] < 1) || (piVar2 = (int *)*piVar8, piVar2 == (int *)0x0)) || (*piVar2 == 0)) {
        if ((HANDLE)param_1[0x16a] != (HANDLE)0x0) {
          ReleaseMutex((HANDLE)param_1[0x16a]);
        }
        return;
      }
      piVar6 = (int *)0x0;
      piVar7 = piVar2;
    } while (piVar2 == (int *)0x0);
    do {
      if (*piVar7 == *piVar2) {
        if (piVar7 == (int *)piVar8[2]) {
          piVar8[2] = piVar7[1];
        }
        if (piVar6 == (int *)0x0) {
          *piVar8 = piVar7[1];
        }
        else {
          piVar6[1] = piVar7[1];
        }
        if ((int *)piVar8[1] == piVar7) {
          piVar8[1] = (int)piVar6;
        }
        piVar8[3] = piVar8[3] + -1;
        if (((char)piVar7[2] != '\0') && (iVar3 = *piVar7, iVar3 != 0)) {
          FUN_005867b0();
          FUN_00587bcf(iVar3);
        }
        FUN_00587bcf(piVar7);
        break;
      }
      piVar1 = piVar7 + 1;
      piVar6 = piVar7;
      piVar7 = (int *)*piVar1;
    } while ((int *)*piVar1 != (int *)0x0);
  } while( true );
}


