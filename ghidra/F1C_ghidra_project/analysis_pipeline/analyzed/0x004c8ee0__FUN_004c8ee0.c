// Function: FUN_004c8ee0 @ 004c8ee0
// Size (bytes): 46


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c8ee0(void)

{
  if ((DAT_008ac4dc & 1) == 0) {
    DAT_008ac4dc = DAT_008ac4dc | 1;
    _rand();
    _DAT_008ac4d8 = 1;
    return 1;
  }
  _DAT_008ac4d8 = _DAT_008ac4d8 + 1;
  return 1;
}


