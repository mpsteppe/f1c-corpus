// Function: FUN_0058aa6f @ 0058aa6f
// Size (bytes): 215


void FUN_0058aa6f(LPVOID param_1)

{
  int iVar1;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005b8ce8;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  if (param_1 == (LPVOID)0x0) {
    return;
  }
  if (DAT_008d4908 == 3) {
    ExceptionList = &local_14;
    FUN_0058dfea(9);
    local_8 = 0;
    local_20 = FUN_00593e1b(param_1);
    if (local_20 != 0) {
      FUN_00593e46(local_20,param_1);
    }
    local_8 = 0xffffffff;
    FUN_0058aad9();
    iVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_008d4908 != 2) goto LAB_0058ab3b;
    ExceptionList = &local_14;
    FUN_0058dfea(9);
    local_8 = 1;
    local_28 = FUN_00594b76(param_1,&local_2c,&local_24);
    if (local_28 != 0) {
      FUN_00594bcd(local_2c,local_24,local_28);
    }
    local_8 = 0xffffffff;
    FUN_0058ab31();
    iVar1 = local_28;
  }
  if (iVar1 != 0) {
    ExceptionList = local_14;
    return;
  }
LAB_0058ab3b:
  HeapFree(DAT_008d4904,0,param_1);
  ExceptionList = local_14;
  return;
}


