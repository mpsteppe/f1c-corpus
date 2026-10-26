// Function: FUN_004b15d0 @ 004b15d0
// Size (bytes): 44


bool __thiscall FUN_004b15d0(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0x1f78) != 5) {
    return true;
  }
  return (*(uint *)(param_1 + 0x2ab4) & 1 << (param_2 & 0x1f)) != 0;
}


