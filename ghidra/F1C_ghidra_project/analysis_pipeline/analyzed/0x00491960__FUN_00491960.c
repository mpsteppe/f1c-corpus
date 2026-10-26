// Function: FUN_00491960 @ 00491960
// Size (bytes): 81


undefined4 __thiscall
FUN_00491960(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  if ((0 < param_4) && (0 < param_5)) {
    FUN_00490ee0(*param_1 + 0x1c,param_2,param_3,param_4,param_5);
    FUN_00490ee0(*param_1 + 0x2c,param_2,param_3,param_4,param_5);
    return 1;
  }
  return 0;
}


