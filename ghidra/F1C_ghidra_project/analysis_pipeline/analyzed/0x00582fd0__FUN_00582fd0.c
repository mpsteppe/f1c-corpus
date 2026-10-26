// Function: FUN_00582fd0 @ 00582fd0
// Size (bytes): 125


void __fastcall FUN_00582fd0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void **ppvVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059cde8;
  local_4 = 0;
  ppvVar4 = &local_c;
  piVar3 = (int *)*param_1;
  local_c = ExceptionList;
  while (ExceptionList = ppvVar4, piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_005867b0();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    ppvVar4 = ExceptionList;
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ExceptionList = local_c;
  return;
}


