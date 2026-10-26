// Function: FUN_00589a35 @ 00589a35
// Size (bytes): 111


int FUN_00589a35(int param_1)

{
  bool bVar1;
  
  if (DAT_008d3f38 == 0) {
    if ((0x60 < param_1) && (param_1 < 0x7b)) {
      return param_1 + -0x20;
    }
  }
  else {
    InterlockedIncrement(&DAT_008d5a5c);
    bVar1 = DAT_008d5a58 != 0;
    if (bVar1) {
      InterlockedDecrement(&DAT_008d5a5c);
      FUN_0058dfea(0x13);
    }
    param_1 = FUN_00589aa4(param_1);
    if (bVar1) {
      FUN_0058e04b(0x13);
    }
    else {
      InterlockedDecrement(&DAT_008d5a5c);
    }
  }
  return param_1;
}


