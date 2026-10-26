// Function: FUN_00565bb0 @ 00565bb0
// Size (bytes): 225


bool __thiscall FUN_00565bb0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  LONG LVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar2 = *(int *)(*param_1 + 0x220);
  if (iVar2 == 1) {
    pbVar3 = (byte *)(param_2 + 0x30);
    pbVar5 = (byte *)(param_1 + 0xc);
    while( true ) {
      bVar1 = *pbVar5;
      bVar6 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) break;
      if (bVar1 == 0) {
        return false;
      }
      bVar1 = pbVar5[1];
      bVar6 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) break;
      pbVar5 = pbVar5 + 2;
      pbVar3 = pbVar3 + 2;
      if (bVar1 == 0) {
        return false;
      }
    }
    return 0 < (int)((1 - (uint)bVar6) - (uint)(bVar6 != 0));
  }
  if (iVar2 == 2) {
    LVar4 = CompareFileTime((FILETIME *)(param_1 + 6),(FILETIME *)(param_2 + 0x18));
    return 0 < LVar4;
  }
  if (iVar2 == 3) {
    LVar4 = CompareFileTime((FILETIME *)(param_1 + 6),(FILETIME *)(param_2 + 0x18));
    return LVar4 < 0;
  }
  pbVar3 = (byte *)(param_1 + 0xc);
  pbVar5 = (byte *)(param_2 + 0x30);
  while( true ) {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) break;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)((1 - (uint)bVar6) - (uint)(bVar6 != 0)) < 0;
}


