// Function: FUN_005819c0 @ 005819c0
// Size (bytes): 82


void __fastcall FUN_005819c0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && ((int *)*piVar2 != (int *)0x0)) {
      (**(code **)(*(int *)*piVar2 + 4))(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


