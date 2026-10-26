// Function: FUN_005545e0 @ 005545e0
// Size (bytes): 46


void __thiscall FUN_005545e0(undefined4 *param_1,int param_2)

{
  if ((param_2 != -1) && (param_2 != param_1[0xb])) {
    (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0xb,param_2);
    param_1[0xb] = param_2;
  }
  return;
}


