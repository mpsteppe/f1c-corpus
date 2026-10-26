// Function: FUN_0054a200 @ 0054a200
// Size (bytes): 50


void FUN_0054a200(uint param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_008b8e34 = DAT_008b8e34 & ~param_1;
    return;
  }
  DAT_008b8e34 = DAT_008b8e34 | param_1;
  return;
}


