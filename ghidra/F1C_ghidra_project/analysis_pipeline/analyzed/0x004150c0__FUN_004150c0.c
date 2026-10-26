// Function: FUN_004150c0 @ 004150c0
// Size (bytes): 354


void __fastcall FUN_004150c0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_004149a0();
      FUN_00401030(iVar2 + 0x88,0x14,2,FUN_00414370);
      FUN_00401030(iVar2 + 0x60,0x14,2,FUN_00414370);
      FUN_00401030(iVar2 + 0x38,0x14,2,FUN_00414370);
      FUN_00401030(iVar2 + 0x10,0x14,2,FUN_00414370);
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
  piVar3 = (int *)param_1[4];
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_00414380();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  piVar3 = (int *)param_1[8];
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_00414fe0();
      FUN_00401030(iVar2 + 0x34,0x14,2,FUN_00414370);
      FUN_00401030(iVar2 + 0xc,0x14,2,FUN_00414370);
      FUN_00414370();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


