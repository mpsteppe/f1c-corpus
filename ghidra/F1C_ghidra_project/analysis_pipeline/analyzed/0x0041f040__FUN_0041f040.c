// Function: FUN_0041f040 @ 0041f040
// Size (bytes): 39


undefined4 __fastcall FUN_0041f040(int param_1)

{
  int iVar1;
  
  FUN_004c2850();
  iVar1 = FUN_004c11d0();
  if ((0 < iVar1) && (param_1 != 0)) {
    return *(undefined4 *)(param_1 + 0x14 + iVar1 * 4);
  }
  return 0xffffffff;
}


