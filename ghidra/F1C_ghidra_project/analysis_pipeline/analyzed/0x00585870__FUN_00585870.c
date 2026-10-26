// Function: FUN_00585870 @ 00585870
// Size (bytes): 896


void __thiscall FUN_00585870(int *param_1,int param_2,char param_3)

{
  int *piVar1;
  bool bVar2;
  uint3 uVar3;
  uint uVar4;
  undefined1 uVar5;
  char cVar6;
  byte bVar7;
  DWORD DVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 uStack_348;
  uint uStack_344;
  int *local_340;
  int *local_33c;
  int *local_338;
  int local_334;
  int *local_330;
  int local_32c;
  undefined1 local_328 [24];
  undefined1 auStack_310 [4];
  undefined1 auStack_30c [768];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  uVar3 = (uint3)uStack_348;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d101;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00585d20();
  local_32c = FUN_00585770();
  FUN_00587030(0xffffffff,0xff,0);
  piVar12 = param_1 + 0x189;
  bVar2 = false;
  local_4 = 0;
  uStack_348 = (uint)(uint3)uStack_348;
  local_330 = piVar12;
  if (((HANDLE)param_1[400] == (HANDLE)0x0) ||
     ((DVar8 = WaitForSingleObject((HANDLE)param_1[400],param_1[0x191]), piVar9 = piVar12,
      DVar8 != 0 && (DVar8 != 0x80)))) {
    piVar9 = (int *)0x0;
  }
  if ((param_3 != '\0') || (*(char *)((int)piVar9 + 0x19) != '\0')) {
    FUN_00587370(piVar9);
    bVar2 = true;
  }
  if ((HANDLE)param_1[400] != (HANDLE)0x0) {
    ReleaseMutex((HANDLE)param_1[400]);
  }
  local_340 = (int *)0x0;
  local_33c = (int *)0x0;
  local_338 = (int *)0x0;
  local_334 = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*param_1 + 200))();
  if (bVar2) {
    uVar5 = (**(code **)(*param_1 + 0xb4))(local_32c,local_328,1);
    uStack_348 = CONCAT13(uVar5,uVar3);
  }
  iVar10 = (**(code **)(*param_1 + 0xa4))();
  uStack_344 = uStack_344 & 0xffffff00;
  piVar9 = (int *)0x0;
  if (0 < iVar10) {
    do {
      uVar4 = uStack_344;
      iVar11 = (**(code **)(*param_1 + 0x1c))();
      cVar6 = (**(code **)(*param_1 + 0xac))(uVar4,iVar11);
      if (((cVar6 == '\0') ||
          (((param_3 == '\0' && (*(char *)(iVar11 + 0x19) == '\0')) || (param_2 == local_32c)))) ||
         (iVar11 == 0)) {
        (**(code **)(*param_1 + 0x20))(iVar11);
      }
      else {
        piVar12 = operator_new(0xc);
        if (piVar12 == (int *)0x0) {
          piVar12 = (int *)0x0;
        }
        else {
          *piVar12 = iVar11;
          piVar12[1] = 0;
          *(undefined1 *)(piVar12 + 2) = 0;
        }
        if (local_340 == (int *)0x0) {
          local_334 = local_334 + 1;
          local_340 = piVar12;
          local_33c = piVar12;
          local_338 = piVar12;
        }
        else {
          local_33c[1] = (int)piVar12;
          local_334 = local_334 + 1;
          local_33c = piVar12;
        }
      }
      bVar7 = (char)uStack_344 + 1;
      uStack_344 = CONCAT31(uStack_344._1_3_,bVar7);
      piVar12 = local_330;
      piVar9 = local_340;
    } while ((int)(uint)bVar7 < iVar10);
  }
  (**(code **)(*param_1 + 0xcc))();
  auStack_30c[0] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  local_338 = piVar9;
  if (piVar9 != (int *)0x0) {
    iVar10 = *piVar9;
    while (iVar10 != 0) {
      piVar12 = (int *)0x0;
      piVar9 = local_338;
      do {
        if (*piVar9 == iVar10) {
          if (piVar9 == local_340) {
            local_338 = (int *)piVar9[1];
          }
          if (piVar12 == (int *)0x0) {
            local_340 = (int *)piVar9[1];
          }
          else {
            piVar12[1] = piVar9[1];
          }
          if (local_33c == piVar9) {
            local_33c = piVar12;
          }
          local_334 = local_334 + -1;
          FUN_00586620();
          FUN_00587bcf(piVar9);
          break;
        }
        piVar1 = piVar9 + 1;
        piVar12 = piVar9;
        piVar9 = (int *)*piVar1;
      } while ((int *)*piVar1 != (int *)0x0);
      uStack_344 = FUN_00587250();
      cVar6 = FUN_00587260(auStack_30c,&uStack_344);
      if (cVar6 != '\0') {
        iVar11 = (**(code **)(*param_1 + 0x58))();
        FUN_00586800(0,8,1,2,0xffffffff);
        (**(code **)(**(int **)(iVar11 + 0x48) + 0xc))(param_2);
        FUN_00586a00(auStack_310,uStack_348);
        FUN_00585380(iVar11);
      }
      (**(code **)(*param_1 + 0x20))(iVar10);
      local_338 = local_340;
      piVar12 = local_330;
      if (local_340 == (int *)0x0) break;
      iVar10 = *local_340;
    }
  }
  piVar9 = local_338;
  if (uStack_348._3_1_ != '\0') {
    if ((HANDLE)piVar12[7] != (HANDLE)0x0) {
      WaitForSingleObject((HANDLE)piVar12[7],piVar12[8]);
    }
    FUN_00587230(0);
    if ((HANDLE)piVar12[7] != (HANDLE)0x0) {
      ReleaseMutex((HANDLE)piVar12[7]);
    }
  }
  local_4 = local_4 & 0xffffff00;
  piVar12 = local_340;
  while (piVar12 != (int *)0x0) {
    piVar12 = (int *)piVar9[1];
    if (((char)piVar9[2] != '\0') && ((undefined4 *)*piVar9 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar9)(1);
    }
    FUN_00587bcf(piVar9);
    piVar9 = piVar12;
  }
  local_4 = 0xffffffff;
  FUN_005870d0();
  ExceptionList = pvStack_c;
  return;
}


