// Function: FUN_004bda20 @ 004bda20
// Size (bytes): 230


void __thiscall FUN_004bda20(int param_1,int param_2,int param_3,float *param_4,float param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 8) + iVar6 * 4);
      fVar2 = *param_4 - *(float *)(iVar1 + 0xc);
      fVar5 = param_4[1] - *(float *)(iVar1 + 0x10);
      fVar4 = param_4[2] - *(float *)(iVar1 + 0x14);
      fVar3 = *(float *)(iVar1 + 0x18) + param_5;
      if (((fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4 <= fVar3 * fVar3) &&
          (param_3 != *(int *)(iVar1 + 0x20))) && (*(int *)(iVar1 + 4) != param_2)) {
        *(int *)(iVar1 + 4) = param_2;
        FUN_0040f380(param_3);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 4));
  }
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4);
      fVar2 = *param_4 - *(float *)(iVar1 + 0xc);
      fVar5 = param_4[1] - *(float *)(iVar1 + 0x10);
      fVar4 = param_4[2] - *(float *)(iVar1 + 0x14);
      fVar3 = *(float *)(iVar1 + 0x18) + param_5;
      if ((fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4 <= fVar3 * fVar3) &&
         (*(int *)(iVar1 + 4) != param_2)) {
        *(int *)(iVar1 + 4) = param_2;
        FUN_0040f380(param_3);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x10));
  }
  return;
}


