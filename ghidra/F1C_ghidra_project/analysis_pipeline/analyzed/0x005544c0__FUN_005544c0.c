// Function: FUN_005544c0 @ 005544c0
// Size (bytes): 68


void __thiscall FUN_005544c0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == -1) {
    return;
  }
  if (param_2 == param_1[0xe]) {
    return;
  }
  if (param_2 == 0) {
    uVar1 = 1;
  }
  else if (param_2 == 1) {
    uVar1 = 3;
  }
  else {
    if (param_2 != 2) goto LAB_005544fc;
    uVar1 = 2;
  }
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0xd,uVar1);
LAB_005544fc:
  param_1[0xe] = param_2;
  return;
}


