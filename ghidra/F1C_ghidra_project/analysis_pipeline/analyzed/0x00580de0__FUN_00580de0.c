// Function: FUN_00580de0 @ 00580de0
// Size (bytes): 642


undefined1 __thiscall FUN_00580de0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint unaff_EDI;
  undefined1 *puVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined1 local_2c [24];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = -1;
  puStack_8 = &LAB_0059cae8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0057b780(0,0,0);
  puVar9 = local_2c;
  local_4 = 0;
  cVar2 = (**(code **)(*param_1 + 0xd0))(param_2);
  if (cVar2 == '\0') goto LAB_0058103b;
  iVar3 = (**(code **)(*param_1 + 0x58))();
  FUN_00586800(0,7,1,2,0xffffffff);
  (**(code **)(**(int **)(iVar3 + 0x48) + 0xc))(local_4);
  FUN_0057d8d0(iVar3,0);
  (**(code **)(*param_1 + 0x5c))(iVar3);
  piVar7 = param_1 + 0x2b2;
  if (((HANDLE)param_1[0x2b6] == (HANDLE)0x0) ||
     ((DVar4 = WaitForSingleObject((HANDLE)param_1[0x2b6],param_1[0x2b7]), DVar4 != 0 &&
      (DVar4 != 0x80)))) {
    piVar7 = (int *)0x0;
  }
  piVar6 = (int *)*piVar7;
  piVar7[2] = (int)piVar6;
  if ((piVar6 != (int *)0x0) && (iVar3 = *piVar6, iVar3 != 0)) {
    while( true ) {
      iVar5 = FUN_005871f0();
      if (iVar5 == local_4) {
        iVar5 = FUN_00587220();
        if (iVar5 == 2) {
          puVar9 = (undefined1 *)0x10000;
        }
        if (*(int *)(iVar3 + 0x1c) != 0) {
          *(undefined1 *)(*(int *)(iVar3 + 0x1c) + 0x28) = 1;
          FUN_0057b6c0(0);
        }
        piVar6 = (int *)0x0;
        piVar8 = (int *)*piVar7;
        if ((int *)*piVar7 == (int *)0x0) goto LAB_00580f6b;
        goto LAB_00580f14;
      }
      if (piVar7[2] == 0) break;
      piVar6 = *(int **)(piVar7[2] + 4);
      piVar7[2] = (int)piVar6;
      if ((piVar6 == (int *)0x0) || (iVar3 = *piVar6, iVar3 == 0)) break;
    }
  }
  goto LAB_00580f70;
  while (piVar1 = piVar8 + 1, piVar6 = piVar8, piVar8 = (int *)*piVar1, (int *)*piVar1 != (int *)0x0
        ) {
LAB_00580f14:
    if (*piVar8 == iVar3) {
      if (piVar8 == (int *)piVar7[2]) {
        piVar7[2] = piVar8[1];
      }
      if (piVar6 == (int *)0x0) {
        *piVar7 = piVar8[1];
      }
      else {
        piVar6[1] = piVar8[1];
      }
      if ((int *)piVar7[1] == piVar8) {
        piVar7[1] = (int)piVar6;
      }
      piVar7[3] = piVar7[3] + -1;
      if (((char)piVar8[2] != '\0') && ((undefined4 *)*piVar8 != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)*piVar8)(1);
      }
      FUN_00587bcf(piVar8);
      break;
    }
  }
LAB_00580f6b:
  puVar9 = (undefined1 *)CONCAT13(1,(int3)puVar9);
LAB_00580f70:
  piVar6 = (int *)*piVar7;
  piVar7[2] = (int)piVar6;
  if (piVar6 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar6;
  }
  uVar11 = unaff_EDI & 0xffffff00;
  if (iVar3 != 0) {
    while( true ) {
      FUN_00587200(uVar11);
      FUN_00587230(1);
      uVar11 = CONCAT31((int3)(uVar11 >> 8),(char)uVar11 + '\x01');
      if (piVar7[2] == 0) break;
      piVar6 = *(int **)(piVar7[2] + 4);
      piVar7[2] = (int)piVar6;
      if ((piVar6 == (int *)0x0) || (*piVar6 == 0)) break;
    }
  }
  if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
    ReleaseMutex((HANDLE)param_1[0x2b6]);
  }
  iVar3 = FUN_00585d20();
  if (iVar3 == 4) {
    iVar3 = (**(code **)(*param_1 + 0x58))();
    FUN_00586800(0,9,1,2,0xffffffff);
    FUN_00586a00(&local_4,4);
    *(undefined1 *)(*(int *)(iVar3 + 0x48) + 4) = 1;
    FUN_0057d8d0(iVar3,0);
    (**(code **)(*param_1 + 0x5c))(iVar3);
  }
  if (((char)((uint)puVar9 >> 0x10) != '\0') && (iVar3 = FUN_00585d20(), iVar3 == 3)) {
    (**(code **)(*param_1 + 0x74))();
  }
LAB_0058103b:
  uVar10 = (undefined1)((uint)puVar9 >> 0x18);
  pvStack_c = (void *)0xffffffff;
  FUN_0057b7f0();
  ExceptionList = pvStack_14;
  return uVar10;
}


