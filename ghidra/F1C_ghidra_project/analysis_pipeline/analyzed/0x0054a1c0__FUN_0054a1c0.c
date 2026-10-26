// Function: FUN_0054a1c0 @ 0054a1c0
// Size (bytes): 50


void FUN_0054a1c0(uint param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_008b8ee0 = DAT_008b8ee0 & ~param_1;
    return;
  }
  DAT_008b8ee0 = DAT_008b8ee0 | param_1;
  return;
}


