// Function: FUN_00547420 @ 00547420
// Size (bytes): 172


undefined4 __fastcall FUN_00547420(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0xc0); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc0)) {
      FUN_00546370();
      iVar1 = *(int *)(iVar2 + 0xbc);
      if (iVar1 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar1);
      }
      *(undefined4 *)(iVar2 + 0xbc) = 0;
      iVar1 = iVar2;
    }
    FUN_00546370();
    FUN_00557470();
    FUN_00587bcf(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (iVar1 != 0) {
        FUN_0053ab70();
        FUN_00587bcf(iVar1);
      }
      iVar1 = iVar2;
    }
    FUN_0053ab70();
    FUN_00587bcf(iVar1);
  }
  return 0;
}


