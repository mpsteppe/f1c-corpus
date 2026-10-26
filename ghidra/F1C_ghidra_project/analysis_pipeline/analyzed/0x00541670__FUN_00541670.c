// Function: FUN_00541670 @ 00541670
// Size (bytes): 46


undefined4 __thiscall FUN_00541670(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1[0x4f6] != 0) {
    uVar1 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x8b,param_2);
    *param_1 = uVar1;
  }
  return 0;
}


