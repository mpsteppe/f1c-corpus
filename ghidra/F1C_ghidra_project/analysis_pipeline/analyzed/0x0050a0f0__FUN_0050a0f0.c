// Function: FUN_0050a0f0 @ 0050a0f0
// Size (bytes): 130


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050a0f0(int param_1,int param_2,int param_3,float *param_4)

{
  char *pcVar1;
  float fVar2;
  char *pcVar3;
  
  fVar2 = _DAT_0059e774;
  pcVar3 = (char *)(*(int *)(param_1 + 0x1050) * param_2 + *(int *)(param_1 + 0x1054) * param_3 +
                   *(int *)(param_1 + 0x18));
  pcVar1 = pcVar3 + *(int *)(param_1 + 0x1058) * 2;
  for (; pcVar3 < pcVar1; pcVar3 = pcVar3 + 2) {
    *param_4 = (float)(int)*pcVar3 * fVar2;
    param_4[1] = (float)(int)pcVar3[1] * fVar2;
    param_4[2] = 0.0;
    param_4[3] = 1.0;
    param_4 = param_4 + 4;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00507845(param_4 + *(int *)(param_1 + 0x1058) * -4);
  }
  return;
}


