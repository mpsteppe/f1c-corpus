// Function: FUN_00585380 @ 00585380
// Size (bytes): 39


undefined4 __thiscall FUN_00585380(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_2 != 0) {
    FUN_00584c70(param_2);
    uVar1 = 0;
  }
  (**(code **)(*param_1 + 0x38))();
  return uVar1;
}


