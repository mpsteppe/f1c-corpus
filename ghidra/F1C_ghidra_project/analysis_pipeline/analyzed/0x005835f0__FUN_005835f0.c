// Function: FUN_005835f0 @ 005835f0
// Size (bytes): 85


undefined4 __fastcall FUN_005835f0(undefined4 param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059ce4b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00568ba0();
  local_4 = 0;
  FUN_00568be0(1);
  FUN_00583660(0);
  ExceptionList = local_c;
  return param_1;
}


