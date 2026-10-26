// Function: FUN_00418b90 @ 00418b90
// Size (bytes): 108


bool FUN_00418b90(int param_1)

{
  bool bVar1;
  
  bVar1 = true;
  switch(DAT_007d0308) {
  case 0:
    return 0x7ffffffe < *(int *)(&DAT_005bf9a0 + param_1 * 0x14);
  case 1:
    return 0x45 < *(int *)(&DAT_005bf9a0 + param_1 * 0x14);
  case 2:
    return 0x27 < *(int *)(&DAT_005bf9a0 + param_1 * 0x14);
  case 3:
    bVar1 = 0 < *(int *)(&DAT_005bf9a0 + param_1 * 0x14);
  }
  return bVar1;
}


