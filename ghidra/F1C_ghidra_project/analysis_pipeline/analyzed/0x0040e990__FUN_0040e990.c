// Function: FUN_0040e990 @ 0040e990
// Size (bytes): 157


void __thiscall FUN_0040e990(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  local_20 = 0;
  local_1c = 0x3fe00000;
  local_18 = 0x9999999a;
  local_14 = 0x3fb99999;
  local_10 = 0;
  local_c = 0x3fe00000;
  FUN_00459950(0x33333333,0x3ff33333,&local_20);
  FUN_00459990(0,0x40790000,0,0x40440000,0xa0000000,0x3fe99999);
  if (param_4 != 0) {
    FUN_0040e770(param_4,0);
  }
  return;
}


