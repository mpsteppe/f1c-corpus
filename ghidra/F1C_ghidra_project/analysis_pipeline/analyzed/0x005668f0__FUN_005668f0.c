// Function: FUN_005668f0 @ 005668f0
// Size (bytes): 74


undefined4 FUN_005668f0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0058ba75(param_1,0);
  if (iVar1 != -1) {
    iVar1 = FUN_0058ba75(param_1,6);
    if (iVar1 != 0) {
      FUN_0058ba36(param_1,0x180);
      iVar1 = FUN_0058ba75(param_1,6);
      if (iVar1 != 0) {
        return 0;
      }
    }
  }
  return 1;
}


