// Function: FUN_004c7aa0 @ 004c7aa0
// Size (bytes): 121


void __thiscall FUN_004c7aa0(int param_1,char param_2)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    *(uint *)(param_1 + 0x48bc) = *(uint *)(param_1 + 0x48bc) & 0xfffffff9;
    FUN_004e0ed0(3);
    return;
  }
  *(uint *)(param_1 + 0x48bc) = *(uint *)(param_1 + 0x48bc) | 6;
  if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) == *(int *)(param_1 + 0x4894)) {
    uVar1 = FUN_0040c8d0();
    FUN_004e0ed0(uVar1);
    return;
  }
  FUN_004e0ed0(0);
  return;
}


