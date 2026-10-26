// Function: FUN_0040e8f0 @ 0040e8f0
// Size (bytes): 157


void __thiscall FUN_0040e8f0(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  local_20 = 0;
  local_1c = 0x3fd00000;
  local_18 = 0x9999999a;
  local_14 = 0x3fc99999;
  local_10 = 0;
  local_c = 0x3fd00000;
  FUN_00459950(0,0x40040000,&local_20);
  FUN_00459990(0x66666667,0x40964666,0,0x40520000,0xa0000000,0x3fe99999);
  if (param_4 != 0) {
    FUN_0040e770(param_4,0);
  }
  return;
}


