// Function: FUN_00548eb0 @ 00548eb0
// Size (bytes): 358


void __fastcall FUN_00548eb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xe8);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      if (iVar1 != 0) {
        FUN_004b0170();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_004b0170();
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  iVar1 = *(int *)(param_1 + 0xf0);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x34); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if (iVar1 != 0) {
        FUN_004b0170();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_004b0170();
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0xf0) = 0;
  }
  iVar1 = *(int *)(param_1 + 0xf8);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      if (iVar1 != 0) {
        FUN_004b0170();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_004b0170();
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  iVar1 = *(int *)(param_1 + 0xfc);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      if (iVar1 != 0) {
        FUN_004b0170();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_004b0170();
    FUN_00587bcf(iVar1);
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  iVar1 = *(int *)(param_1 + 0xec);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      FUN_00549110(iVar1);
      iVar1 = iVar2;
    }
    FUN_00549110(iVar1);
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  return;
}


