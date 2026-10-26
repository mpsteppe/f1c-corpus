// Function: FUN_005830c0 @ 005830c0
// Size (bytes): 134


undefined4 * __fastcall FUN_005830c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059ce2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x207c);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 2;
    FUN_0058a6eb(puVar1 + 1,0x103c,2,FUN_00582110,FUN_0047aa60);
    *param_1 = puVar1 + 1;
    ExceptionList = local_c;
    return param_1;
  }
  *param_1 = 0;
  ExceptionList = local_c;
  return param_1;
}


