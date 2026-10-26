// Function: FUN_005575f0 @ 005575f0
// Size (bytes): 54


undefined4 __fastcall FUN_005575f0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x400) != 0) {
      return 0;
    }
    iVar2 = FUN_00558310();
  }
  else {
    if ((uVar1 & 0x400) != 0) {
      return 0;
    }
    iVar2 = FUN_0047abb0();
  }
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x400;
    return 0;
  }
  return 0xffffffff;
}


