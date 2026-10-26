// Function: FUN_005456b0 @ 005456b0
// Size (bytes): 261


int __thiscall FUN_005456b0(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar2 = *(int *)(param_1 + 0x120);
  for (iVar5 = *(int *)(param_1 + 0x11c); iVar5 != 0; iVar5 = iVar5 + -1) {
    pbVar6 = (byte *)(iVar2 + 0x58);
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_005456f4:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_005456f9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_005456f4;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_005456f9:
    if (iVar4 == 0) {
      return iVar2;
    }
    iVar2 = *(int *)(iVar2 + 0x6c);
  }
  iVar2 = *(int *)(param_1 + 0x128);
  for (iVar5 = *(int *)(param_1 + 0x124); iVar5 != 0; iVar5 = iVar5 + -1) {
    pbVar6 = (byte *)(iVar2 + 0x58);
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_00545744:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_00545749;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_00545744;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00545749:
    if (iVar4 == 0) {
      return iVar2;
    }
    iVar2 = *(int *)(iVar2 + 0x6c);
  }
  iVar5 = *(int *)(param_1 + 300);
  iVar2 = *(int *)(param_1 + 0x130);
  do {
    if (iVar5 == 0) {
      return 0;
    }
    pbVar6 = (byte *)(iVar2 + 0x58);
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_00545794:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_00545799;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_00545794;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00545799:
    if (iVar4 == 0) {
      return iVar2;
    }
    iVar5 = iVar5 + -1;
    iVar2 = *(int *)(iVar2 + 0x6c);
  } while( true );
}


