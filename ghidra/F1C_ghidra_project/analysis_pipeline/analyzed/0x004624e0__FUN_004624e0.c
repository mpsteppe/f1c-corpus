// Function: FUN_004624e0 @ 004624e0
// Size (bytes): 80


int FUN_004624e0(float param_1,float param_2)

{
  undefined2 extraout_var;
  uint3 uVar1;
  
  if (param_2 < DAT_0059e440) {
    param_2 = DAT_007d108c;
  }
  FUN_0045ca20(param_1,&param_1,0);
  param_1 = ABS(param_1);
  uVar1 = (uint3)(CONCAT22(extraout_var,
                           (ushort)(param_2 < param_1) << 8 |
                           (ushort)(NAN(param_2) || NAN(param_1)) << 10 |
                           (ushort)(param_2 == param_1) << 0xe) >> 8);
  if (param_2 < param_1) {
    return CONCAT31(uVar1,1);
  }
  return (uint)uVar1 << 8;
}


