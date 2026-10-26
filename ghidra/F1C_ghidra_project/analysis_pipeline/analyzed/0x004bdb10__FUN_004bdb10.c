// Function: FUN_004bdb10 @ 004bdb10
// Size (bytes): 128


void __thiscall
FUN_004bdb10(int param_1,int param_2,undefined4 param_3,float *param_4,float param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x1c)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + iVar6 * 4);
      fVar2 = *param_4 - *(float *)(iVar1 + 0xc);
      fVar5 = param_4[1] - *(float *)(iVar1 + 0x10);
      fVar4 = param_4[2] - *(float *)(iVar1 + 0x14);
      fVar3 = *(float *)(iVar1 + 0x18) + param_5;
      if ((fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4 <= fVar3 * fVar3) &&
         (*(int *)(iVar1 + 4) != param_2)) {
        *(int *)(iVar1 + 4) = param_2;
        FUN_0054f7a0(*(undefined4 *)(iVar1 + 0x20),1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 0x1c));
  }
  return;
}


