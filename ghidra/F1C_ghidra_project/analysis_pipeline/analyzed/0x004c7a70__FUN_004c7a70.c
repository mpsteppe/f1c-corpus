// Function: FUN_004c7a70 @ 004c7a70
// Size (bytes): 38


void __thiscall FUN_004c7a70(int param_1,char param_2)

{
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x48bc) = *(uint *)(param_1 + 0x48bc) | 1;
    return;
  }
  *(uint *)(param_1 + 0x48bc) = *(uint *)(param_1 + 0x48bc) & 0xfffffffe;
  return;
}


