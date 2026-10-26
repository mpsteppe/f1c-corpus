// Function: FUN_00586700 @ 00586700
// Size (bytes): 162


int __fastcall FUN_00586700(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d186;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00587460(0);
  local_4 = 0;
  FUN_0059b2f0(8,1,0x10,8);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0059b5c0(1,param_1 + 0x34);
  FUN_0059b5c0(8,param_1 + 0x38);
  FUN_0059b5c0(1,param_1 + 0x3c);
  FUN_0059b5c0(2,param_1 + 0x40);
  FUN_0059b5c0(0x10,param_1 + 0x44);
  FUN_00586aa0();
  ExceptionList = local_c;
  return param_1;
}


