// Function: FUN_0050a3ce @ 0050a3ce
// Size (bytes): 186


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050a3ce(int param_1,int param_2,int param_3,float *param_4)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  uint *puVar4;
  
  fVar3 = _DAT_005acf38;
  puVar4 = (uint *)(*(int *)(param_1 + 0x1050) * param_2 + *(int *)(param_1 + 0x1054) * param_3 +
                   *(int *)(param_1 + 0x18));
  puVar1 = puVar4 + *(int *)(param_1 + 0x1058);
  for (; puVar4 < puVar1; puVar4 = puVar4 + 1) {
    uVar2 = *puVar4;
    *param_4 = (float)(int)((short)((short)*puVar4 << 6) >> 6) * _DAT_0059e4d8;
    param_4[1] = (float)(int)((short)((short)(uVar2 >> 10) << 5) >> 5) * fVar3;
    param_4[2] = (float)(int)(short)((int)uVar2 >> 0x15) * fVar3;
    param_4[3] = 1.0;
    param_4 = param_4 + 4;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00507845(param_4 + *(int *)(param_1 + 0x1058) * -4);
  }
  return;
}


