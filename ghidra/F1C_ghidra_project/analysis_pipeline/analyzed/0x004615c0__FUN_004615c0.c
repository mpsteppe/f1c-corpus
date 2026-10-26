// Function: FUN_004615c0 @ 004615c0
// Size (bytes): 42


void __thiscall FUN_004615c0(int param_1,byte param_2,char param_3)

{
  byte bVar1;
  
  bVar1 = (byte)(1 << (param_2 & 0x1f));
  if (param_3 != '\0') {
    *(byte *)(param_1 + 0x6e) = *(byte *)(param_1 + 0x6e) | bVar1;
    return;
  }
  *(byte *)(param_1 + 0x6e) = *(byte *)(param_1 + 0x6e) & ~bVar1;
  return;
}


