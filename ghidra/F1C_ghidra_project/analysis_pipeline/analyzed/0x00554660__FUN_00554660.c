// Function: FUN_00554660 @ 00554660
// Size (bytes): 49


void __thiscall FUN_00554660(undefined4 *param_1,float param_2)

{
  if (param_2 != (float)param_1[0x10]) {
    param_1[0x10] = param_2;
    (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0x13,param_1[0x10]);
  }
  return;
}


