// Function: FUN_00544f50 @ 00544f50
// Size (bytes): 193


int __thiscall FUN_00544f50(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar2 = *(int *)(param_1 + 0xf8);
  do {
    if (iVar2 == 0) {
      return 0;
    }
    pbVar3 = (byte *)(iVar2 + 0x8c);
    pbVar5 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_00544f98:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_00544f9d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_00544f98;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00544f9d:
    if (iVar4 == 0) {
      return iVar2;
    }
    if (*(int *)(iVar2 + 0x1b0) != 0) {
      pbVar5 = (byte *)(*(int *)(iVar2 + 0x1b0) + 0x8c);
      pbVar3 = param_2;
      do {
        bVar1 = *pbVar5;
        bVar6 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_00544fdb:
          iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_00544fe0;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar6 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_00544fdb;
        pbVar5 = pbVar5 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_00544fe0:
      if (iVar4 == 0) {
        return *(int *)(iVar2 + 0x1b0);
      }
    }
    iVar2 = *(int *)(iVar2 + 0x1b8);
  } while( true );
}


