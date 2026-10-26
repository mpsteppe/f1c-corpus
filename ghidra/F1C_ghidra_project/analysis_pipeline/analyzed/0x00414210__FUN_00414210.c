// Function: FUN_00414210 @ 00414210
// Size (bytes): 351


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00414210(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_004150c0();
  piVar3 = DAT_005ea608;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_00414420();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  DAT_005ea608 = (int *)0x0;
  _DAT_005ea60c = 0;
  _DAT_005ea610 = 0;
  _DAT_005ea614 = 0;
  piVar3 = DAT_005ea5f8;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_00414380();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  DAT_005ea5f8 = (int *)0x0;
  _DAT_005ea5fc = 0;
  _DAT_005ea600 = 0;
  _DAT_005ea604 = 0;
  piVar3 = DAT_005ea5e8;
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
  DAT_005ea5e8 = (int *)0x0;
  _DAT_005ea5ec = 0;
  _DAT_005ea5f0 = 0;
  _DAT_005ea5f4 = 0;
  return;
}


