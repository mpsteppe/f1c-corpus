// Function: FUN_0052de00 @ 0052de00
// Size (bytes): 55


bool __fastcall FUN_0052de00(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  if (*(uint **)(param_1 + 0x24a4) == (uint *)0x0) {
    local_8 = *(uint *)(param_1 + 0x24f0);
  }
  else {
    local_8 = **(uint **)(param_1 + 0x24a4);
  }
  iVar1 = FUN_0052da30(local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                       local_8 << 0x18);
  return iVar1 == -1;
}


