// Function: FUN_0052ddc0 @ 0052ddc0
// Size (bytes): 52


int __fastcall FUN_0052ddc0(uint param_1)

{
  int iVar1;
  uint local_8;
  
  local_8 = param_1;
  (**(code **)(**(int **)(param_1 + 0x2d34) + 8))(&local_8,4,0);
  iVar1 = FUN_0052da30(local_8 >> 0x18 | (local_8 & 0xff0000) >> 8 | (local_8 & 0xff00) << 8 |
                       local_8 << 0x18);
  return (iVar1 != -1) - 1;
}


