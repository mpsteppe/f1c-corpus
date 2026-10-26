// Function: FUN_0049c670 @ 0049c670
// Strings:  [ %d/%d,  %d/--]


undefined4 FUN_0049c670(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_007c54e0 + 0x403c) + 1;
  if (DAT_008acf8c < iVar1) {
    iVar1 = DAT_008acf8c;
  }
  if (DAT_008acf8c == 0x7fffffff) {
    FUN_0058815f(param_1,s__d____005cce88,iVar1);
    return 0;
  }
  FUN_0058815f(param_1,s__d__d_005cce80,iVar1,DAT_008acf8c);
  return 0;
}


