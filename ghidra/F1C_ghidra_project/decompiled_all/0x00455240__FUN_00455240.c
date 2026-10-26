// Function: FUN_00455240 @ 00455240
// Strings:  [-EMPTY-]


char * FUN_00455240(uint param_1)

{
  char *pcVar1;
  
  pcVar1 = &DAT_005ea438;
  if (param_1 < 0x6e) {
    pcVar1 = s__EMPTY__005c44b0 + param_1 * 9;
  }
  return pcVar1;
}


