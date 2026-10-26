// Function: FUN_0058a973 @ 0058a973
// Size (bytes): 231


void FUN_0058a973(uint param_1)

{
  int iVar1;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005b8cd0;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  if (DAT_008d4908 == 3) {
    ExceptionList = &local_14;
    if (param_1 <= DAT_008d4900) {
      ExceptionList = &local_14;
      FUN_0058dfea(9);
      local_8 = 0;
      iVar1 = FUN_0059416f(param_1);
      local_8 = 0xffffffff;
      FUN_0058a9da();
      if (iVar1 != 0) {
        ExceptionList = local_14;
        return;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (DAT_008d4908 == 2) {
      if (param_1 == 0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = param_1 + 0xf & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_005e998c) {
        ExceptionList = &local_14;
        FUN_0058dfea(9);
        local_8 = 1;
        iVar1 = FUN_00594c12(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_0058aa39();
        if (iVar1 != 0) {
          ExceptionList = local_14;
          return;
        }
      }
      goto LAB_0058aa52;
    }
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  dwBytes = param_1 + 0xf & 0xfffffff0;
LAB_0058aa52:
  HeapAlloc(DAT_008d4904,0,dwBytes);
  ExceptionList = local_14;
  return;
}


