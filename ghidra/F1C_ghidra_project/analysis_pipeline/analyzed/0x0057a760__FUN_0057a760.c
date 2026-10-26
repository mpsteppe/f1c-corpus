// Function: FUN_0057a760 @ 0057a760
// Size (bytes): 156


undefined4 FUN_0057a760(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 local_64;
  undefined1 local_60 [4];
  undefined4 local_5c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c778;
  local_c = ExceptionList;
  uVar2 = 0xb;
  ExceptionList = &local_c;
  FUN_00586700();
  local_4 = 0;
  cVar1 = FUN_005853b0(local_60);
  if (cVar1 != '\0') {
    local_64 = 0;
    FUN_00586a10(param_1,*param_2,&local_64);
    *param_3 = local_5c;
    *param_2 = local_64;
    uVar2 = 0;
  }
  local_4 = 0xffffffff;
  FUN_005867b0();
  ExceptionList = local_c;
  return uVar2;
}


