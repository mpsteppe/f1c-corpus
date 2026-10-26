// Function: FUN_00565e20 @ 00565e20
// Size (bytes): 136


void __fastcall FUN_00565e20(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00565d50();
  param_1 = (undefined4 *)*param_1;
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[0x84] != 0) {
      FUN_00587bcf(param_1[0x84]);
    }
    piVar3 = (int *)*param_1;
    while (piVar3 != (int *)0x0) {
      piVar1 = (int *)piVar3[1];
      if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
        FUN_00414370();
        FUN_00587bcf(iVar2);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar1;
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    FUN_00587bcf(param_1);
  }
  return;
}


