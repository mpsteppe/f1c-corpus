// Function: FUN_00489a10 @ 00489a10
// Size (bytes): 60


undefined1 * __thiscall FUN_00489a10(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x90);
  if (-1 < param_2) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x8c)) {
      if (param_2 == 0) {
        if (iVar1 == 0) {
          return (undefined1 *)0x0;
        }
        if (*(undefined1 **)(iVar1 + 0xb0) == (undefined1 *)0x0) {
          return &DAT_005ea438;
        }
        return *(undefined1 **)(iVar1 + 0xb0);
      }
      param_2 = param_2 + -1;
    }
  }
  return (undefined1 *)0x0;
}


