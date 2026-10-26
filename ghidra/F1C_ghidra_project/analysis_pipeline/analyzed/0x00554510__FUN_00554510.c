// Function: FUN_00554510 @ 00554510
// Size (bytes): 68


void __thiscall FUN_00554510(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == -1) {
    return;
  }
  if (param_2 == param_1[0xf]) {
    return;
  }
  if (param_2 == 0) {
    uVar1 = 1;
  }
  else if (param_2 == 1) {
    uVar1 = 3;
  }
  else {
    if (param_2 != 2) goto LAB_0055454c;
    uVar1 = 2;
  }
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0xe,uVar1);
LAB_0055454c:
  param_1[0xf] = param_2;
  return;
}


