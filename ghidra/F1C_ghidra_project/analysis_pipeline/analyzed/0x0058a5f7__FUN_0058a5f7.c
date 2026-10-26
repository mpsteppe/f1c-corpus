// Function: FUN_0058a5f7 @ 0058a5f7
// Size (bytes): 104


void FUN_0058a5f7(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005b8c98;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)();
  }
  local_8 = 0xffffffff;
  FUN_0058a65f();
  ExceptionList = local_14;
  return;
}


