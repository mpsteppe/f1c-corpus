// Function: FUN_00596007 @ 00596007
// Size (bytes): 41


byte FUN_00596007(uint param_1)

{
  if (DAT_008d4a20 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}


