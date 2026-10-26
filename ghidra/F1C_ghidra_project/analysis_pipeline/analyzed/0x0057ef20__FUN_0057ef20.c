// Function: FUN_0057ef20 @ 0057ef20
// Size (bytes): 93


undefined4 FUN_0057ef20(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059ca1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x20);
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0057b780(0,0,0);
    ExceptionList = local_c;
    return uVar2;
  }
  ExceptionList = local_c;
  return 0;
}


