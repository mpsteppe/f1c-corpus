// Function: FUN_0054bc60 @ 0054bc60
// Size (bytes): 109


void __thiscall FUN_0054bc60(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_0054bc60(param_2,param_3);
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_0054bc60(param_2,param_3);
  }
  pbVar2 = param_1;
  if (*param_3 == 0) {
    do {
      bVar1 = *pbVar2;
      bVar4 = bVar1 < *param_2;
      if (bVar1 != *param_2) {
LAB_0054bcba:
        iVar3 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
        goto LAB_0054bcbf;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar4 = bVar1 < param_2[1];
      if (bVar1 != param_2[1]) goto LAB_0054bcba;
      param_2 = param_2 + 2;
      pbVar2 = pbVar2 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0054bcbf:
    if (iVar3 == 0) {
      *param_3 = (int)param_1;
    }
  }
  return;
}


