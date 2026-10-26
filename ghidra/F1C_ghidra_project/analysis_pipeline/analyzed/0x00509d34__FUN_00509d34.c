// Function: FUN_00509d34 @ 00509d34
// Size (bytes): 178


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00509d34(int param_1,int param_2,int param_3,float *param_4)

{
  byte *pbVar1;
  float fVar2;
  byte *pbVar3;
  
  fVar2 = _DAT_005ad210;
  pbVar3 = (byte *)(*(int *)(param_1 + 0x1050) * param_2 + *(int *)(param_1 + 0x1054) * param_3 +
                   *(int *)(param_1 + 0x18));
  pbVar1 = pbVar3 + *(int *)(param_1 + 0x1058) * 2;
  for (; pbVar3 < pbVar1; pbVar3 = pbVar3 + 2) {
    *param_4 = (float)(*pbVar3 >> 5) * fVar2;
    param_4[1] = (float)(*pbVar3 >> 2 & 7) * fVar2;
    param_4[2] = (float)(*pbVar3 & 3) * _DAT_0059e98c;
    param_4[3] = (float)pbVar3[1] * _DAT_0059e460;
    param_4 = param_4 + 4;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00507845(param_4 + *(int *)(param_1 + 0x1058) * -4);
  }
  return;
}


