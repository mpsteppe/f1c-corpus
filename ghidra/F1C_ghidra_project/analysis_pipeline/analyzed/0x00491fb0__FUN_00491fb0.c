// Function: FUN_00491fb0 @ 00491fb0
// Size (bytes): 117


undefined4 __fastcall FUN_00491fb0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_005351d0(0x100);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 1;
    iVar1 = FUN_005651b0();
    if ((iVar1 != 1) && ((iVar1 < 3 || (4 < iVar1)))) break;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
    iVar1 = FUN_005351d0(0x100);
  }
  return 1;
}


