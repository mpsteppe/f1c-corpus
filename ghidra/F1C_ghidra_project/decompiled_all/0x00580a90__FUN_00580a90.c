// Function: FUN_00580a90 @ 00580a90
// Strings:  [Leaving Current Session]


void __fastcall FUN_00580a90(int *param_1)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  code *pcVar5;
  int *piVar6;
  
  iVar2 = FUN_00585d20();
  if ((iVar2 != 0) && (iVar2 != 1)) {
    FUN_00585cd0(0);
    FUN_00585680();
    iVar2 = (**(code **)(*param_1 + 0x58))();
    FUN_00586800(0,7,1,2,0xffffffff);
    *(undefined1 *)(*(int *)(iVar2 + 0x48) + 4) = 1;
    FUN_0057d8d0(iVar2,0);
    (**(code **)(*param_1 + 0x5c))(iVar2);
    FUN_00585040();
    FUN_00585130();
    pcVar5 = WaitForSingleObject_exref;
    piVar6 = param_1 + 0x2b2;
    if (((HANDLE)param_1[0x2b6] == (HANDLE)0x0) ||
       ((DVar3 = WaitForSingleObject((HANDLE)param_1[0x2b6],param_1[0x2b7]), DVar3 != 0 &&
        (DVar3 != 0x80)))) {
      piVar6 = (int *)0x0;
    }
    piVar1 = (int *)*piVar6;
    piVar6[2] = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      while (iVar2 != 0) {
        iVar2 = *param_1;
        uVar4 = FUN_005871f0();
        (**(code **)(iVar2 + 0x94))(uVar4);
        piVar1 = (int *)*piVar6;
        piVar6[2] = (int)piVar1;
        pcVar5 = WaitForSingleObject_exref;
        if (piVar1 == (int *)0x0) break;
        iVar2 = *piVar1;
      }
    }
    if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[0x2b6]);
    }
    piVar6 = param_1 + 0x2ab;
    if ((param_1[0x2af] == 0) ||
       ((iVar2 = (*pcVar5)(param_1[0x2af],param_1[0x2b0]), iVar2 != 0 && (iVar2 != 0x80)))) {
      piVar6 = (int *)0x0;
    }
    piVar1 = (int *)*piVar6;
    piVar6[2] = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      while (iVar2 != 0) {
        FUN_0057de30(iVar2,s_Leaving_Current_Session_005e632c);
        piVar1 = (int *)*piVar6;
        piVar6[2] = (int)piVar1;
        if (piVar1 == (int *)0x0) break;
        iVar2 = *piVar1;
      }
    }
    if ((HANDLE)param_1[0x2af] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[0x2af]);
    }
    if (param_1[400] != 0) {
      (*pcVar5)(param_1[400],param_1[0x191]);
    }
    FUN_005870e0();
    if ((HANDLE)param_1[400] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[400]);
    }
  }
  return;
}


