// Function: FUN_00554560 @ 00554560
// Size (bytes): 115


void __thiscall FUN_00554560(undefined4 *param_1,int param_2)

{
  if ((param_2 != -1) && (param_2 != param_1[0xd])) {
    if (param_2 == 0) {
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0x12,0);
    }
    else if (param_2 == 1) {
      if ((DAT_008b8c48 & 1) != 0) {
        (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0x12,2);
        param_1[0xd] = 1;
        return;
      }
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0x12,1);
      param_1[0xd] = 1;
      return;
    }
    param_1[0xd] = param_2;
  }
  return;
}


