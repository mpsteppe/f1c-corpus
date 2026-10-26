// Function: FUN_0058a02c @ 0058a02c
// Size (bytes): 46


int FUN_0058a02c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0058a05a(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)(param_1 + 0xd) & 0x40) != 0) {
    iVar1 = FUN_00592891(*(undefined4 *)(param_1 + 0x10));
    return -(uint)(iVar1 != 0);
  }
  return 0;
}


