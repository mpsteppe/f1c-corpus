// Function: FUN_00593cfd @ 00593cfd
// Size (bytes): 79


void FUN_00593cfd(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005b99a0;
  puStack_10 = &LAB_0058895c;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_005e7960 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_005e7960)();
  }
  local_8 = 0xffffffff;
  FUN_00593c9c();
  return;
}


