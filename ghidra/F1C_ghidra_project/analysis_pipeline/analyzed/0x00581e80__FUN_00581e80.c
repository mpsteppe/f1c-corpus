// Function: FUN_00581e80 @ 00581e80
// Size (bytes): 84


undefined4 * __fastcall FUN_00581e80(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cbc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0057a160();
  local_4 = 0;
  *param_1 = &PTR_FUN_005b8b3c;
  *(undefined2 *)(param_1 + 0x4b) = 0;
  param_1[0x4c] = 0;
  FUN_0057a1e0();
  ExceptionList = local_c;
  return param_1;
}


