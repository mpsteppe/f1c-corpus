// Function: FUN_005867b0 @ 005867b0
// Size (bytes): 77


void FUN_005867b0(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059d19b;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0059b390();
  local_4 = 0xffffffff;
  FUN_00499ae0();
  ExceptionList = local_c;
  return;
}


