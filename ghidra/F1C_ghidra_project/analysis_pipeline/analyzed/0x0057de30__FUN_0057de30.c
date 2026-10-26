// Function: FUN_0057de30 @ 0057de30
// Size (bytes): 440


uint __thiscall FUN_0057de30(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  piVar6 = param_1 + 0x2ab;
  bVar1 = false;
  if (((HANDLE)param_1[0x2af] == (HANDLE)0x0) ||
     ((DVar5 = WaitForSingleObject((HANDLE)param_1[0x2af],param_1[0x2b0]), DVar5 != 0 &&
      (DVar5 != 0x80)))) {
    piVar6 = (int *)0x0;
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*piVar6;
    puVar3 = (undefined4 *)0x0;
    while (puVar2 = puVar4, puVar2 != (undefined4 *)0x0) {
      if ((undefined4 *)*puVar2 == param_2) {
        if (puVar2 == (undefined4 *)piVar6[2]) {
          piVar6[2] = puVar2[1];
        }
        if (puVar3 == (undefined4 *)0x0) {
          *piVar6 = puVar2[1];
        }
        else {
          puVar3[1] = puVar2[1];
        }
        if ((undefined4 *)piVar6[1] == puVar2) {
          piVar6[1] = (int)puVar3;
        }
        piVar6[3] = piVar6[3] + -1;
        FUN_00491e40();
        FUN_00587bcf(puVar2);
        break;
      }
      puVar3 = puVar2;
      puVar4 = (undefined4 *)puVar2[1];
    }
    iVar7 = FUN_0057b2e0();
    if (iVar7 != 0) {
      if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
        WaitForSingleObject((HANDLE)param_1[0x2b6],param_1[0x2b7]);
      }
      iVar7 = FUN_0057b2e0();
      *(undefined4 *)(iVar7 + 0x1c) = 0;
      if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
        ReleaseMutex((HANDLE)param_1[0x2b6]);
      }
      bVar1 = true;
      FUN_0057b2e0();
      local_4 = FUN_005871f0();
    }
    uVar10 = 1;
    uVar8 = FUN_0057b6b0(1);
    FUN_0057c8e0(uVar8,uVar10);
    if ((HANDLE)param_1[0x2fb] != (HANDLE)0x0) {
      WaitForSingleObject((HANDLE)param_1[0x2fb],param_1[0x2fc]);
    }
    FUN_0057b530();
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0xffffffff;
    param_2[9] = 0;
    *(undefined1 *)(param_2 + 10) = 0;
    param_2[0xb] = 0;
    param_2[0xc] = 0;
    *(undefined2 *)(param_2 + 0xd) = 0;
    FUN_00583210(param_2,0);
    if ((HANDLE)param_1[0x2fb] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)param_1[0x2fb]);
    }
  }
  uVar9 = 0;
  if ((HANDLE)param_1[0x2af] != (HANDLE)0x0) {
    uVar9 = ReleaseMutex((HANDLE)param_1[0x2af]);
  }
  if (bVar1) {
    uVar9 = (**(code **)(*param_1 + 0x94))(local_4);
  }
  return uVar9 & 0xffffff00;
}


