// Function: FUN_00582ce0 @ 00582ce0
// Size (bytes): 209


void __fastcall FUN_00582ce0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059cd90;
  local_4 = 1;
  piVar3 = (int *)param_1[4];
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && ((int *)*piVar3 != (int *)0x0)) {
      (**(code **)(*(int *)*piVar3 + 4))(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_4 = 0xffffffff;
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if ((int *)*piVar2 != (int *)0x0) {
        (**(code **)(*(int *)*piVar2 + 4))(3);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ExceptionList = pvStack_c;
  return;
}


