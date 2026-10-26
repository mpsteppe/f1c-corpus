// Function: FUN_00431c70 @ 00431c70
// Size (bytes): 201


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00431c70(void)

{
  int iVar1;
  int iVar2;
  
  FUN_004331a0();
  iVar2 = DAT_007c7418;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    FUN_00582290();
    FUN_00587bcf(iVar2);
    iVar2 = iVar1;
  }
  DAT_007c7418 = 0;
  _DAT_007c741c = 0;
  _DAT_007c7420 = 0;
  _DAT_007c7424 = 0;
  iVar2 = DAT_007c7404;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    FUN_00434240();
    FUN_00587bcf(iVar2);
    iVar2 = iVar1;
  }
  DAT_007c7404 = 0;
  _DAT_007c7408 = 0;
  _DAT_007c740c = 0;
  _DAT_007c7410 = 0;
  if (DAT_007c73f8 != 0) {
    FUN_00587bcf(DAT_007c73f8);
  }
  if (DAT_007c73f0 != 0) {
    FUN_00587bcf(DAT_007c73f0);
  }
  if (DAT_007c73e8 != 0) {
    FUN_00587bcf(DAT_007c73e8);
  }
  return;
}


