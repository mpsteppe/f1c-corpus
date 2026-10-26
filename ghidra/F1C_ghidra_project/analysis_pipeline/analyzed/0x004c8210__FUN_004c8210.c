// Function: FUN_004c8210 @ 004c8210
// Size (bytes): 172


void __fastcall FUN_004c8210(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
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
  FUN_004c8350();
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
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
  return;
}


