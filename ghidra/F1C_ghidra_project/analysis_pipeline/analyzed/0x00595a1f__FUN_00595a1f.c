// Function: FUN_00595a1f @ 00595a1f
// Size (bytes): 66


undefined4 FUN_00595a1f(uint param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < DAT_008d4a20) &&
     ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_008d4920)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  puVar1 = (undefined4 *)FUN_0058afcf();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0058afd8();
  *puVar1 = 0;
  return 0xffffffff;
}


