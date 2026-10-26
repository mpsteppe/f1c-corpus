// Function: FUN_00464bb0 @ 00464bb0
// Size (bytes): 31


short __thiscall FUN_00464bb0(int param_1,float param_2,float param_3)

{
  byte bVar1;
  
  param_2 = param_2 + *(float *)(param_1 + 0x68);
  *(float *)(param_1 + 0x68) = param_2;
  bVar1 = param_2 < param_3 | (byte)((ushort)((ushort)(NAN(param_2) || NAN(param_3)) << 10) >> 8) |
          (byte)((ushort)((ushort)(param_2 == param_3) << 0xe) >> 8);
  if (param_2 >= param_3) {
    return CONCAT11(bVar1,1);
  }
  return (ushort)bVar1 << 8;
}


