// Function: FUN_00585fb0 @ 00585fb0
// Size (bytes): 77


void __fastcall FUN_00585fb0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_004b0170();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


