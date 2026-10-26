// Function: FUN_004614f0 @ 004614f0
// Size (bytes): 52


void __thiscall FUN_004614f0(int param_1,byte param_2,char param_3)

{
  if (param_3 != '\0') {
    *(byte *)(param_1 + 0x88) = *(byte *)(param_1 + 0x88) | param_2;
    return;
  }
  *(byte *)(param_1 + 0x88) = *(byte *)(param_1 + 0x88) & ~param_2;
  return;
}


