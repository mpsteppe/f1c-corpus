// Function: FUN_004c8f10 @ 004c8f10
// Size (bytes): 98


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_004c8f10(undefined4 *param_1,float param_2)

{
  float fVar1;
  uint uVar2;
  
  fVar1 = DAT_0059e440;
  *param_1 = &PTR_LAB_005ace2c;
  param_1[1] = 0;
  if (param_2 <= fVar1) {
    param_1[5] = 0x3f800000;
  }
  else {
    param_1[5] = param_2;
  }
  uVar2 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  param_1[6] = *(float *)(&DAT_008aae74 + uVar2 * 4) * _DAT_0059e8a4 + (float)param_1[5];
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}


