// Function: FUN_005593d0 @ 005593d0
// Size (bytes): 218


void __fastcall FUN_005593d0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x1c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      if (iVar1 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_00557470();
    FUN_00587bcf(iVar1);
    *param_1 = 0;
  }
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x1c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      if (iVar1 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_00557470();
    FUN_00587bcf(iVar1);
    param_1[1] = 0;
  }
  iVar1 = param_1[2];
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x1c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      if (iVar1 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_00557470();
    FUN_00587bcf(iVar1);
    param_1[2] = 0;
  }
  return;
}


