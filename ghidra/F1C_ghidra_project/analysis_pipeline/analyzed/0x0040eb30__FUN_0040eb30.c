// Function: FUN_0040eb30 @ 0040eb30
// Size (bytes): 151


void __thiscall FUN_0040eb30(int param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1c) = 3;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  local_20 = 0x66666666;
  local_1c = 0x3fe66666;
  local_18 = 0;
  local_14 = 0x3fe00000;
  local_10 = 0;
  local_c = 0x3fe00000;
  FUN_00459950(0,0x402e0000,&local_20);
  FUN_00459990(0,0x40b5f900,0,0x40468000,0,0x3ff00000);
  if (param_4 != 0) {
    FUN_0040e770(param_4,0);
  }
  return;
}


