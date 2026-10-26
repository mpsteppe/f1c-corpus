// Function: FUN_0058ac95 @ 0058ac95
// Size (bytes): 81


undefined4 FUN_0058ac95(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  uVar1 = FUN_0058d04d(&local_24,param_2,param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_0058cf35(0,&local_24);
  }
  else {
    *local_24 = 0;
  }
  return uVar1;
}


