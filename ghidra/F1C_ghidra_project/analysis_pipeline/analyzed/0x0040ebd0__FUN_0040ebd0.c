// Function: FUN_0040ebd0 @ 0040ebd0
// Size (bytes): 154


void __thiscall FUN_0040ebd0(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = 4;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  local_20 = 0;
  local_1c = 0x3ff00000;
  local_18 = 0;
  local_14 = 0x3fe00000;
  local_10 = 0;
  local_c = 0x3ff80000;
  FUN_00459950(0,0x40240000,&local_20);
  FUN_00459990(0,0x40ac2000,0,0x404e0000,0x40000000,0x3fe33333);
  if (param_4 != 0) {
    FUN_0040e770(param_4,0);
  }
  return;
}


