// Function: FUN_00581c20 @ 00581c20
// Size (bytes): 278


void __fastcall FUN_00581c20(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  BOOL BVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cb70;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if ((*(char *)(param_1 + 10) != '\0') &&
     (ExceptionList = &local_c, BVar5 = CloseHandle((HANDLE)param_1[8]), BVar5 != 0)) {
    param_1[8] = 0;
  }
  local_4 = 1;
  piVar4 = (int *)param_1[4];
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (iVar2 = *piVar4, iVar2 != 0)) {
      FUN_005867b0();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar1;
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_4 = 0xffffffff;
  piVar4 = (int *)*param_1;
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (piVar3 = (int *)*piVar4, piVar3 != (int *)0x0)) {
      iVar2 = *piVar3;
      if (iVar2 != 0) {
        FUN_0058a5f7(iVar2,0x54,*(undefined4 *)(iVar2 + -4),FUN_005867b0);
        FUN_00587bcf(iVar2 + -4);
      }
      FUN_00587bcf(piVar3);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ExceptionList = local_c;
  return;
}


