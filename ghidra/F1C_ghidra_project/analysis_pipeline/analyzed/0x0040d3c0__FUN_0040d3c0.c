// Function: FUN_0040d3c0 @ 0040d3c0
// Size (bytes): 80


void __thiscall FUN_0040d3c0(int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_007d0350 != 0) {
    iVar1 = FUN_0040cd60();
    if ((6 < param_2) && (param_2 < 0xb)) {
      if ((-1 < iVar1) && (iVar1 < 6)) {
        *(int *)(param_1 + 0x10) = iVar1;
      }
      FUN_0040cde0(param_2,0);
      *(undefined1 *)(param_1 + 0x24) = 1;
      FUN_00408420();
      return;
    }
  }
  return;
}


