// Function: FUN_00557630 @ 00557630
// Size (bytes): 54


undefined4 __fastcall FUN_00557630(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x400) == 0) {
      return 0;
    }
    iVar2 = FUN_00558990();
  }
  else {
    if ((uVar1 & 0x400) == 0) {
      return 0;
    }
    iVar2 = FUN_0047abb0();
  }
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffbff;
    return 0;
  }
  return 0xffffffff;
}


