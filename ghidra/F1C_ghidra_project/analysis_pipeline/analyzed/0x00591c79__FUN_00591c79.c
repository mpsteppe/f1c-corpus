// Function: FUN_00591c79 @ 00591c79
// Size (bytes): 40


void FUN_00591c79(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 1) {
    puVar1 = (undefined4 *)FUN_0058afcf();
    *puVar1 = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    puVar1 = (undefined4 *)FUN_0058afcf();
    *puVar1 = 0x22;
    return;
  }
  return;
}


