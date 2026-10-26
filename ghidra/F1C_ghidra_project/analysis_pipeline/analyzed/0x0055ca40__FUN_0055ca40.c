// Function: FUN_0055ca40 @ 0055ca40
// Size (bytes): 67


void __thiscall FUN_0055ca40(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 0x100;
  }
  else if (param_2 == 2) {
    uVar1 = 2;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar1 = 3;
  }
  uVar1 = (**(code **)(*(int *)param_1[0x440] + 0x94))((int *)param_1[0x440],uVar1,param_3);
  *param_1 = uVar1;
  return;
}


