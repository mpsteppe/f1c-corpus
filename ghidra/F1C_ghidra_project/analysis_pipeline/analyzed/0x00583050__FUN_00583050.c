// Function: FUN_00583050 @ 00583050
// Size (bytes): 112


void __fastcall FUN_00583050(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  void **ppvVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059ce08;
  local_4 = 0;
  ppvVar3 = &local_c;
  piVar2 = (int *)*param_1;
  local_c = ExceptionList;
  while (ExceptionList = ppvVar3, piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && ((int *)*piVar2 != (int *)0x0)) {
      (**(code **)(*(int *)*piVar2 + 4))(1);
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


