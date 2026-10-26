// Function: FUN_00582a10 @ 00582a10
// Size (bytes): 248


void __fastcall FUN_00582a10(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059cd50;
  local_4 = 1;
  piVar4 = (int *)param_1[4];
  local_c = ExceptionList;
  ExceptionList = &local_c;
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


