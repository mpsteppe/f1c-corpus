// Function: FUN_004144f0 @ 004144f0
// Size (bytes): 202


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004144f0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,float param_8)

{
  float fVar1;
  int iVar2;
  
  param_1[4] = param_3;
  param_1[6] = param_5;
  *param_1 = param_2;
  param_1[5] = param_4;
  param_1[7] = param_6;
  if (param_6 == -1) {
    param_1[7] = *(int *)(&DAT_005bf9a0 + param_2 * 0x14);
  }
  if (param_8 == _DAT_0059e7f0) {
    param_8 = *(float *)(&DAT_005bf9a4 + param_2 * 0x14);
  }
  iVar2 = __ftol();
  fVar1 = (float)iVar2 * _DAT_0059e7e8;
  param_1[2] = (int)fVar1;
  if (param_8 == _DAT_0059e670) {
    param_1[3] = -0x40800000;
    return;
  }
  param_1[3] = (int)(fVar1 + param_8 + _DAT_0059e7e8);
  return;
}


