// Function: FUN_00455200 @ 00455200
// Strings:  [PAUSE, -EMPTY-]


char * FUN_00455200(uint param_1)

{
  char *pcVar1;
  
  pcVar1 = &DAT_005ea438;
  if ((int)param_1 < 0x80) {
    if (param_1 < 0x5a) {
      pcVar1 = s_PAUSE_005c4890 + param_1 * 0x10;
    }
  }
  else if (param_1 - 0x80 < 0x58) {
    return s__EMPTY__005c4e30 + (param_1 - 0x80) * 0x10;
  }
  return pcVar1;
}


