// Function: FUN_00582f60 @ 00582f60
// Size (bytes): 111


void __fastcall FUN_00582f60(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  void **ppvVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059cdc8;
  local_4 = 0;
  ppvVar3 = &local_c;
  piVar2 = (int *)*param_1;
  local_c = ExceptionList;
  while (ExceptionList = ppvVar3, piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    FUN_00587bcf(piVar2);
    ppvVar3 = ExceptionList;
    piVar2 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ExceptionList = local_c;
  return;
}


