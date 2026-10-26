// Function: FUN_00500010 @ 00500010
// Size (bytes): 165


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00500010(float *param_1,undefined4 param_2,uint *param_3)

{
  float fVar1;
  char cVar2;
  float fVar3;
  
  fVar1 = (float)param_3[1];
  fVar3 = (float)(*(byte *)((int)param_3 + 3) & 7);
  if ((fVar1 <= *param_1) && (*param_1 - _DAT_005ad358 <= fVar1)) {
    cVar2 = FUN_005001f0();
    if ((cVar2 != '\0') && (fVar3 == param_1[1])) {
      return 0;
    }
  }
  *param_1 = fVar1;
  param_1[1] = fVar3;
  if ((*param_3 & 0xfc0000) == 0) {
    FUN_004b3a90(param_3);
    return 1;
  }
  cVar2 = FUN_005001f0();
  if (cVar2 != '\0') {
    FUN_004b2dd0(param_1 + 2,param_3[1]);
    return 1;
  }
  FUN_004b32a0(param_1 + 2,param_3[1]);
  return 1;
}


