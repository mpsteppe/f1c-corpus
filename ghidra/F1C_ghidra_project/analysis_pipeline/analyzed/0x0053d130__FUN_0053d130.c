// Function: FUN_0053d130 @ 0053d130
// Size (bytes): 145


void FUN_0053d130(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  bool bVar6;
  
  if (DAT_008b8e20 == 0) {
    return;
  }
  iVar5 = DAT_008b8e20;
  do {
    pbVar2 = (byte *)(iVar5 + 0x14);
    pbVar4 = (byte *)(param_1 + 0x14);
    do {
      bVar1 = *pbVar2;
      bVar6 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0053d179:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0053d17e;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar6 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0053d179;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0053d17e:
    if (iVar3 == 0) {
      FUN_0053d3a0(param_1);
      FUN_00552760();
      if (param_1 == 0) {
        return;
      }
      FUN_00557470();
      FUN_00587bcf(param_1);
      return;
    }
    iVar5 = *(int *)(iVar5 + 0x870);
    if (iVar5 == 0) {
      return;
    }
  } while( true );
}


