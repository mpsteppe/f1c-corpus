// Function: FUN_0059b5c0 @ 0059b5c0
// Size (bytes): 132


undefined4 __thiscall FUN_0059b5c0(int *param_1,int param_2,int *param_3)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  FUN_0059b490(param_2);
  FUN_0059b530();
  *(short *)(param_1[2] + param_1[5] * 4) = (short)param_1[4];
  *(short *)(param_1[2] + 2 + param_1[5] * 4) = (short)param_2;
  uVar4 = (uint)*(ushort *)(param_1[2] + param_1[5] * 4);
  uVar1 = uVar4 + param_2;
  for (; uVar4 < uVar1; uVar4 = uVar4 + 1) {
    pbVar2 = (byte *)(*param_1 + (uVar4 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << ((byte)uVar4 & 7));
  }
  *param_3 = param_1[5];
  iVar3 = param_1[5];
  param_1[4] = param_1[4] + param_2;
  param_1[5] = iVar3 + 1;
  return CONCAT31((int3)((uint)(iVar3 + 1) >> 8),1);
}


