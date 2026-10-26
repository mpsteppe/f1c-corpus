// Function: FUN_004915a0 @ 004915a0
// Size (bytes): 83


uint __thiscall FUN_004915a0(short *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = (int)*param_1;
  if (((int)param_2 <= iVar1) && (param_4 = param_2 + param_4, iVar1 < param_4)) {
    param_2 = (uint)param_1[1];
    if ((param_3 <= (int)param_2) &&
       ((((int)param_2 < param_3 + param_5 && (param_1[2] + iVar1 <= param_4)) &&
        ((int)((int)param_1[3] + param_2) <= param_3 + param_5)))) {
      return CONCAT31((int3)(char)((ushort)param_1[1] >> 8),1);
    }
  }
  return param_2 & 0xffffff00;
}


