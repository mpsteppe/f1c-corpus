// Function: FUN_00581ee0 @ 00581ee0
// Size (bytes): 233


void __fastcall FUN_00581ee0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  BOOL BVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cbf0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((*(char *)(param_1 + 10) != '\0') &&
     (ExceptionList = &pvStack_c, BVar4 = CloseHandle((HANDLE)param_1[8]), BVar4 != 0)) {
    param_1[8] = 0;
  }
  local_4 = 1;
  piVar3 = (int *)param_1[4];
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


